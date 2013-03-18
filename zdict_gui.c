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
#include "main.h"
#include "zdict.xpm"


gboolean zdict_delete_event_signal(GtkWidget *window, GdkEvent *event, gpointer data)
{
	return zdict_unload();
}


void zdict_destroy_signal(GtkWidget *window, gpointer data)
{
	zdict_destroy();
}


gboolean about_button_clicked(GtkWidget *widget, GdkEventButton *event, gpointer data)
{
	about_button_click();

	// we handled the event
	return TRUE;
}


void combo_changed_signal(GtkComboBox *widget, gpointer data)
{
	combo_change(gtk_combo_box_get_active(widget));
}


void scroll_value_changed_signal(GtkVScrollbar *widget, gpointer data)
{
	scroll_value_change((int) gtk_range_get_value(GTK_RANGE(widget)));
}


void search_changed_signal(GtkEntry *widget, gpointer data)
{
	search_change((char *) gtk_entry_get_text(widget));
}


void zdict_create()
{
	int i;

	zdict = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(zdict), "zdict");
	gtk_window_set_resizable(GTK_WINDOW(zdict), FALSE);
	gtk_widget_set_size_request(zdict, 600, -1);

	GdkPixbuf *pixbuf;
	pixbuf = gdk_pixbuf_new_from_xpm_data((const char **) zdict_xpm);
	gtk_window_set_icon(GTK_WINDOW(zdict), pixbuf);

	GtkWidget *table;
	table = gtk_table_new(14, 3, FALSE);
	gtk_widget_show(table);
	gtk_container_add(GTK_CONTAINER(zdict), table);
	gtk_container_set_border_width(GTK_CONTAINER(table), 8);
	gtk_table_set_row_spacings(GTK_TABLE(table), 4);
	gtk_table_set_col_spacings(GTK_TABLE(table), 4);

	GtkWidget *table_top;
	table_top = gtk_table_new(1, 2, FALSE);
	gtk_widget_show(table_top);
	gtk_table_attach(GTK_TABLE(table), table_top, 0, 3, 0, 1, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 0, 0);
	gtk_table_set_row_spacings(GTK_TABLE(table_top), 8);
	gtk_table_set_col_spacings(GTK_TABLE(table_top), 8);

	GtkWidget *about_button;
	GdkPixbuf *about_pixbuf;
	GtkWidget *about_icon;
	about_button = gtk_button_new();
	about_pixbuf = gdk_pixbuf_new_from_xpm_data((const char **) zdict_xpm);
	about_icon = gtk_image_new_from_pixbuf(about_pixbuf);
	gtk_button_set_relief(GTK_BUTTON(about_button), GTK_RELIEF_NONE);
	g_object_unref(about_pixbuf);
	gtk_widget_show(about_button);
	gtk_widget_show(about_icon);
	gtk_container_add(GTK_CONTAINER(about_button), about_icon);
	gtk_table_attach(GTK_TABLE(table_top), about_button, 0, 1, 0, 1, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 0, 0);

	combo = gtk_combo_box_text_new();
	gtk_widget_show(combo);
	gtk_table_attach(GTK_TABLE(table_top), combo, 1, 2, 0, 1, (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), (GtkAttachOptions) (0), 0, 0);

	GtkWidget *hr1;
	//hr1 = gtk_hseparator_new ();
	hr1 = gtk_separator_new(GTK_ORIENTATION_HORIZONTAL);
	gtk_widget_show(hr1);
	gtk_table_attach(GTK_TABLE(table), hr1, 0, 3, 1, 2, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 0, 8);

	for (i = 0; i < 10; i++) {
		name[i] = gtk_entry_new();
		gtk_widget_show(name[i]);
		gtk_table_attach(GTK_TABLE(table), name[i], 0, 1, i + 2, i + 3, (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), (GtkAttachOptions) (0), 0, 0);
		gtk_editable_set_editable(GTK_EDITABLE(name[i]), FALSE);
		gtk_widget_set_can_focus(name[i], FALSE);

		value[i] = gtk_entry_new();
		gtk_widget_show(value[i]);
		gtk_table_attach(GTK_TABLE(table), value[i], 2, 3, i + 2, i + 3, (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), (GtkAttachOptions) (0), 0, 0);
		gtk_editable_set_editable(GTK_EDITABLE(value[i]), FALSE);
		gtk_widget_set_can_focus(value[i], FALSE);
	}

	scroll = gtk_scrollbar_new(GTK_ORIENTATION_VERTICAL, NULL);
	gtk_widget_show(scroll);
	gtk_table_attach(GTK_TABLE(table), scroll, 1, 2, 2, 12, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 0, 0);

	GtkWidget *hr2;
	hr2 = gtk_separator_new(GTK_ORIENTATION_HORIZONTAL);
	gtk_widget_show(hr2);
	gtk_table_attach(GTK_TABLE(table), hr2, 0, 3, 12, 13, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 0, 8);

	GtkWidget *table_bot;
	table_bot = gtk_table_new(1, 2, FALSE);
	gtk_widget_show(table_bot);
	gtk_table_attach(GTK_TABLE(table), table_bot, 0, 3, 13, 14, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 0, 0);
	gtk_table_set_row_spacings(GTK_TABLE(table_bot), 8);
	gtk_table_set_col_spacings(GTK_TABLE(table_bot), 8);

	GtkWidget *search_label;
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
