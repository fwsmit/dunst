void load_settings(char *cmdline_config_path)
{

#ifndef STATIC_CONFIG
        FILE *config_file = NULL;

        if (cmdline_config_path) {
                if (STR_EQ(cmdline_config_path, "-")) {
                        config_file = stdin;
                } else {
                        config_file = fopen(cmdline_config_path, "r");
                }

                if (!config_file) {
                        DIE("Cannot find config file: '%s'", cmdline_config_path);
                }
        }

        if (!config_file) {
                config_file = xdg_config("/dunst/dunstrc");
        }

        if (!config_file) {
                /* Fall back to just "dunstrc", which was used before 2013-06-23
                 * (before v0.2). */
                config_file = xdg_config("/dunstrc");
        }

        if (!config_file) {
                LOG_W("No dunstrc found.");
        }

        load_ini_file(config_file);
#else
        LOG_M("dunstrc parsing disabled. "
              "Using STATIC_CONFIG is deprecated behavior.");
#endif

        {
                char *loglevel = option_get_string(
                                "global",
                                "verbosity", "-verbosity", NULL,
                                "The verbosity to log (one of 'crit', 'warn', 'mesg', 'info', 'debug')"
                        );

                log_set_level_from_string(loglevel);

                g_free(loglevel);
        }





        {
                // Check if allow_markup set
                if (ini_is_set("global", "allow_markup")) {
                        bool allow_markup = option_get_bool(
                                "global",
                                "allow_markup", NULL, false,
                                "Allow markup in notifications"
                        );

                        settings.markup = (allow_markup ? MARKUP_FULL : MARKUP_STRIP);
                        LOG_M("'allow_markup' is deprecated, please "
                              "use 'markup' instead.");
                }

                char *c = option_get_string(
                        "global",
                        "markup", "-markup", NULL,
                        "Specify how markup should be handled"
                );

                if (!string_parse_markup_mode(c, &settings.markup)) {
                        if (c)
                                LOG_W("Cannot parse markup mode value: '%s'", c);
                        if (!settings.markup)
                                settings.markup = defaults.markup;
                }
                g_free(c);
        }





        {
                char *c = option_get_string(
                        "global",
                        "ellipsize", "-ellipsize", NULL,
                        "Ellipsize truncated lines on the start/middle/end"
                );

                if (!string_parse_ellipsize(c, &settings.ellipsize)) {
                        if (c)
                                LOG_W("Unknown ellipsize value: '%s'", c);
                        settings.ellipsize = defaults.ellipsize;
                }
                g_free(c);
        }



#ifndef ENABLE_WAYLAND
        if (is_running_wayland()){
                /* We are using xwayland now. Setting force_xwayland to make sure
                 * the idle workaround below is activated */
                settings.force_xwayland = true;
        }
#endif

        if (settings.force_xwayland && is_running_wayland()) {
                if (settings.idle_threshold > 0)
                        LOG_W("Using xwayland. Disabling idle.");
                /* There is no way to detect if the user is idle
                 * on xwayland, so turn this feature off */
                settings.idle_threshold = 0;
        }


        {
                char *c = option_get_string(
                        "global",
                        "follow", "-follow", NULL,
                        "Follow mouse, keyboard or none?"
                );

                if (!string_parse_follow_mode(c, &settings.f_mode)) {
                        if (c)
                                LOG_W("Cannot parse follow mode: %s", c);
                        settings.f_mode = defaults.f_mode;
                }
                g_free(c);
        }



        {

                char *c = option_get_string(
                        "global",
                        "geometry", "-geom/-geometry", NULL,
                        "Geometry for the window"
                );

                if (c) {
                        // TODO: Implement own geometry parsing to get rid of
                        //       the include dependency on X11
                        settings.geometry = x_parse_geometry(c);
                        g_free(c);
                } else {
                        settings.geometry = defaults.geometry;
                }

        }




        {
                char *c = option_get_string(
                        "global",
                        "alignment", "-align/-alignment", NULL,
                        "Text alignment left/center/right"
                );

                if (!string_parse_alignment(c, &settings.align)) {
                        if (c)
                                LOG_W("Unknown alignment value: '%s'", c);
                        settings.align = defaults.align;
                }

                g_free(c);
        }

















        // check sanity of the progress bar options
        {
                if (settings.progress_bar_height < (2 * settings.progress_bar_frame_width)){
                        LOG_E("setting progress_bar_frame_width is bigger than half of progress_bar_height");
                }
                if (settings.progress_bar_max_width < (2 * settings.progress_bar_frame_width)){
                        LOG_E("setting progress_bar_frame_width is bigger than half of progress_bar_max_width");
                }
                if (settings.progress_bar_max_width < settings.progress_bar_min_width){
                        LOG_E("setting progress_bar_max_width is smaller than progress_bar_min_width");
                }
        }

        {
                char *c = option_get_string(
                        "global",
                        "separator_color", "-sep_color/-separator_color", "",
                        "Color of the separator line (or 'auto')"
                );

                if (!string_parse_sepcolor(c, &settings.sep_color)) {
                        settings.sep_color = defaults.sep_color;
                }
                g_free(c);
        }




        {
                GError *error = NULL;
                if (!g_shell_parse_argv(settings.dmenu, NULL, &settings.dmenu_cmd, &error)) {
                        LOG_W("Unable to parse dmenu command: '%s'."
                              "dmenu functionality will be disabled.", error->message);
                        g_error_free(error);
                        settings.dmenu_cmd = NULL;
                }
        }



        {
                GError *error = NULL;
                if (!g_shell_parse_argv(settings.browser, NULL, &settings.browser_cmd, &error)) {
                        LOG_W("Unable to parse browser command: '%s'."
                              " URL functionality will be disabled.", error->message);
                        g_error_free(error);
                        settings.browser_cmd = NULL;
                }
        }

        {
                char *c = option_get_string(
                        "global",
                        "icon_position", "-icon_position", "left",
                        "Align icons left/right/off"
                );

                if (!string_parse_icon_position(c, &settings.icon_position)) {
                        if (c)
                                LOG_W("Unknown icon position: '%s'", c);
                        settings.icon_position = defaults.icon_position;
                }
                g_free(c);
        }

        {
                char *c = option_get_string(
                        "global",
                        "vertical_alignment", "-vertical_alignment", "center",
                        "Align icon and text top/center/bottom"
                );
                if (!string_parse_vertical_alignment(c, &settings.vertical_alignment)) {
                        if (c)
                                LOG_W("Unknown vertical alignment: '%s'", c);
                        settings.vertical_alignment = defaults.vertical_alignment;
                }
                g_free(c);

        }

        {
                char *c = option_get_string(
                        "global",
                        "layer", "-layer", "overlay",
                        "Select the layer where notifications should be placed"
                );

                if (!string_parse_layer(c, &settings.layer)) {
                        if (c)
                                LOG_W("Unknown layer: '%s'", c);
                        settings.layer = defaults.layer;
                }
                g_free(c);

        }



        // restrict the icon size to a reasonable limit if we have a fixed width.
        // Otherwise the layout will be broken by too large icons.
        // See https://github.com/dunst-project/dunst/issues/540
        if (settings.geometry.width_set && settings.geometry.w != 0) {
                const int icon_size_limit = settings.geometry.w / 2;
                if (   settings.max_icon_size == 0
                    || settings.max_icon_size > icon_size_limit) {
                        if (settings.max_icon_size != 0) {
                                LOG_W("Max width was set to %d but got a max_icon_size of %d, too large to use. Setting max_icon_size=%d",
                                        settings.geometry.w, settings.max_icon_size, icon_size_limit);
                        } else {
                                LOG_I("Max width was set but max_icon_size is unlimited. Limiting icons to %d pixels", icon_size_limit);
                        }

                        settings.max_icon_size = icon_size_limit;
                }
        }

        // If the deprecated icon_folders option is used,
        // read it and generate its usage string.
        if (ini_is_set("global", "icon_folders") || cmdline_is_set("-icon_folders")) {

        {
                // Backwards compatibility with the legacy 'frame' section.
                if (ini_is_set("frame", "width")) {






















        settings.print_notifications = cmdline_get_bool(
                "-print", false,
                "Print notifications to cmdline (DEBUG)"
        );
