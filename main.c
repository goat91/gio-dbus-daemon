#include "system_manager.h"
#include <glib.h>
#include <string.h>

typedef enum
{
  SYSTEM_MANAGER_USER_UNKNOWN_ERROR,
  SYSTEM_MANAGER_INVALID_ARGUMENTS_ERROR,
  SYSTEM_MANAGER_N_ERRORS
} SystemManagerError;

static const GDBusErrorEntry system_manager_error_entries[] =
{
  {SYSTEM_MANAGER_USER_UNKNOWN_ERROR,    "org.freedesktop.SystemManager.Error.UnknownUser"},
  {SYSTEM_MANAGER_INVALID_ARGUMENTS_ERROR, "org.freedesktop.SystemManager.Error.InvalidArguments"},
};

static GMainLoop *loop;
static volatile gsize system_manager_quark;

static gboolean user_auth_callback(SystemManagerUser *object,
	GDBusMethodInvocation *invocation,
	const gchar *username,
	const gchar *password,
	gpointer user_data)
{
	if (!strcmp(username, "test")) {
		g_print("username is '%s', password is '%s'\n", username, password);
		system_manager_user_complete_auth(object, invocation, TRUE);	
	} else {
		g_dbus_method_invocation_return_error(invocation,
				system_manager_quark,
				SYSTEM_MANAGER_USER_UNKNOWN_ERROR,
				"unknown user '%s'",
				username);	
	}
	
	return TRUE;
}

gboolean get_status_callback (
		SystemManagerNetwork *object,
		GDBusMethodInvocation *invocation,
    	const gchar *arg_interface,
		gpointer user_data)
{
		g_dbus_method_invocation_return_error(invocation,
				system_manager_quark,
				SYSTEM_MANAGER_INVALID_ARGUMENTS_ERROR,
				"unknown interface '%s'",
				arg_interface);
		return TRUE;
}

static void bus_acquired_cb(GDBusConnection *connection,
		const gchar *name,
		gpointer user_data)
{
	g_print("bus acquired\n");
}

static void name_acquired_cb(GDBusConnection *connection,
		const gchar *name,
		gpointer user_data)
{
	gboolean success;
	GError *error = NULL;
	
	SystemManagerUser *user_manager = system_manager_user_skeleton_new();	
	SystemManagerNetwork *network_manager = system_manager_network_skeleton_new();	

	g_print("name acquired\n");

	g_signal_connect(user_manager, "handle-auth", G_CALLBACK(user_auth_callback), NULL);
	g_signal_connect(network_manager, "handle-status", G_CALLBACK(get_status_callback), NULL);

	g_print("export interfaces\n");
	g_dbus_interface_skeleton_export(G_DBUS_INTERFACE_SKELETON(user_manager), connection, "/org/freedesktop/SystemManager/User", NULL);
	g_dbus_interface_skeleton_export(G_DBUS_INTERFACE_SKELETON(network_manager), connection, "/org/freedesktop/SystemManager/Network", NULL);

}

int main(void)
{

	g_dbus_error_register_error_domain("system-manager-error-quark",
			&system_manager_quark,
			system_manager_error_entries,
			G_N_ELEMENTS(system_manager_error_entries));

	guint owner_id = g_bus_own_name(G_BUS_TYPE_SYSTEM,
			"org.freedesktop.SystemManager",
			G_BUS_NAME_OWNER_FLAGS_NONE,
			&bus_acquired_cb,
			&name_acquired_cb,
			NULL,
			NULL,
			NULL);
			
	loop = g_main_loop_new(NULL, FALSE);

	g_main_loop_run(loop);

	g_bus_unown_name(owner_id);
	return 0;
}
