//
// Created by wolala on 23-4-13.
//

#ifndef A660_C_HOMEWORK_CLOSE_EVENTS_H
#define A660_C_HOMEWORK_CLOSE_EVENTS_H

#include <gtk/gtk.h>

#include "MainWindow.h"

void on_window_close_show_main_window(GtkWidget *widget, gpointer data);
gboolean on_window_close_show_parent_window(GtkWidget *widget, GdkEvent *event, gpointer data);
void clearTableRows(GtkWidget *grid, int start_row);

#endif  // A660_C_HOMEWORK_CLOSE_EVENTS_H
