/*
 *  (GLABELS) Label and Business Card Creation program for GNOME
 *
 *  commands.c:  GLabels commands module
 *
 *  Copyright (C) 2001-2003  Jim Evins <evins@snaught.com>.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
 */

#include <config.h>

#include <gtk/gtk.h>
#include <libgnome/libgnome.h>
#include <libgnomeui/libgnomeui.h>

#include "commands.h"
#include "view.h"
#include "file.h"
#include "template-designer.h"
#include "print-dialog.h"
#include "prefs.h"
#include "prefs-dialog.h"
#include "debug.h"

#define LOGO_PIXMAP gnome_program_locate_file (NULL,\
					 GNOME_FILE_DOMAIN_APP_PIXMAP,\
					 "glabels/glabels-about-logo.png",\
					 FALSE, NULL)


/****************************************************************************/
/* File->New command.                                                       */
/****************************************************************************/
void 
gl_cmd_file_new (BonoboUIComponent *uic,
		 gpointer           user_data,
		 const gchar       *verbname)
{
	glWindow *window = GL_WINDOW (user_data);

	gl_debug (DEBUG_COMMANDS, "");
	
	gl_file_new (GTK_WINDOW(window));
}

/****************************************************************************/
/* File->Properties command.                                                */
/****************************************************************************/
void 
gl_cmd_file_properties (BonoboUIComponent *uic,
			gpointer           user_data,
			const gchar       *verbname)
{
	glWindow *window = GL_WINDOW (user_data);

	gl_debug (DEBUG_COMMANDS, "");
	
	gl_file_properties (GL_VIEW(window->view)->label, GTK_WINDOW(window));
}

/****************************************************************************/
/* File->Template Designer command.                                         */
/****************************************************************************/
void
gl_cmd_file_template_designer (BonoboUIComponent *uic,
			       gpointer           user_data,
			       const gchar       *verbname)
{
	glWindow  *window = GL_WINDOW (user_data);
	GtkWidget *dialog;

	gl_debug (DEBUG_COMMANDS, "");

	g_return_if_fail (window && GL_IS_WINDOW(window));

	dialog = gl_template_designer_new (GTK_WINDOW(window));

	gtk_widget_show (dialog);
}

/****************************************************************************/
/* File->Open command.                                                      */
/****************************************************************************/
void 
gl_cmd_file_open (BonoboUIComponent *uic,
		  gpointer           user_data,
		  const gchar       *verbname)
{
	glWindow *window = GL_WINDOW (user_data);

	gl_debug (DEBUG_COMMANDS, "");

	g_return_if_fail (window && GL_IS_WINDOW(window));

	gl_file_open (GTK_WINDOW(window));
}

/****************************************************************************/
/* File->Save command.                                                      */
/****************************************************************************/
void 
gl_cmd_file_save (BonoboUIComponent *uic,
		  gpointer           user_data,
		  const gchar       *verbname)
{
	glWindow *window = GL_WINDOW (user_data);

	gl_debug (DEBUG_COMMANDS, "");

	g_return_if_fail (window && GL_IS_WINDOW(window));

	gl_file_save (GL_VIEW(window->view)->label, GTK_WINDOW(window));
}

/****************************************************************************/
/* File->Save_as command.                                                   */
/****************************************************************************/
void 
gl_cmd_file_save_as (BonoboUIComponent *uic,
		     gpointer           user_data,
		     const gchar       *verbname)
{
	glWindow *window = GL_WINDOW (user_data);

	gl_debug (DEBUG_COMMANDS, "");

	g_return_if_fail (window && GL_IS_WINDOW(window));

	gl_file_save_as (GL_VIEW(window->view)->label, GTK_WINDOW(window));
}

