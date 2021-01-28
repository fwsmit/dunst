{
        .name = "per_monitor_dpi",
        .section = "experimental",
        .description = "",
        .type = TYPE_BOOLEAN,
        .default_value = false,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "force_xinerama",
        .section = "global",
        .description = "Force the use of the Xinerama extension",
        .type = TYPE_BOOLEAN,
        .default_value = false,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "force_xwayland",
        .section = "global",
        .description = "Force the use of the xwayland output",
        .type = TYPE_BOOLEAN,
        .default_value = false,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "font",
        .section = "global",
        .description = "The font dunst should use.",
        .type = TYPE_STRING,
        .default_value = defaults.font,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "format",
        .section = "global",
        .description = "The format template for the notifications",
        .type = TYPE_STRING,
        .default_value = defaults.format,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "sort",
        .section = "global",
        .description = "Sort notifications by urgency and date?",
        .type = TYPE_BOOLEAN,
        .default_value = defaults.sort,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "indicate_hidden",
        .section = "global",
        .description = "Show how many notifications are hidden",
        .type = TYPE_BOOLEAN,
        .default_value = defaults.indicate_hidden,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "word_wrap",
        .section = "global",
        .description = "Truncating long lines or do word wrap",
        .type = TYPE_BOOLEAN,
        .default_value = defaults.word_wrap,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "ignore_dbusclose",
        .section = "global",
        .description = "Ignore dbus CloseNotification events",
        .type = TYPE_BOOLEAN,
        .default_value = defaults.ignore_dbusclose,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "ignore_newline",
        .section = "global",
        .description = "Ignore newline characters in notifications",
        .type = TYPE_BOOLEAN,
        .default_value = defaults.ignore_newline,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "idle_threshold",
        .section = "global",
        .description = "Don't timeout notifications if user is longer idle than threshold",
        .type = TYPE_TIME,
        .default_value = defaults.idle_threshold,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "monitor",
        .section = "global",
        .description = "On which monitor should the notifications be displayed",
        .type = TYPE_INT,
        .default_value = defaults.monitor,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "title",
        .section = "global",
        .description = "Define the title of windows spawned by dunst.",
        .type = TYPE_STRING,
        .default_value = defaults.title,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "class",
        .section = "global",
        .description = "Define the class of windows spawned by dunst.",
        .type = TYPE_STRING,
        .default_value = defaults.class,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "shrink",
        .section = "global",
        .description = "Shrink window if it's smaller than the width",
        .type = TYPE_BOOLEAN,
        .default_value = defaults.shrink,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "line_height",
        .section = "global",
        .description = "Add spacing between lines of text",
        .type = TYPE_INT,
        .default_value = defaults.line_height,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "notification_height",
        .section = "global",
        .description = "Define height of the window",
        .type = TYPE_INT,
        .default_value = defaults.notification_height,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "show_age_threshold",
        .section = "global",
        .description = "When should the age of the notification be displayed?",
        .type = TYPE_TIME,
        .default_value = defaults.show_age_threshold,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "hide_duplicate_count",
        .section = "global",
        .description = "Hide the count of stacked notifications with the same content",
        .type = TYPE_BOOLEAN,
        .default_value = false,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "sticky_history",
        .section = "global",
        .description = "Don't timeout notifications popped up from history",
        .type = TYPE_BOOLEAN,
        .default_value = defaults.sticky_history,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "history_length",
        .section = "global",
        .description = "Max amount of notifications kept in history",
        .type = TYPE_INT,
        .default_value = defaults.history_length,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "show_indicators",
        .section = "global",
        .description = "Show indicators for actions \"(A)\" and URLs \"(U)\"",
        .type = TYPE_BOOLEAN,
        .default_value = defaults.show_indicators,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "separator_height",
        .section = "global",
        .description = "height of the separator line",
        .type = TYPE_INT,
        .default_value = defaults.separator_height,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "padding",
        .section = "global",
        .description = "Padding between text and separator",
        .type = TYPE_INT,
        .default_value = defaults.padding,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "horizontal_padding",
        .section = "global",
        .description = "horizontal padding",
        .type = TYPE_INT,
        .default_value = defaults.h_padding,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "text_icon_padding",
        .section = "global",
        .description = "Padding between text and icon",
        .type = TYPE_INT,
        .default_value = defaults.text_icon_padding,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "transparency",
        .section = "global",
        .description = "Transparency. Range 0-100",
        .type = TYPE_INT,
        .default_value = defaults.transparency,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "corner_radius",
        .section = "global",
        .description = "Window corner radius",
        .type = TYPE_INT,
        .default_value = defaults.corner_radius,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "progress_bar_height",
        .section = "global",
        .description = "Height of the progress bar",
        .type = TYPE_INT,
        .default_value = defaults.progress_bar_height,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "progress_bar_min_width",
        .section = "global",
        .description = "Minimum width of the progress bar",
        .type = TYPE_INT,
        .default_value = defaults.progress_bar_min_width,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "progress_bar_max_width",
        .section = "global",
        .description = "Maximum width of the progress bar",
        .type = TYPE_INT,
        .default_value = defaults.progress_bar_max_width,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "progress_bar_frame_width",
        .section = "global",
        .description = "Frame width of the progress bar",
        .type = TYPE_INT,
        .default_value = defaults.progress_bar_frame_width,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "progress_bar",
        .section = "global",
        .description = "Show the progress bar",
        .type = TYPE_BOOLEAN,
        .default_value = true,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "stack_duplicates",
        .section = "global",
        .description = "Stack together notifications with the same content",
        .type = TYPE_BOOLEAN,
        .default_value = true,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "startup_notification",
        .section = "global",
        .description = "print notification on startup",
        .type = TYPE_BOOLEAN,
        .default_value = false,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "dmenu",
        .section = "global",
        .description = "path to dmenu",
        .type = TYPE_PATH,
        .default_value = defaults.dmenu,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "browser",
        .section = "global",
        .description = "path to browser",
        .type = TYPE_PATH,
        .default_value = defaults.browser,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "min_icon_size",
        .section = "global",
        .description = "Scale smaller icons up to this size, set to 0 to disable. If max_icon_size also specified, that has the final say.",
        .type = TYPE_INT,
        .default_value = defaults.min_icon_size,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "max_icon_size",
        .section = "global",
        .description = "Scale larger icons down to this size, set to 0 to disable",
        .type = TYPE_INT,
        .default_value = defaults.max_icon_size,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "foreground",
        .section = "urgency_low",
        .description = "Foreground color for notifications with low urgency",
        .type = TYPE_STRING,
        .default_value = defaults.colors_low.fg,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "highlight",
        .section = "urgency_low",
        .description = "Highlight color for notifications with low urgency",
        .type = TYPE_STRING,
        .default_value = defaults.colors_low.highlight,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "frame_color",
        .section = "urgency_low",
        .description = "Frame color for notifications with low urgency",
        .type = TYPE_STRING,
        .default_value = settings.frame_color ? settings.frame_color : defaults.colors_low.frame,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "timeout",
        .section = "urgency_low",
        .description = "Timeout for notifications with low urgency",
        .type = TYPE_TIME,
        .default_value = defaults.timeouts[URG_LOW],
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "icon",
        .section = "urgency_low",
        .description = "Icon for notifications with low urgency",
        .type = TYPE_STRING,
        .default_value = defaults.icons[URG_LOW],
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "background",
        .section = "urgency_normal",
        .description = "Background color for notifications with normal urgency",
        .type = TYPE_STRING,
        .default_value = defaults.colors_norm.bg,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "foreground",
        .section = "urgency_normal",
        .description = "Foreground color for notifications with normal urgency",
        .type = TYPE_STRING,
        .default_value = defaults.colors_norm.fg,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "highlight",
        .section = "urgency_normal",
        .description = "Highlight color for notifications with normal urgency",
        .type = TYPE_STRING,
        .default_value = defaults.colors_norm.highlight,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "frame_color",
        .section = "urgency_normal",
        .description = "Frame color for notifications with normal urgency",
        .type = TYPE_STRING,
        .default_value = settings.frame_color ? settings.frame_color : defaults.colors_norm.frame,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "timeout",
        .section = "urgency_normal",
        .description = "Timeout for notifications with normal urgency",
        .type = TYPE_TIME,
        .default_value = defaults.timeouts[URG_NORM],
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "icon",
        .section = "urgency_normal",
        .description = "Icon for notifications with normal urgency",
        .type = TYPE_STRING,
        .default_value = defaults.icons[URG_NORM],
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "background",
        .section = "urgency_critical",
        .description = "Background color for notifications with critical urgency",
        .type = TYPE_STRING,
        .default_value = defaults.colors_crit.bg,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "foreground",
        .section = "urgency_critical",
        .description = "Foreground color for notifications with ciritical urgency",
        .type = TYPE_STRING,
        .default_value = defaults.colors_crit.fg,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "highlight",
        .section = "urgency_critical",
        .description = "Highlight color for notifications with ciritical urgency",
        .type = TYPE_STRING,
        .default_value = defaults.colors_crit.highlight,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "frame_color",
        .section = "urgency_critical",
        .description = "Frame color for notifications with critical urgency",
        .type = TYPE_STRING,
        .default_value = settings.frame_color ? settings.frame_color : defaults.colors_crit.frame,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "timeout",
        .section = "urgency_critical",
        .description = "Timeout for notifications with critical urgency",
        .type = TYPE_TIME,
        .default_value = defaults.timeouts[URG_CRIT],
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "icon",
        .section = "urgency_critical",
        .description = "Icon for notifications with critical urgency",
        .type = TYPE_STRING,
        .default_value = defaults.icons[URG_CRIT],
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "close",
        .section = "shortcuts",
        .description = "Shortcut for closing one notification",
        .type = TYPE_STRING,
        .default_value = defaults.close_ks.str,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "close_all",
        .section = "shortcuts",
        .description = "Shortcut for closing all notifications",
        .type = TYPE_STRING,
        .default_value = defaults.close_all_ks.str,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "history",
        .section = "shortcuts",
        .description = "Shortcut to pop the last notification from history",
        .type = TYPE_STRING,
        .default_value = defaults.history_ks.str,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "context",
        .section = "shortcuts",
        .description = "Shortcut for context menu",
        .type = TYPE_STRING,
        .default_value = defaults.context_ks.str,
        .parser = NULL,
        .parser_data = NULL,
},
{
        .name = "always_run_script",
        .section = "global",
        .description = "Always run rule-defined scripts, even if the notification is suppressed with format = \"\".",
        .type = TYPE_BOOLEAN,
        .default_value = true,
        .parser = NULL,
        .parser_data = NULL,
},
