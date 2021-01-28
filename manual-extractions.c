#define ENUM_END {NULL, 0}

static struct string_to_enum_def verbosity_enum_data[] = {
        {"critical", G_LOG_LEVEL_CRITICAL },
        {"crit", G_LOG_LEVEL_CRITICAL },
        {"warning", G_LOG_LEVEL_WARNING },
        {"warn", G_LOG_LEVEL_WARNING },
        {"message", G_LOG_LEVEL_MESSAGE },
        {"mesg", G_LOG_LEVEL_MESSAGE },
        {"info", G_LOG_LEVEL_INFO },
        {"debug", G_LOG_LEVEL_DEBUG },
        {"deb", G_LOG_LEVEL_DEBUG },
        ENUM_END,
};

static struct string_to_enum_def alignment_enum_data[] = {
        {"left",   ALIGN_LEFT },
        {"center", ALIGN_CENTER },
        {"right",  ALIGN_RIGHT },
        ENUM_END,
};

static struct string_to_enum_def ellipsize_enum_data[] = {
        {"start",  ELLIPSE_START },
        {"middle", ELLIPSE_MIDDLE },
        {"end",    ELLIPSE_END },
        ENUM_END,
};

static struct string_to_enum_def follow_mode_enum_data[] = {
        {"mouse",    FOLLOW_MOUSE },
        {"keyboard", FOLLOW_KEYBOARD },
        {"none",     FOLLOW_NONE },
        ENUM_END,
}

static struct string_to_enum_def fullscreen_enum_data[] = {
        {"show",     FS_SHOW },
        {"delay",    FS_DELAY },
        {"pushback", FS_PUSHBACK },
        ENUM_END,
}

static struct string_to_enum_def icon_position_enum_data[] = {
        {"left",  ICON_LEFT },
        {"right", ICON_RIGHT },
        {"off",   ICON_OFF },
        ENUM_END,
}

static struct string_to_enum_def alignment_enum_data[] = {
        {"top",     VERTICAL_TOP },
        {"center",  VERTICAL_CENTER },
        {"bottom",  VERTICAL_BOTTOM },
        ENUM_END,
}

static struct string_to_enum_def markup_mode_enum_data[] = {
        {"strip", MARKUP_STRIP },
        {"no",    MARKUP_NO },
        {"full",  MARKUP_FULL },
        {"yes",   MARKUP_FULL },
        ENUM_END,
}

static struct string_to_enum_def mouse_action_enum_data[] = {
        {"none",           MOUSE_NONE },
        {"do_action",      MOUSE_DO_ACTION },
        {"close_current",  MOUSE_CLOSE_CURRENT },
        {"close_all",      MOUSE_CLOSE_ALL },
        ENUM_END,
}

static struct string_to_enum_def sep_color_enum_data[] = {
        {"auto",       (struct separator_color_data){.type = SEP_AUTO} },
        {"foreground", (struct separator_color_data){.type = SEP_FOREGROUND} },
        {"frame",      (struct separator_color_data){.type = SEP_FRAME} },
        ENUM_END,
}

static struct string_to_enum_def urgency_enum_data[] = {
        {"low",      URG_LOW },
        {"normal",   URG_NORM },
        {"critical", URG_CRIT },
        ENUM_END,
}

static struct string_to_enum_def layer_enum_data[] = {
        {"bottom",  ZWLR_LAYER_SHELL_V1_LAYER_BOTTOM },
        {"top",     ZWLR_LAYER_SHELL_V1_LAYER_TOP },
        {"overlay", ZWLR_LAYER_SHELL_V1_LAYER_OVERLAY },
        ENUM_END,
}

{
        .name = "verbosity",
        .section = "global",
        .description = "The verbosity to log (one of 'crit', 'warn', 'mesg', 'info', 'debug')"
        .type = TYPE_ENUM,
        .default_value = "warning",
        .parser = string_parse_enum,
        .parser_data = verbosity_enum_data,
},

// TODO Maybe implement deprecated allow_markup
{
        .name = "markup",
        .section = "global",
        .description = "Specify how markup should be handled",
        .type = TYPE_ENUM,
        .default_value = defaults.markup,
        .parser = string_parse_enum,
        .parser_data = markup_enum_data,
},
{
        .name = "ellipsize",
        .section = "global",
        .description = "Ellipsize truncated lines on the start/middle/end",
        .type = TYPE_ENUM,
        .default_value = defaults.ellipsize,
        .parser = string_parse_enum,
        .parser_data = ellipsize_enum_data,
},
{
        .name = "follow",
        .section = "global",
        .description = "Follow mouse, keyboard or none?",
        .type = TYPE_ENUM,
        .default_value = defaults.follow_mode,
        .parser = string_parse_enum,
        .parser_data = follow_enum_data,
},
{
        .name = "geometry",
        .section = "global",
        .description = "Geometry for the window",
        .type = TYPE_ENUM,
        .default_value = defaults.geometry,
        .parser = x_parse_geometry, // TODO implement proxy for this parser
        .parser_data = NULL,
},
{
        .name = "alignment",
        .section = "global",
        .description = "Text alignment left/center/right",
        .type = TYPE_ENUM,
        .default_value = defaults.align,
        .parser = string_parse_enum,
        .parser_data = alignment_enum_data,
},
{
        .name = "separator_color",
        .section = "global",
        .description = "Color of the separator line (or 'auto')",
        .type = TYPE_ENUM,
        .default_value = defaults.sep_color,
        .parser = string_parse_enum,
        .parser_data = sep_color_enum_data,
},
{
        .name = "icon_position",
        .section = "global",
        .description = "Align icons left/right/off",
        .type = TYPE_ENUM,
        .default_value = defaults.icon_position,
        .parser = string_parse_enum,
        .parser_data = icon_position_enum_data,
},
{
        .name = "vertical_alignment",
        .section = "global",
        .description = "Align icon and text top/center/bottom",
        .type = TYPE_ENUM,
        .default_value = defaults.vertical_alignment,
        .parser = string_parse_enum,
        .parser_data = vertical_alignment_enum_data,
},
{
        .name = "layer",
        .section = "global",
        .description = "Select the layer where notifications should be placed",
        .type = TYPE_ENUM,
        .default_value = defaults.layer
        .parser = string_parse_enum,
        .parser_data = layer_enum_data,
},
// TODO maybe implement deprecated icon_folders
