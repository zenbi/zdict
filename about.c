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
#include "book_48.h"


void about_dialog(GtkWidget *parent)
{
	GtkWidget *win_about;
	GdkPixbuf *pix_icon;

	win_about = gtk_about_dialog_new();
	pix_icon = gdk_pixbuf_new_from_inline(-1, book_48, FALSE, NULL);
	gtk_about_dialog_set_program_name(GTK_ABOUT_DIALOG(win_about), "zdict");
	gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(win_about), VERSION);
	gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(win_about), COPYRIGHT);
	gtk_about_dialog_set_license_type(GTK_ABOUT_DIALOG(win_about), GTK_LICENSE_GPL_3_0);
	gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(win_about), WEBSITE);
	gtk_about_dialog_set_website_label(GTK_ABOUT_DIALOG(win_about), WEBSITE);
	gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(win_about), DESCRIPTION);
	gtk_about_dialog_set_logo(GTK_ABOUT_DIALOG(win_about), pix_icon);
	gtk_dialog_run(GTK_DIALOG(win_about));
	gtk_widget_destroy(win_about);
}
