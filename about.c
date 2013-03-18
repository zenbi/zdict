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


void about_dialog(GtkWidget * parent, char ** xpm, char * name, char * desc, char * copy)
{
	GtkWidget * dialog;

	dialog = gtk_about_dialog_new();
	gtk_about_dialog_set_program_name(GTK_ABOUT_DIALOG(dialog), "zdict");
	gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(dialog), VERSION);
	gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(dialog), COPYRIGHT);
	gtk_about_dialog_set_license_type(GTK_ABOUT_DIALOG(dialog), GTK_LICENSE_GPL_3_0);
	gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(dialog), WEBSITE);
	gtk_about_dialog_set_website_label(GTK_ABOUT_DIALOG(dialog), WEBSITE);
	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
}
