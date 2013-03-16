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

#include <gtk/gtk.h>		// gtk
#include <string.h>		// strlen(), strcmp()
#include "en.h"
#include "ja.h"
#include "main.h"
#include "zdict.xpm"


void zdict_load()
{
	gtk_range_set_increments(GTK_RANGE(scroll), 1, 1024);
	
	gtk_combo_box_append_text(GTK_COMBO_BOX(combo), "English to Japanese");
	gtk_combo_box_append_text(GTK_COMBO_BOX(combo), "Japanese to English");
	gtk_combo_box_set_active(GTK_COMBO_BOX(combo), 0);
}


//
// window manager is trying to close the window
//
gboolean zdict_unload()
{
	// let the window close
	return FALSE;
}


//
// exit the program when the window dies
//
void zdict_destroy()
{
	gtk_main_quit();
}


//
// display about box
//
void about_button_click()
{
	about_dialog(zdict, zdict_xpm, "zdict " VERSION, "simple dictionary viewer", "Copyright (C) 2004-2005 Bryan Beicker");
}


//
// change the dictionary
//
void combo_change(int lang)
{
	GtkAdjustment * a;

	if (lang == 0) {
		gtk_range_set_range(GTK_RANGE(scroll), 0, EN_NUM - 10);
	} else {
		gtk_range_set_range(GTK_RANGE(scroll), 0, JA_NUM - 10);
	}
	
	gtk_range_set_value(GTK_RANGE(scroll), 0);
	a = gtk_range_get_adjustment(GTK_RANGE(scroll));
	gtk_adjustment_value_changed(a);
	gtk_adjustment_changed(a);
	
	gtk_entry_set_text(GTK_ENTRY(search), "");
	gtk_widget_grab_focus(search);
}


//
// refresh the list
//
void scroll_value_change(int v)
{
	int lang;
	int i;
	
	lang = gtk_combo_box_get_active(GTK_COMBO_BOX(combo));
	
	if (lang == 0) {
		for (i = 0; i < 10; i++) {
			gtk_entry_set_text(GTK_ENTRY(name[i]), en[i + v][0]);
			gtk_entry_set_text(GTK_ENTRY(value[i]), en[i + v][1]);
		}
	} else {
		for (i = 0; i < 10; i++) {
			gtk_entry_set_text(GTK_ENTRY(name[i]), ja[i + v][0]);
			gtk_entry_set_text(GTK_ENTRY(value[i]), ja[i + v][1]);
		}
	}

}


//
// search for a string
//
void search_change(char * text)
{
	int lang;
	int i;
	
	if (strlen(text) == 0) {
		return;
	}

	lang = gtk_combo_box_get_active(GTK_COMBO_BOX(combo));
	if (lang == 0) {
		for (i = 0; i < EN_NUM; i++) {
			if (strcmp(text, en[i][0]) <= 0) {
				if (i > EN_NUM - 10) {
					i = EN_NUM - 10;
				}
				gtk_range_set_value(GTK_RANGE(scroll), i);
				gtk_adjustment_value_changed(gtk_range_get_adjustment(GTK_RANGE(scroll)));
				return;
			}
		}
	} else {
		for (i = 0; i < JA_NUM; i++) {
			if (strcmp(text, ja[i][0]) <= 0) {
				if (i > JA_NUM - 10) {
					i = JA_NUM - 10;
				}
				gtk_range_set_value(GTK_RANGE(scroll), i);
				gtk_adjustment_value_changed(gtk_range_get_adjustment(GTK_RANGE(scroll)));
				return;
			}
		}
	}	
}
