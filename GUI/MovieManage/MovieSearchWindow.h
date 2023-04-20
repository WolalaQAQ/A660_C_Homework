//
// Created by wolala on 23-4-15.
//

#ifndef A660_C_HOMEWORK_MOVIESEARCHWINDOW_H
#define A660_C_HOMEWORK_MOVIESEARCHWINDOW_H

#include <gtk/gtk.h>

#include "DataStruct.h"
#include "CloseEvents.h"
#include "movie.h"

void SearchMovieWindow(GtkWidget *button, gpointer data);

void on_search_movie_ok_button_clicked(GtkWidget* button, gpointer data);

#endif  // A660_C_HOMEWORK_MOVIESEARCHWINDOW_H
