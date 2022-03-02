#ifndef DUNST_TEST_DBUS_H
#define DUNST_TEST_DBUS_H

#include "greatest.h"
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <gio/gio.h>
#include <stdbool.h>

struct dbus_notification {
        const char* app_name;
        guint replaces_id;
        const char* app_icon;
        const char* summary;
        const char* body;
        GHashTable *actions;
        GHashTable *hints;
        int expire_timeout;
};

struct dbus_notification *dbus_notification_new(void);
bool dbus_notification_fire(struct dbus_notification *n, uint *id);
bool dbus_init_and_wait();
void dbus_notification_free(struct dbus_notification *n);
void dbus_clear_connection();

#endif
/* vim: set ft=c tabstop=8 shiftwidth=8 expandtab textwidth=0: */
