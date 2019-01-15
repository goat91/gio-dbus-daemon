# gio-dbus-daemon
dbus daemon using gio


1. 在编写dbus接口的introspect XML文件后，用gdbus-codegen工具生成dbus接口代码

```
      # gdbus-codegen --interface-prefix=org.freedesktop. --generate-c-code=system_manager data/org.freedesktop.SystemManager.xml
```

2. 在代码中include生成的system_manager.h文件，通过g_bus_own_name函数来在对应的system Bus或Session Bus上注册DBus服务对应的Bus Name(例如代码中的org.freedesktop.SystemManager)，并调用g_loop_run进入事件循环

3. 在g_bus_own_name函数的回调参数中通过..skeleton_new()函数生成interface的实例

4. 通过g_signal_connect来将system_manager.c中为实例定义的信号和dbus method的实际处理函数(如代码中的user_auth_callback和get_status_callback)相连接，确保客户端调用dbus method的时候，对应的处理函数可以正常调用返回

5. 将步骤３中生成的interface实例通过g_dbus_interface_skeleton_export函数在dbus上导出为指定的对象路径
