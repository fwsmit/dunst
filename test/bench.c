#include <time.h>
#include <stdio.h>
#include "../src/icon.h"
#include "../src/settings.h"

static void bench_icon_search() {
        clock_t start_time = clock();
        printf("Benchmarking icons\n");

        settings.icon_theme = "Papirus";
        /* settings.icon_path = "/usr/share/icons/Adwaita"; */
        /* settings.icon_path = "/usr/share/icons/Papirus"; */
        /* char* res = get_path_from_icon_name("display-brightness-low-symbolic", 1); */
        char* res = get_path_from_icon_name("edit-cut", 1);
        /* char* res = get_path_from_icon_name("dialog-information", 1); */

        double elapsed_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;
        printf("Done in %f seconds\n", elapsed_time);
        printf("Result :%s\n", res);
}
