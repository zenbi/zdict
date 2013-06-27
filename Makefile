#
# zdict - simple dictionary viewer
# Copyright (C) 2004-2013 Bryan Beicker <bryan@beicker.com>
#
# This file is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License (Version 3)
# as published by the Free Software Foundation.
#
# This file is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#

ifndef PREFIX
	PREFIX = /usr
endif
ifndef BINDIR
	BINDIR = /bin
endif

GTK_CFLAGS = `pkg-config --cflags gtk+-3.0`
GTK_LIBS = `pkg-config --libs gtk+-3.0`
OBJECTS = main.o zdict_gui.o zdict.o about.o
ICONS = book_16.h book_48.h
VERSION = `awk '$$2 == "VERSION" { print $$3 }' main.h | sed s/\"//g`

all: zdict

zdict: $(ICONS) $(OBJECTS)
	$(CC) -Wall -s $(OBJECTS) $(GLIBS) $(LDFLAGS) -o $@ $(LIBS) $(GTK_CFLAGS) $(GTK_LIBS)

%.o: %.c main.h en.h ja.h
	$(CC) -Wall $(CFLAGS) -c $< $(GTK_CFLAGS)

book_16.h: book-16.png
	gdk-pixbuf-csource --raw --name=book_16 $< > $@

book_48.h: book-48.png
	gdk-pixbuf-csource --raw --name=book_48 $< > $@

clean:
	rm -rf *.o zdict bin obj zdict*.tar.gz $(ICONS)

install: zdict
	mkdir -p -m 755 $(DESTDIR)
	mkdir -p -m 755 $(DESTDIR)$(PREFIX)
	mkdir -p -m 755 $(DESTDIR)$(PREFIX)$(BINDIR)
	mkdir -p -m 755 $(DESTDIR)$(PREFIX)/share
	mkdir -p -m 755 $(DESTDIR)$(PREFIX)/share/applications
	mkdir -p -m 755 $(DESTDIR)$(PREFIX)/share/icons
	mkdir -p -m 755 $(DESTDIR)$(PREFIX)/share/icons/hicolor/16x16
	mkdir -p -m 755 $(DESTDIR)$(PREFIX)/share/icons/hicolor/16x16/apps
	mkdir -p -m 755 $(DESTDIR)$(PREFIX)/share/icons/hicolor/32x32
	mkdir -p -m 755 $(DESTDIR)$(PREFIX)/share/icons/hicolor/32x32/apps
	mkdir -p -m 755 $(DESTDIR)$(PREFIX)/share/icons/hicolor/48x48
	mkdir -p -m 755 $(DESTDIR)$(PREFIX)/share/icons/hicolor/48x48/apps
	mkdir -p -m 755 $(DESTDIR)$(PREFIX)/share/man
	mkdir -p -m 755 $(DESTDIR)$(PREFIX)/share/man/man1
	cp zdict $(DESTDIR)$(PREFIX)$(BINDIR)
	cp zdict.desktop $(DESTDIR)$(PREFIX)/share/applications/
	cp book-16.png $(DESTDIR)$(PREFIX)/share/icons/hicolor/16x16/apps/zdict.png
	cp book-32.png $(DESTDIR)$(PREFIX)/share/icons/hicolor/32x32/apps/zdict.png
	cp book-48.png $(DESTDIR)$(PREFIX)/share/icons/hicolor/48x48/apps/zdict.png
	gzip -c zdict.1 > $(DESTDIR)$(PREFIX)/share/man/man1/zdict.1.gz
	chmod 755 $(DESTDIR)$(PREFIX)$(BINDIR)/zdict
	chmod 644 $(DESTDIR)$(PREFIX)/share/applications/zdict.desktop
	chmod 644 $(DESTDIR)$(PREFIX)/share/icons/hicolor/16x16/apps/zdict.png
	chmod 644 $(DESTDIR)$(PREFIX)/share/icons/hicolor/32x32/apps/zdict.png
	chmod 644 $(DESTDIR)$(PREFIX)/share/icons/hicolor/48x48/apps/zdict.png
	chmod 644 $(DESTDIR)$(PREFIX)/share/man/man1/zdict.1.gz

tarball:
	@echo creating zdict-$(VERSION).tar.gz
	@git archive --prefix=zdict-$(VERSION)/ -o zdict-$(VERSION).tar.gz HEAD
