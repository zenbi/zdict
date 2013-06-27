//
// zdict - simple dictionary viewer
// Copyright (C) 2004-2013 Bryan Beicker <bryan@beicker.com>
//
// This file is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License (Version 3)
// as published by the Free Software Foundation.
//
// This file is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//

#include <gtk/gtk.h>		// gtk
#include <string.h>		// strcmp()
#include "main.h"


//
// start program
//
int main(int argc, char * argv[])
{
	if (argc > 1) {
		if (strcmp(argv[1], "--version") == 0) {
			g_print("zdict " VERSION "\n");
			return 0;
		}
		if (strcmp(argv[1], "--help") == 0) {
			g_print("zdict " VERSION "\n\n");
			g_print("Options:\n\n");
			g_print("        --help          display this help and exit\n");
			g_print("        --version       output version information and exit\n\n");
			return 0;
		}
	}

	gtk_init(&argc, &argv);
	zdict_create();
	gtk_main();

	return 0;
}
