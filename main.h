//
// zdict - simple dictionary viewer
// Copyright (C) 2004-2005 Bryan Beicker <tokiko@tokiko.net>
//
// This file is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License (Version 2)
// as published by the Free Software Foundation.
//
// This file is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//

#ifndef MAIN_H
#define MAIN_H

#define VERSION                 "0.3.2"

// zdict.w.c
void zdict_create();

// zdict.z.c
void zdict_load();
gboolean zdict_unload();
void zdict_destroy();
void about_button_click();
void combo_change(int);
void scroll_value_change(int);
void search_change(char *);

// about.c
void about_dialog(GtkWidget *, char **, char *, char *, char *);


// globals
GtkWidget * zdict;
GtkWidget * combo;
GtkWidget * name[10];
GtkWidget * value[10];
GtkWidget * scroll;
GtkWidget * search;
GtkWidget * version;

#endif
