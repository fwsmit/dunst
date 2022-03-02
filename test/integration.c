#include "greatest.h"
#include "./dbus.h"
#include "./icon-lookup.h"
#include "../src/icon-lookup.h"

#include "queues.h"
#include <assert.h>
#include <gio/gio.h>

static gint owner_id;
static GMainLoop *loop;
static GThread *thread_tests;

static gpointer run_threaded_tests(gpointer data)
{
        dbus_init_and_wait(&owner_id);

        dbus_teardown(owner_id);
        g_main_loop_quit(loop);
        return NULL;
}

SUITE (suite_integration)
{
        setup_test_theme();
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
        free_all_themes();
}
/* vim: set ft=c tabstop=8 shiftwidth=8 expandtab textwidth=0: */
