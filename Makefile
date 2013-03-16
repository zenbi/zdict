#
# zdict - simple dictionary viewer
# Copyright (C) 2004-2005 Bryan Beicker <tokiko@tokiko.net>
#
# This file is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License (Version 2)
# as published by the Free Software Foundation.
#
# This file is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#

PREFIX = /prog/zdict
RUNDIR = /prog/zdict/run

GTK_CFLAGS = `pkg-config --cflags gtk+-2.0`
GTK_LIBS = `pkg-config --libs gtk+-2.0`
OBJECTS = main.o zdict.w.o zdict.z.o about.o


zdict: $(OBJECTS)
	$(CC) -Wall $(OBJECTS) $(GLIBS) $(LDFLAGS) -o $@ $(LIBS) $(GTK_CFLAGS) $(GTK_LIBS)
	strip $@

%.o: %.c main.h en.h ja.h
	$(CC) -Wall $(CFLAGS) -c $< $(GTK_CFLAGS)

clean:
	rm -f *.o zdict

install: zdict
	mkdir -p -m 755 $(PREFIX)
	mkdir -p -m 755 $(RUNDIR)
	cp zdict $(RUNDIR)
	chmod 755 $(RUNDIR)/zdict
