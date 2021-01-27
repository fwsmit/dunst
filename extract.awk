#!/usr/bin/awk -f

BEGIN {
        ACTIVE = 0
        IN_SETTING = 0
        SETTING_TYPE = "unknown"
        SETTING_LOCATION = "unknown"
}
/^void load_settings/ { ACTIVE = 1 }
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
                                print "NOT " $3
                        }
                        print SETTING_LOCATION
                        print SETTING_TYPE
                }
        } 
}

{
        if (IN_SETTING){
             print   
        }
}

# end of setting
/^        );$/ {
        IN_SETTING = 0
}

END { 
}
