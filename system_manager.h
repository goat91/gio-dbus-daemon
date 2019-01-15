/*
 * Generated by gdbus-codegen 2.48.0. DO NOT EDIT.
 *
 * The license of this code is the same as for the source it was derived from.
 */

#ifndef __SYSTEM_MANAGER_H__
#define __SYSTEM_MANAGER_H__

#include <gio/gio.h>

G_BEGIN_DECLS


/* ------------------------------------------------------------------------ */
/* Declarations for org.freedesktop.SystemManager.User */

#define TYPE_SYSTEM_MANAGER_USER (system_manager_user_get_type ())
#define SYSTEM_MANAGER_USER(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TYPE_SYSTEM_MANAGER_USER, SystemManagerUser))
#define IS_SYSTEM_MANAGER_USER(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TYPE_SYSTEM_MANAGER_USER))
#define SYSTEM_MANAGER_USER_GET_IFACE(o) (G_TYPE_INSTANCE_GET_INTERFACE ((o), TYPE_SYSTEM_MANAGER_USER, SystemManagerUserIface))

struct _SystemManagerUser;
typedef struct _SystemManagerUser SystemManagerUser;
typedef struct _SystemManagerUserIface SystemManagerUserIface;

struct _SystemManagerUserIface
{
  GTypeInterface parent_iface;

  gboolean (*handle_auth) (
    SystemManagerUser *object,
    GDBusMethodInvocation *invocation,
    const gchar *arg_username,
    const gchar *arg_password);

};

GType system_manager_user_get_type (void) G_GNUC_CONST;

GDBusInterfaceInfo *system_manager_user_interface_info (void);
guint system_manager_user_override_properties (GObjectClass *klass, guint property_id_begin);


/* D-Bus method call completion functions: */
void system_manager_user_complete_auth (
    SystemManagerUser *object,
    GDBusMethodInvocation *invocation,
    gboolean unnamed_arg2);



