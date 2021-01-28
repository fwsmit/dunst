#!/usr/bin/awk -f

BEGIN {
        ACTIVE = 0
        IN_SETTING = 0
        SETTING_TYPE = "unknown"
        SETTING_LOCATION = "unknown"
        SETTING_NAME = "unknown"
        SETTING_SECTION = "unknown"
        SETTING_DEFAULT = "unknown"
        SETTING_DESCRIPTION = "unknown"
        errors = ""
        unextracted = ""
        n_lines = 0
        line_number = 64
}

# Start of extraction
/^void load_settings/ { ACTIVE = 1 }

# end of extraction
/push hardcoded default rules into rules list/ { ACTIVE = 0 }

/settings\..* = option_get/ {
        if (ACTIVE) {
                if (IN_SETTING == 0){
                        IN_SETTING = 1
                        SETTING_LOCATION = $1
                        if ($3 == "option_get_bool("){
                                SETTING_TYPE = "TYPE_BOOLEAN"
                        } else if ($3 == "option_get_string("){
                                SETTING_TYPE = "TYPE_STRING"
                        } else if ($3 == "option_get_time("){
                                SETTING_TYPE = "TYPE_TIME"
                        } else if ($3 == "option_get_int("){
                                SETTING_TYPE = "TYPE_INT"
                        } else if ($3 == "option_get_path("){
                                SETTING_TYPE = "TYPE_PATH"
                        } else {
                                SETTING_TYPE = "TYPE_NOT_FOUND"
                                errors = errors "TYPE_NOT_FOUND " $3 " line " line_number "\n"
                        }
                        n_lines++
                }
        }
}

{
        if (IN_SETTING){
                if (n_lines == 2) {
                        SETTING_SECTION = substr($1, 0, length($1)-1)
                }
                if (n_lines == 3) {
                        SETTING_NAME = substr($1, 0, length($1)-1)
                        n = split($0, array, ",")
                        SETTING_DEFAULT = array[3]
                        sub(/^ +/, "", SETTING_DEFAULT)
                }
                if (n_lines == 4) {
                        SETTING_DESCRIPTION = $0
                        sub(/^ +/, "", SETTING_DESCRIPTION)
                }
             # print
             n_lines ++
        }
        line_number ++
        if (ACTIVE && !IN_SETTING) {
                unextracted = unextracted $0 "\n"
        }
}

# end of setting
/^        );$/ {
        IN_SETTING = 0
        if (n_lines != 6) {
                errors = errors "ERROR, not the expected number of lines (" n_lines ") line " line_number "-" line_number+n_lines "\n"
        } else {
                print "{"
                print "        .name = " SETTING_NAME ","
                print "        .section = " SETTING_SECTION ","
                print "        .description = " SETTING_DESCRIPTION ","
                print "        .type = " SETTING_TYPE ","
                print "        .default_value = " SETTING_DEFAULT ","
                print "        .parser = NULL,"
                print "        .parser_data = NULL,"
                print "},"
        }

        SETTING_TYPE = "unknown"
        SETTING_LOCATION = "unknown"
        SETTING_NAME = "unknown"
        SETTING_SECTION = "unknown"
        SETTING_DEFAULT = "unknown"
        SETTING_DESCRIPTION = "unknown"
        n_lines = 0
}

END {
        print "These lines have not been extracted"
        print unextracted
        print "These errors have to be manually corrected: "
        print errors
}
