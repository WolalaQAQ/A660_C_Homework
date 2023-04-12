//
// Created by wolala on 23-4-13.
//

#ifndef A660_C_HOMEWORK_CLOSEEVENTS_H
#define A660_C_HOMEWORK_CLOSEEVENTS_H

#include <gtk/gtk.h>

#include "MainWindow.h"

void on_window_close_show_main_window(GtkWidget *widget, gpointer data);
gboolean on_window_close_show_parent_window(GtkWidget *widget, GdkEvent *event, gpointer data);

#endif  // A660_C_HOMEWORK_CLOSEEVENTS_H
