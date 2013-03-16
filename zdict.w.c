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
#include "main.h"
#include "zdict.xpm"


gboolean zdict_delete_event_signal(GtkWidget * window, GdkEvent * event, gpointer data)
{
	return zdict_unload();
}


void zdict_destroy_signal(GtkWidget * window, gpointer data)
{
	zdict_destroy();
}


gboolean about_button_clicked(GtkWidget * widget, GdkEventButton * event, gpointer data)
{
	about_button_click();
	
	// we handled the event
	return TRUE;
}


void combo_changed_signal(GtkComboBox * widget, gpointer data)
{
	combo_change(gtk_combo_box_get_active(widget));
}


void scroll_value_changed_signal(GtkVScrollbar * widget, gpointer data)
{
	scroll_value_change((int) gtk_range_get_value(GTK_RANGE(widget)));
}


void search_changed_signal(GtkEntry * widget, gpointer data)
{
	search_change((char *) gtk_entry_get_text(widget));
}


void zdict_create()
{
	zdict = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(zdict), "zdict");
	gtk_window_set_resizable(GTK_WINDOW(zdict), FALSE);
	gtk_widget_set_size_request(zdict, 600, -1);
	
	GdkPixbuf * pixbuf;
	pixbuf = gdk_pixbuf_new_from_xpm_data((const char **) zdict_xpm);
	gtk_window_set_icon(GTK_WINDOW(zdict), pixbuf);
	
	GtkWidget * table;
	table = gtk_table_new(14, 3, FALSE);
	gtk_widget_show(table);
	gtk_container_add(GTK_CONTAINER(zdict), table);
	gtk_container_set_border_width(GTK_CONTAINER(table), 8);
	gtk_table_set_row_spacings(GTK_TABLE(table), 4);
	gtk_table_set_col_spacings(GTK_TABLE(table), 4);
	
	GtkWidget * table_top;
	table_top = gtk_table_new(1, 2, FALSE);
	gtk_widget_show(table_top);
	gtk_table_attach(GTK_TABLE(table), table_top, 0, 3, 0, 1, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 0, 0);
	gtk_table_set_row_spacings(GTK_TABLE(table_top), 8);
	gtk_table_set_col_spacings(GTK_TABLE(table_top), 8);
	
	GtkWidget * about_button;
	GdkPixbuf * about_pixbuf;
	GtkWidget * about_icon;
	about_button = gtk_button_new();
	about_pixbuf = gdk_pixbuf_new_from_xpm_data((const char **) zdict_xpm);
	about_icon = gtk_image_new_from_pixbuf(about_pixbuf);
	gtk_button_set_relief(GTK_BUTTON(about_button), GTK_RELIEF_NONE);
	gdk_pixbuf_unref(about_pixbuf);
	gtk_widget_show(about_button);
	gtk_widget_show(about_icon);
	gtk_container_add(GTK_CONTAINER(about_button), about_icon);
	gtk_table_attach(GTK_TABLE(table_top), about_button, 0, 1, 0, 1, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 0, 0);

	combo = gtk_combo_box_new_text();
	gtk_widget_show(combo);
	gtk_table_attach(GTK_TABLE(table_top), combo, 1, 2, 0, 1, (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	
	GtkWidget * hr1;
	hr1 = gtk_hseparator_new ();
	gtk_widget_show(hr1);
	gtk_table_attach(GTK_TABLE(table), hr1, 0, 3, 1, 2, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 0, 8);
	
	name[0] = gtk_entry_new();
	gtk_widget_show(name[0]);
	gtk_table_attach(GTK_TABLE(table), name[0], 0, 1, 2, 3, (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_editable_set_editable(GTK_EDITABLE(name[0]), FALSE);
	GTK_WIDGET_UNSET_FLAGS(name[0], GTK_CAN_FOCUS);
	
	name[1] = gtk_entry_new();
	gtk_widget_show(name[1]);
	gtk_table_attach(GTK_TABLE(table), name[1], 0, 1, 3, 4, (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_editable_set_editable(GTK_EDITABLE(name[1]), FALSE);
	GTK_WIDGET_UNSET_FLAGS(name[1], GTK_CAN_FOCUS);
	
	name[2] = gtk_entry_new();
	gtk_widget_show(name[2]);
	gtk_table_attach(GTK_TABLE(table), name[2], 0, 1, 4, 5, (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_editable_set_editable(GTK_EDITABLE(name[2]), FALSE);
	GTK_WIDGET_UNSET_FLAGS(name[2], GTK_CAN_FOCUS);
	
	name[3] = gtk_entry_new();
	gtk_widget_show(name[3]);
	gtk_table_attach(GTK_TABLE(table), name[3], 0, 1, 5, 6, (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_editable_set_editable(GTK_EDITABLE(name[3]), FALSE);
	GTK_WIDGET_UNSET_FLAGS(name[3], GTK_CAN_FOCUS);
	
	name[4] = gtk_entry_new();
	gtk_widget_show(name[4]);
	gtk_table_attach(GTK_TABLE(table), name[4], 0, 1, 6, 7, (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_editable_set_editable(GTK_EDITABLE(name[4]), FALSE);
	GTK_WIDGET_UNSET_FLAGS(name[4], GTK_CAN_FOCUS);
	
	name[5] = gtk_entry_new();
	gtk_widget_show(name[5]);
	gtk_table_attach(GTK_TABLE(table), name[5], 0, 1, 7, 8, (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_editable_set_editable(GTK_EDITABLE(name[5]), FALSE);
	GTK_WIDGET_UNSET_FLAGS(name[5], GTK_CAN_FOCUS);
	
	name[6] = gtk_entry_new();
	gtk_widget_show(name[6]);
	gtk_table_attach(GTK_TABLE(table), name[6], 0, 1, 8, 9, (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_editable_set_editable(GTK_EDITABLE(name[6]), FALSE);
	GTK_WIDGET_UNSET_FLAGS(name[6], GTK_CAN_FOCUS);
	
	name[7] = gtk_entry_new();
	gtk_widget_show(name[7]);
	gtk_table_attach(GTK_TABLE(table), name[7], 0, 1, 9, 10, (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_editable_set_editable(GTK_EDITABLE(name[7]), FALSE);
	GTK_WIDGET_UNSET_FLAGS(name[7], GTK_CAN_FOCUS);
	
	name[8] = gtk_entry_new();
	gtk_widget_show(name[8]);
	gtk_table_attach(GTK_TABLE(table), name[8], 0, 1, 10, 11, (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_editable_set_editable(GTK_EDITABLE(name[8]), FALSE);
	GTK_WIDGET_UNSET_FLAGS(name[8], GTK_CAN_FOCUS);
	
	name[9] = gtk_entry_new();
	gtk_widget_show(name[9]);
	gtk_table_attach(GTK_TABLE(table), name[9], 0, 1, 11, 12, (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_editable_set_editable(GTK_EDITABLE(name[9]), FALSE);
	GTK_WIDGET_UNSET_FLAGS(name[9], GTK_CAN_FOCUS);
	
	scroll = gtk_vscrollbar_new(NULL);
	gtk_widget_show(scroll);
	gtk_table_attach(GTK_TABLE(table), scroll, 1, 2, 2, 12, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 0, 0);
	
	value[0] = gtk_entry_new();
	gtk_widget_show(value[0]);
	gtk_table_attach(GTK_TABLE(table), value[0], 2, 3, 2, 3, (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_editable_set_editable(GTK_EDITABLE(value[0]), FALSE);
	GTK_WIDGET_UNSET_FLAGS(value[0], GTK_CAN_FOCUS);
	
	value[1] = gtk_entry_new();
	gtk_widget_show(value[1]);
	gtk_table_attach(GTK_TABLE(table), value[1], 2, 3, 3, 4, (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_editable_set_editable(GTK_EDITABLE(value[1]), FALSE);
	GTK_WIDGET_UNSET_FLAGS(value[1], GTK_CAN_FOCUS);
	
	value[2] = gtk_entry_new();
	gtk_widget_show(value[2]);
	gtk_table_attach(GTK_TABLE(table), value[2], 2, 3, 4, 5, (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_editable_set_editable(GTK_EDITABLE(value[2]), FALSE);
	GTK_WIDGET_UNSET_FLAGS(value[2], GTK_CAN_FOCUS);
	
	value[3] = gtk_entry_new();
	gtk_widget_show(value[3]);
	gtk_table_attach(GTK_TABLE(table), value[3], 2, 3, 5, 6, (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_editable_set_editable(GTK_EDITABLE(value[3]), FALSE);
	GTK_WIDGET_UNSET_FLAGS(value[3], GTK_CAN_FOCUS);
	
	value[4] = gtk_entry_new();
	gtk_widget_show(value[4]);
	gtk_table_attach(GTK_TABLE(table), value[4], 2, 3, 6, 7, (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_editable_set_editable(GTK_EDITABLE(value[4]), FALSE);
	GTK_WIDGET_UNSET_FLAGS(value[4], GTK_CAN_FOCUS);
	
	value[5] = gtk_entry_new();
	gtk_widget_show(value[5]);
	gtk_table_attach(GTK_TABLE(table), value[5], 2, 3, 7, 8, (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_editable_set_editable(GTK_EDITABLE(value[5]), FALSE);
	GTK_WIDGET_UNSET_FLAGS(value[5], GTK_CAN_FOCUS);
	
	value[6] = gtk_entry_new();
	gtk_widget_show(value[6]);
	gtk_table_attach(GTK_TABLE(table), value[6], 2, 3, 8, 9, (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_editable_set_editable(GTK_EDITABLE(value[6]), FALSE);
	GTK_WIDGET_UNSET_FLAGS(value[6], GTK_CAN_FOCUS);
	
	value[7] = gtk_entry_new();
	gtk_widget_show(value[7]);
	gtk_table_attach(GTK_TABLE(table), value[7], 2, 3, 9, 10, (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_editable_set_editable(GTK_EDITABLE(value[7]), FALSE);
	GTK_WIDGET_UNSET_FLAGS(value[7], GTK_CAN_FOCUS);
	
	value[8] = gtk_entry_new();
	gtk_widget_show(value[8]);
	gtk_table_attach(GTK_TABLE(table), value[8], 2, 3, 10, 11, (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_editable_set_editable(GTK_EDITABLE(value[8]), FALSE);
	GTK_WIDGET_UNSET_FLAGS(value[8], GTK_CAN_FOCUS);
	
	value[9] = gtk_entry_new();
	gtk_widget_show(value[9]);
	gtk_table_attach(GTK_TABLE(table), value[9], 2, 3, 11, 12, (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_editable_set_editable(GTK_EDITABLE(value[9]), FALSE);
	GTK_WIDGET_UNSET_FLAGS(value[9], GTK_CAN_FOCUS);
	
	GtkWidget * hr2;
	hr2 = gtk_hseparator_new();
	gtk_widget_show(hr2);
	gtk_table_attach(GTK_TABLE(table), hr2, 0, 3, 12, 13, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 0, 8);
	
	GtkWidget * table_bot;
	table_bot = gtk_table_new(1, 2, FALSE);
	gtk_widget_show(table_bot);
	gtk_table_attach(GTK_TABLE(table), table_bot, 0, 3, 13, 14, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 0, 0);
	gtk_table_set_row_spacings(GTK_TABLE(table_bot), 8);
	gtk_table_set_col_spacings(GTK_TABLE(table_bot), 8);
	
	GtkWidget * search_label;
	search_label = gtk_label_new("search");
	gtk_widget_show(search_label);
	gtk_table_attach(GTK_TABLE(table_bot), search_label, 0, 1, 0, 1, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_misc_set_alignment(GTK_MISC(search_label), 0, 0.5);
	
	search = gtk_entry_new();
	gtk_widget_show(search);
	gtk_table_attach(GTK_TABLE(table_bot), search, 1, 2, 0, 1, (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_widget_grab_focus(search);
	
	g_signal_connect((gpointer) zdict, "delete_event", G_CALLBACK(zdict_delete_event_signal), NULL);
	g_signal_connect((gpointer) zdict, "destroy", G_CALLBACK(zdict_destroy_signal), NULL);
	g_signal_connect((gpointer) about_button, "clicked", G_CALLBACK(about_button_clicked), NULL);
	g_signal_connect((gpointer) combo, "changed", G_CALLBACK(combo_changed_signal), NULL);
	g_signal_connect((gpointer) scroll, "value-changed", G_CALLBACK(scroll_value_changed_signal), NULL);
	g_signal_connect((gpointer) search, "changed", G_CALLBACK(search_changed_signal), NULL);
	
	zdict_load();
	gtk_widget_show(zdict);
}
