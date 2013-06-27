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

#ifndef MAIN_H
#define MAIN_H

#define VERSION                 "0.4.1"
#define COPYRIGHT		"Copyright (C) 2004-2013 Bryan Beicker"
#define DESCRIPTION		"Japanese to English dictionary"
#define WEBSITE			"http://zwin.org/zdict/"

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
void about_dialog(GtkWidget *);


// globals
GtkWidget * zdict;
GtkWidget * combo;
GtkWidget * name[10];
GtkWidget * value[10];
GtkWidget * scroll;
GtkWidget * search;
GtkWidget * version;

#endif
