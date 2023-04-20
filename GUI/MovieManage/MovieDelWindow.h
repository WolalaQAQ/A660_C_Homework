//
// Created by wolala on 23-4-15.
//

#ifndef A660_C_HOMEWORK_MOVIEDELWINDOW_H
#define A660_C_HOMEWORK_MOVIEDELWINDOW_H

#include <gtk/gtk.h>

#include "DataStruct.h"
#include "movie.h"
#include "MovieManageWindow.h"

void DeleteMovieWindow(GtkWidget *button, gpointer data);

void on_del_movie_ok_button_clicked(GtkWidget* button, gpointer data);

#endif  // A660_C_HOMEWORK_MOVIEDELWINDOW_H
