#include "greatest.h"
#include "./dbus.h"
#include "./icon-lookup.h"
#include "../src/icon-lookup.h"
#include "../src/settings.h"

#include "queues.h"
#include <assert.h>
#include <gio/gio.h>
#include <cairo.h>

static gint owner_id;
extern const char *base;

TEST test_hint_icons2(void)
{
        struct notification *n;
        struct dbus_notification *n_dbus;
        const char *iconname = "edit";
        char *path = g_strconcat(base, "/data/icons/valid.png", NULL);

        gsize len = queues_length_waiting();

        n_dbus = dbus_notification_new();
        /* dbus_notification_set_raw_image(n_dbus, path); */
        n_dbus->app_name = "dunstteststack";
        n_dbus->app_icon = "NONE";
        n_dbus->summary = "test_hint_icons";
        n_dbus->body = "Summary of it";

        g_hash_table_insert(n_dbus->hints,
                            g_strdup("image-path"),
                            g_variant_ref_sink(g_variant_new_string(iconname)));

        guint id;
        ASSERT(dbus_notification_fire(n_dbus, &id));
        ASSERT(id != 0);

        ASSERT_EQ(queues_length_waiting(), len+1);

        n = queues_debug_find_notification_by_id(id);

        ASSERT(n->icon);
        /* printf("%s\n", n->iconname); */
        /* printf("%s\n", n->icon_path); */
        printf("icon: %p\n", n->icon);
        /* printf("icon size: %i\n", cairo_image_surface_get_height(n->icon)); */
        /* printf("icon size: %i\n", cairo_image_surface_get_width(n->icon)); */
        ASSERT_STR_EQ(iconname, n->iconname);

        dbus_notification_free(n_dbus);
        g_free(path);

        PASS();
}

static GMainLoop *loop;
static GThread *thread_tests;

static gpointer run_threaded_tests(gpointer data)
{
        dbus_init_and_wait(&owner_id);
        RUN_TEST(test_hint_icons2);

        dbus_teardown(owner_id);
        g_main_loop_quit(loop);
        return NULL;
}

SUITE (suite_integration)
{
        setup_test_theme();
        bool tmp = settings.enable_recursive_icon_lookup;
        settings.enable_recursive_icon_lookup = true;
        GTestDBus *dbus_bus;
        g_test_dbus_unset();
        queues_init();

        loop = g_main_loop_new(NULL, false);

        dbus_bus = g_test_dbus_new(G_TEST_DBUS_NONE);

        fflush(stdout);
        g_test_dbus_up(dbus_bus);

        thread_tests = g_thread_new("testexecutor2", run_threaded_tests, loop);
        g_main_loop_run(loop);

        queues_teardown();
        g_test_dbus_down(dbus_bus);
        g_object_unref(dbus_bus);
        g_thread_unref(thread_tests);
        g_main_loop_unref(loop);
        dbus_clear_connection();
        settings.enable_recursive_icon_lookup = tmp;
        free_all_themes();
}
/* vim: set ft=c tabstop=8 shiftwidth=8 expandtab textwidth=0: */
