CC=gcc
INSTALL=install
CFLAGS=`pkg-config --cflags gio-2.0 gio-unix-2.0`
LDFLAGS=`pkg-config --libs gio-2.0 gio-unix-2.0`


SOURCES=$(wildcard *.c)
OBJS=$(subst .c,.o,$(SOURCES))

target=system-manager

all: $(target)

$(target): $(OBJS)
	$(CC) $^ -o $@ $(LDFLAGS)

$(OBJS):%.o:%.c
	$(CC) -c $< -o $@ $(CFLAGS)

install:
	$(INSTALL) -m 0644 data/org.freedesktop.SystemManager.conf $(DESTDIR)/etc/dbus-1/system.d/
	$(INSTALL) -m 0644 data/org.freedesktop.SystemManager.service $(DESTDIR)/usr/share/dbus-1/system-services/
	$(INSTALL) -m 0755 $(target) $(DESTDIR)/usr/sbin/

clean:
	rm -rf $(target) $(OBJS)