/****************************************************************************/
/* File->Print command.                                                     */
/****************************************************************************/
void
gl_cmd_file_print (BonoboUIComponent *uic,
		   gpointer           user_data,
		   const gchar       *verbname)
{
	glWindow *window = GL_WINDOW (user_data);

	gl_debug (DEBUG_COMMANDS, "");

	g_return_if_fail (window && GL_IS_WINDOW(window));

	if (GL_VIEW(window->view)->print_dialog) {

		gtk_window_present (GTK_WINDOW(GL_VIEW(window->view)->print_dialog));

	} else {

		GL_VIEW(window->view)->print_dialog =
			gl_print_dialog_new (GL_VIEW(window->view)->label,
					     BONOBO_WINDOW(window));

		gtk_widget_show (GL_VIEW(window->view)->print_dialog);
	}

}

/****************************************************************************/
/* File->Close command.                                                     */
/****************************************************************************/
void 
gl_cmd_file_close (BonoboUIComponent *uic,
		   gpointer           user_data,
		   const gchar       *verbname)
{
	glWindow *window = GL_WINDOW (user_data);

	gl_debug (DEBUG_COMMANDS, "");

	g_return_if_fail (window && GL_IS_WINDOW(window));

	gl_file_close (window);
}

/****************************************************************************/
/* File->Exit command.                                                      */
/****************************************************************************/
void 
gl_cmd_file_exit (BonoboUIComponent *uic,
		  gpointer           user_data,
		  const gchar       *verbname)
{
	glWindow *window = GL_WINDOW (user_data);

	gl_debug (DEBUG_COMMANDS, "");

	g_return_if_fail (window && GL_IS_WINDOW(window));

	gl_file_exit ();
}


/****************************************************************************/
/* Edit->Cut command.                                                       */
/****************************************************************************/
void 
gl_cmd_edit_cut (BonoboUIComponent *uic,
		 gpointer           user_data,
		 const gchar       *verbname)
{
	glWindow *window = GL_WINDOW (user_data);

	gl_debug (DEBUG_COMMANDS, "");

	g_return_if_fail (window && GL_IS_WINDOW(window));

	gl_view_cut (GL_VIEW(window->view)); 
}

/****************************************************************************/
/* Edit->Copy command.                                                      */
/****************************************************************************/
void 
gl_cmd_edit_copy (BonoboUIComponent *uic,
		  gpointer           user_data,
		  const gchar       *verbname)
{
	glWindow *window = GL_WINDOW (user_data);

	gl_debug (DEBUG_COMMANDS, "");

	g_return_if_fail (window && GL_IS_WINDOW(window));

	gl_view_copy (GL_VIEW(window->view)); 
}

/****************************************************************************/
/* Edit->Paste command.                                                     */
/****************************************************************************/
void 
gl_cmd_edit_paste (BonoboUIComponent *uic,
		   gpointer           user_data,
		   const gchar       *verbname)
{
	glWindow *window = GL_WINDOW (user_data);

	gl_debug (DEBUG_COMMANDS, "");

	g_return_if_fail (window && GL_IS_WINDOW(window));

	gl_view_paste (GL_VIEW(window->view)); 
}


/****************************************************************************/
/* Edit->Delete command.                                                    */
/****************************************************************************/
void 
gl_cmd_edit_delete (BonoboUIComponent *uic,
		    gpointer           user_data,
		    const gchar       *verbname)
{
	glWindow *window = GL_WINDOW (user_data);

	gl_debug (DEBUG_COMMANDS, "");

	g_return_if_fail (window && GL_IS_WINDOW(window));

	gl_view_delete_selection (GL_VIEW(window->view)); 
}


/****************************************************************************/
/* Edit->Select_all command.                                                */
/****************************************************************************/
void
gl_cmd_edit_select_all (BonoboUIComponent *uic,
			gpointer           user_data,
			const gchar       *verbname)
{
	glWindow *window = GL_WINDOW (user_data);

	gl_debug (DEBUG_COMMANDS, "");

	g_return_if_fail (window && GL_IS_WINDOW(window));

	gl_view_select_all (GL_VIEW(window->view)); 
}

/****************************************************************************/
/* Edit->Select_all command.                                                */
/****************************************************************************/
void
gl_cmd_edit_unselect_all (BonoboUIComponent *uic,
			  gpointer           user_data,
			  const gchar       *verbname)
{
	glWindow *window = GL_WINDOW (user_data);

	gl_debug (DEBUG_COMMANDS, "");

	g_return_if_fail (window && GL_IS_WINDOW(window));

	gl_view_unselect_all (GL_VIEW(window->view)); 
}

