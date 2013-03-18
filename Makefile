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

PREFIX = /usr/local

GTK_CFLAGS = `pkg-config --cflags gtk+-3.0`
GTK_LIBS = `pkg-config --libs gtk+-3.0`
OBJECTS = main.o zdict_gui.o zdict.o about.o
VERSION = `awk '$$2 == "VERSION" { print $$3 }' main.h | sed s/\"//g`

zdict: $(OBJECTS)
	$(CC) -Wall $(OBJECTS) $(GLIBS) $(LDFLAGS) -o $@ $(LIBS) $(GTK_CFLAGS) $(GTK_LIBS)
	strip $@

%.o: %.c main.h en.h ja.h
	$(CC) -Wall $(CFLAGS) -c $< $(GTK_CFLAGS)

clean:
	rm -rf *.o zdict bin obj

install: zdict
	mkdir -p -m 755 $(PREFIX)
	cp zdict $(PREFIX)/bin
	chmod 755 $(PREFIX)/bin/zdict

tarball:
	@echo creating zdict-$(VERSION).tar.gz
	@git archive --prefix=zdict-$(VERSION)/ -o zdict-$(VERSION).tar.gz HEAD
