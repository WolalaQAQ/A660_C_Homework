//
// Created by wolala on 23-4-15.
//

#ifndef A660_C_HOMEWORK_MOVIEADDWINDOW_H
#define A660_C_HOMEWORK_MOVIEADDWINDOW_H

#include <gtk/gtk.h>

#include "movie.h"

#include "MovieManageWindow.h"

void AddMovieWindow(GtkWidget *button, gpointer data);
void on_menu_item_clicked_add_movie(GtkMenuItem *menu_item, gpointer user_data);
void on_add_movie_ok_button_clicked(GtkWidget* button, gpointer data);

#endif  // A660_C_HOMEWORK_MOVIEADDWINDOW_H
