//
// Created by wolala on 23-4-15.
//

#ifndef A660_C_HOMEWORK_MOVIEEDITWINDOW_H
#define A660_C_HOMEWORK_MOVIEEDITWINDOW_H

#include <gtk/gtk.h>

#include "DataStruct.h"
#include "movie.h"

void EditMovieWindow(GtkWidget *button, gpointer data);

void on_edit_movie_ok_button_clicked(GtkWidget* button, gpointer data);
#endif  // A660_C_HOMEWORK_MOVIEEDITWINDOW_H
