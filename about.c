//
// zdict - simple dictionary viewer
// Copyright (C) 2004-2017 Bryan Beicker <bryan@beicker.com>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#include <gtk/gtk.h>
#include "main.h"


void about_dialog(GtkWidget *parent)
{
	GtkWidget *win_about;
	GdkPixbuf *pix_icon;

	win_about = gtk_about_dialog_new();
	gtk_window_set_transient_for(GTK_WINDOW(win_about), GTK_WINDOW(parent));
	pix_icon = gdk_pixbuf_new_from_resource("/org/zwin/zdict/book-48.png", NULL);
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
