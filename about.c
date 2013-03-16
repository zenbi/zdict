//
// zdict - simple dictionary viewer
// Copyright (C) 2005 Bryan Beicker <tokiko@tokiko.net>
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


void about_dialog(GtkWidget * parent, char ** xpm, char * name, char * desc, char * copy)
{
	GtkWidget * dialog;
	dialog = gtk_dialog_new_with_buttons("about", GTK_WINDOW(parent), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_STOCK_CLOSE, GTK_RESPONSE_NONE, NULL);
	gtk_window_set_resizable(GTK_WINDOW(dialog), FALSE);
	
	GdkPixbuf * pixbuf;
	pixbuf = gdk_pixbuf_new_from_xpm_data((const char **) xpm);
	
	GtkWidget * table;
	table = gtk_table_new(3, 2, FALSE);
	gtk_table_set_row_spacings(GTK_TABLE(table), 2);
	gtk_table_set_col_spacings(GTK_TABLE(table), 4);
	gtk_container_set_border_width(GTK_CONTAINER(table), 12);
	gtk_widget_show(table);

	GtkWidget * icon;
	icon = gtk_image_new_from_pixbuf(pixbuf);
	gdk_pixbuf_unref(pixbuf);
	gtk_misc_set_alignment(GTK_MISC(icon), 1, 0.5);
	gtk_widget_show(icon);
	gtk_table_attach(GTK_TABLE(table), icon, 0, 1, 0, 1, (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 4, 2);
	
	gchar * tmp;
	GtkWidget * version;
	version = gtk_label_new(NULL);
	tmp = g_strdup_printf("<span weight=\"bold\" size=\"larger\">%s</span>", name);
	gtk_label_set_text(GTK_LABEL(version), tmp);
	g_free(tmp);
	gtk_misc_set_alignment(GTK_MISC(version), 0, 0.5);
	gtk_label_set_use_markup(GTK_LABEL(version), TRUE);
	gtk_widget_show(version);
	gtk_table_attach(GTK_TABLE(table), version, 1, 2, 0, 1, (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	
	GtkWidget * description;
	description = gtk_label_new(desc);
	gtk_widget_show(description);
	gtk_table_attach(GTK_TABLE(table), description, 0, 2, 1, 2, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	
	GtkWidget * copyright;
	tmp = g_strdup_printf("<span size=\"smaller\">%s</span>", copy);
	copyright = gtk_label_new(tmp);
	g_free(tmp);
	gtk_label_set_use_markup(GTK_LABEL(copyright), TRUE);
	gtk_widget_show(copyright);
	gtk_table_attach(GTK_TABLE(table), copyright, 0, 2, 2, 3, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	
	gtk_container_add(GTK_CONTAINER (GTK_DIALOG(dialog)->vbox), table);
	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
}