/****************************************************************************/
/* Settings->Preferences command.                                           */
/****************************************************************************/
void
gl_cmd_settings_preferences (BonoboUIComponent *uic,
			     gpointer           user_data,
			     const gchar       *verbname)
{
	glWindow *window = GL_WINDOW (user_data);
	static GtkWidget *dlg = NULL;

	gl_debug (DEBUG_COMMANDS, "");

	g_return_if_fail (window && GL_IS_WINDOW(window));

	if (dlg != NULL)
	{
		gtk_window_present (GTK_WINDOW (dlg));
		gtk_window_set_transient_for (GTK_WINDOW (dlg),	
					      GTK_WINDOW(window));

		return;
	}
		
	dlg = gl_prefs_dialog_new (GTK_WINDOW(window));

	g_signal_connect (G_OBJECT (dlg), "destroy",
			  G_CALLBACK (gtk_widget_destroyed), &dlg);
	
	gtk_widget_show (dlg);
}

/****************************************************************************/
/* Help->Contents command.                                                  */
/****************************************************************************/
void 
gl_cmd_help_contents (BonoboUIComponent *uic,
		      gpointer           user_data,
		      const gchar       *verbname)
{
	glWindow *window = GL_WINDOW (user_data);
	GError *error = NULL;

	gl_debug (DEBUG_COMMANDS, "");

	g_return_if_fail (window && GL_IS_WINDOW(window));

	gnome_help_display_with_doc_id (NULL, NULL, "glabels.xml", NULL, &error);
	
	if (error != NULL)
	{
		g_warning (error->message);

		g_error_free (error);
	}
}

/****************************************************************************/
/* Help->About command.                                                     */
/****************************************************************************/
void 
gl_cmd_help_about (BonoboUIComponent *uic,
		   gpointer           user_data,
		   const gchar       *verbname)
{
	glWindow *window = GL_WINDOW (user_data);
	static GtkWidget *about = NULL;
	GdkPixbuf        *pixbuf = NULL;
	
	gchar *copy_text = "Copyright 2001-2003 Jim Evins";
	gchar *about_text =
	    _("A label and business card creation program for GNOME.\n"
	      " \n"
	      "Glabels is free software; you can redistribute it and/or modify it "
	      "under the terms of the GNU General Public License as published by "
	      "the Free Software Foundation; either version 2 of the License, or "
	      "(at your option) any later version.\n" " \n"
	      "This program is distributed in the hope that it will be useful, but "
	      "WITHOUT ANY WARRANTY; without even the implied warranty of "
	      "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU "
	      "General Public License for more details.\n");

	gchar *authors[] = {
		"Jim Evins <evins@snaught.com>",
		" ",
		_("See the file AUTHORS for additional credits,"),
		_("or visit http://glabels.sourceforge.net/"),
		NULL
	};
	
	gchar *documenters[] = {
		"",
		NULL
	};

	gchar *translator_credits = _(" ");

	gl_debug (DEBUG_COMMANDS, "");

	g_return_if_fail (window && GL_IS_WINDOW(window));

	if (about != NULL)
	{
		gdk_window_show (about->window);
		gdk_window_raise (about->window);
		return;
	}
	
	pixbuf = gdk_pixbuf_new_from_file ( LOGO_PIXMAP, NULL);

	about = gnome_about_new (_("glabels"), VERSION,
				 copy_text,
				 about_text,
				(const char **)authors,
				(const char **)NULL,
				(const char *)NULL,
				pixbuf);

	gtk_window_set_transient_for (GTK_WINDOW (about),
				      GTK_WINDOW (window));

	gtk_window_set_destroy_with_parent (GTK_WINDOW (about), TRUE);

	if (pixbuf != NULL)
		g_object_unref (pixbuf);
	
	g_signal_connect (G_OBJECT (about), "destroy",
			  G_CALLBACK (gtk_widget_destroyed), &about);
	
	gtk_widget_show (about);
}