/* D-Bus method calls: */
void system_manager_user_call_auth (
    SystemManagerUser *proxy,
    const gchar *arg_username,
    const gchar *arg_password,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean system_manager_user_call_auth_finish (
    SystemManagerUser *proxy,
    gboolean *out_unnamed_arg2,
    GAsyncResult *res,
    GError **error);

gboolean system_manager_user_call_auth_sync (
    SystemManagerUser *proxy,
    const gchar *arg_username,
    const gchar *arg_password,
    gboolean *out_unnamed_arg2,
    GCancellable *cancellable,
    GError **error);



/* ---- */

#define TYPE_SYSTEM_MANAGER_USER_PROXY (system_manager_user_proxy_get_type ())
#define SYSTEM_MANAGER_USER_PROXY(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TYPE_SYSTEM_MANAGER_USER_PROXY, SystemManagerUserProxy))
#define SYSTEM_MANAGER_USER_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), TYPE_SYSTEM_MANAGER_USER_PROXY, SystemManagerUserProxyClass))
#define SYSTEM_MANAGER_USER_PROXY_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), TYPE_SYSTEM_MANAGER_USER_PROXY, SystemManagerUserProxyClass))
#define IS_SYSTEM_MANAGER_USER_PROXY(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TYPE_SYSTEM_MANAGER_USER_PROXY))
#define IS_SYSTEM_MANAGER_USER_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), TYPE_SYSTEM_MANAGER_USER_PROXY))

typedef struct _SystemManagerUserProxy SystemManagerUserProxy;
typedef struct _SystemManagerUserProxyClass SystemManagerUserProxyClass;
typedef struct _SystemManagerUserProxyPrivate SystemManagerUserProxyPrivate;

struct _SystemManagerUserProxy
{
  /*< private >*/
  GDBusProxy parent_instance;
  SystemManagerUserProxyPrivate *priv;
};

struct _SystemManagerUserProxyClass
{
  GDBusProxyClass parent_class;
};

GType system_manager_user_proxy_get_type (void) G_GNUC_CONST;

#if GLIB_CHECK_VERSION(2, 44, 0)
G_DEFINE_AUTOPTR_CLEANUP_FUNC (SystemManagerUserProxy, g_object_unref)
#endif

void system_manager_user_proxy_new (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
SystemManagerUser *system_manager_user_proxy_new_finish (
    GAsyncResult        *res,
    GError             **error);
SystemManagerUser *system_manager_user_proxy_new_sync (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);

void system_manager_user_proxy_new_for_bus (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
SystemManagerUser *system_manager_user_proxy_new_for_bus_finish (
    GAsyncResult        *res,
    GError             **error);
SystemManagerUser *system_manager_user_proxy_new_for_bus_sync (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);


/* ---- */

#define TYPE_SYSTEM_MANAGER_USER_SKELETON (system_manager_user_skeleton_get_type ())
#define SYSTEM_MANAGER_USER_SKELETON(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TYPE_SYSTEM_MANAGER_USER_SKELETON, SystemManagerUserSkeleton))
#define SYSTEM_MANAGER_USER_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), TYPE_SYSTEM_MANAGER_USER_SKELETON, SystemManagerUserSkeletonClass))
#define SYSTEM_MANAGER_USER_SKELETON_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), TYPE_SYSTEM_MANAGER_USER_SKELETON, SystemManagerUserSkeletonClass))
#define IS_SYSTEM_MANAGER_USER_SKELETON(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TYPE_SYSTEM_MANAGER_USER_SKELETON))
#define IS_SYSTEM_MANAGER_USER_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), TYPE_SYSTEM_MANAGER_USER_SKELETON))

typedef struct _SystemManagerUserSkeleton SystemManagerUserSkeleton;
typedef struct _SystemManagerUserSkeletonClass SystemManagerUserSkeletonClass;
typedef struct _SystemManagerUserSkeletonPrivate SystemManagerUserSkeletonPrivate;

struct _SystemManagerUserSkeleton
{
  /*< private >*/
  GDBusInterfaceSkeleton parent_instance;
  SystemManagerUserSkeletonPrivate *priv;
};

struct _SystemManagerUserSkeletonClass
{
  GDBusInterfaceSkeletonClass parent_class;
};

GType system_manager_user_skeleton_get_type (void) G_GNUC_CONST;

#if GLIB_CHECK_VERSION(2, 44, 0)
G_DEFINE_AUTOPTR_CLEANUP_FUNC (SystemManagerUserSkeleton, g_object_unref)
#endif

SystemManagerUser *system_manager_user_skeleton_new (void);


/* ------------------------------------------------------------------------ */
/* Declarations for org.freedesktop.SystemManager.Network */

#define TYPE_SYSTEM_MANAGER_NETWORK (system_manager_network_get_type ())
#define SYSTEM_MANAGER_NETWORK(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TYPE_SYSTEM_MANAGER_NETWORK, SystemManagerNetwork))
#define IS_SYSTEM_MANAGER_NETWORK(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TYPE_SYSTEM_MANAGER_NETWORK))
#define SYSTEM_MANAGER_NETWORK_GET_IFACE(o) (G_TYPE_INSTANCE_GET_INTERFACE ((o), TYPE_SYSTEM_MANAGER_NETWORK, SystemManagerNetworkIface))

struct _SystemManagerNetwork;
typedef struct _SystemManagerNetwork SystemManagerNetwork;
typedef struct _SystemManagerNetworkIface SystemManagerNetworkIface;

struct _SystemManagerNetworkIface
{
  GTypeInterface parent_iface;

  gboolean (*handle_connect) (
    SystemManagerNetwork *object,
    GDBusMethodInvocation *invocation,
    const gchar *arg_interface);

  gboolean (*handle_status) (
    SystemManagerNetwork *object,
    GDBusMethodInvocation *invocation,
    const gchar *arg_interface);

};

GType system_manager_network_get_type (void) G_GNUC_CONST;

GDBusInterfaceInfo *system_manager_network_interface_info (void);
guint system_manager_network_override_properties (GObjectClass *klass, guint property_id_begin);


/* D-Bus method call completion functions: */
void system_manager_network_complete_connect (
    SystemManagerNetwork *object,
    GDBusMethodInvocation *invocation,
    gboolean unnamed_arg1);

void system_manager_network_complete_status (
    SystemManagerNetwork *object,
    GDBusMethodInvocation *invocation,
    guint64 unnamed_arg1);



/* D-Bus method calls: */
void system_manager_network_call_connect (
    SystemManagerNetwork *proxy,
    const gchar *arg_interface,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean system_manager_network_call_connect_finish (
    SystemManagerNetwork *proxy,
    gboolean *out_unnamed_arg1,
    GAsyncResult *res,
    GError **error);

gboolean system_manager_network_call_connect_sync (
    SystemManagerNetwork *proxy,
    const gchar *arg_interface,
    gboolean *out_unnamed_arg1,
    GCancellable *cancellable,
    GError **error);

void system_manager_network_call_status (
    SystemManagerNetwork *proxy,
    const gchar *arg_interface,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean system_manager_network_call_status_finish (
    SystemManagerNetwork *proxy,
    guint64 *out_unnamed_arg1,
    GAsyncResult *res,
    GError **error);

gboolean system_manager_network_call_status_sync (
    SystemManagerNetwork *proxy,
    const gchar *arg_interface,
    guint64 *out_unnamed_arg1,
    GCancellable *cancellable,
    GError **error);



/* ---- */

#define TYPE_SYSTEM_MANAGER_NETWORK_PROXY (system_manager_network_proxy_get_type ())
#define SYSTEM_MANAGER_NETWORK_PROXY(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TYPE_SYSTEM_MANAGER_NETWORK_PROXY, SystemManagerNetworkProxy))
#define SYSTEM_MANAGER_NETWORK_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), TYPE_SYSTEM_MANAGER_NETWORK_PROXY, SystemManagerNetworkProxyClass))
#define SYSTEM_MANAGER_NETWORK_PROXY_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), TYPE_SYSTEM_MANAGER_NETWORK_PROXY, SystemManagerNetworkProxyClass))
#define IS_SYSTEM_MANAGER_NETWORK_PROXY(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TYPE_SYSTEM_MANAGER_NETWORK_PROXY))
#define IS_SYSTEM_MANAGER_NETWORK_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), TYPE_SYSTEM_MANAGER_NETWORK_PROXY))

typedef struct _SystemManagerNetworkProxy SystemManagerNetworkProxy;
typedef struct _SystemManagerNetworkProxyClass SystemManagerNetworkProxyClass;
typedef struct _SystemManagerNetworkProxyPrivate SystemManagerNetworkProxyPrivate;

struct _SystemManagerNetworkProxy
{
  /*< private >*/
  GDBusProxy parent_instance;
  SystemManagerNetworkProxyPrivate *priv;
};

struct _SystemManagerNetworkProxyClass
{
  GDBusProxyClass parent_class;
};

GType system_manager_network_proxy_get_type (void) G_GNUC_CONST;

#if GLIB_CHECK_VERSION(2, 44, 0)
G_DEFINE_AUTOPTR_CLEANUP_FUNC (SystemManagerNetworkProxy, g_object_unref)
#endif

void system_manager_network_proxy_new (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
SystemManagerNetwork *system_manager_network_proxy_new_finish (
    GAsyncResult        *res,
    GError             **error);
SystemManagerNetwork *system_manager_network_proxy_new_sync (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);

void system_manager_network_proxy_new_for_bus (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
SystemManagerNetwork *system_manager_network_proxy_new_for_bus_finish (
    GAsyncResult        *res,
    GError             **error);
SystemManagerNetwork *system_manager_network_proxy_new_for_bus_sync (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);


/* ---- */

#define TYPE_SYSTEM_MANAGER_NETWORK_SKELETON (system_manager_network_skeleton_get_type ())
#define SYSTEM_MANAGER_NETWORK_SKELETON(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TYPE_SYSTEM_MANAGER_NETWORK_SKELETON, SystemManagerNetworkSkeleton))
#define SYSTEM_MANAGER_NETWORK_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), TYPE_SYSTEM_MANAGER_NETWORK_SKELETON, SystemManagerNetworkSkeletonClass))
#define SYSTEM_MANAGER_NETWORK_SKELETON_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), TYPE_SYSTEM_MANAGER_NETWORK_SKELETON, SystemManagerNetworkSkeletonClass))
#define IS_SYSTEM_MANAGER_NETWORK_SKELETON(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TYPE_SYSTEM_MANAGER_NETWORK_SKELETON))
#define IS_SYSTEM_MANAGER_NETWORK_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), TYPE_SYSTEM_MANAGER_NETWORK_SKELETON))

typedef struct _SystemManagerNetworkSkeleton SystemManagerNetworkSkeleton;
typedef struct _SystemManagerNetworkSkeletonClass SystemManagerNetworkSkeletonClass;
typedef struct _SystemManagerNetworkSkeletonPrivate SystemManagerNetworkSkeletonPrivate;

struct _SystemManagerNetworkSkeleton
{
  /*< private >*/
  GDBusInterfaceSkeleton parent_instance;
  SystemManagerNetworkSkeletonPrivate *priv;
};

struct _SystemManagerNetworkSkeletonClass
{
  GDBusInterfaceSkeletonClass parent_class;
};

GType system_manager_network_skeleton_get_type (void) G_GNUC_CONST;

#if GLIB_CHECK_VERSION(2, 44, 0)
G_DEFINE_AUTOPTR_CLEANUP_FUNC (SystemManagerNetworkSkeleton, g_object_unref)
#endif

SystemManagerNetwork *system_manager_network_skeleton_new (void);


G_END_DECLS

#endif /* __SYSTEM_MANAGER_H__ */