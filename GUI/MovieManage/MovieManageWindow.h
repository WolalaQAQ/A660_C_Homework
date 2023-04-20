//
// Created by wolala on 23-4-13.
//

#ifndef A660_C_HOMEWORK_MAIN_MOVIE_MANAGE_WINDOW_H
#define A660_C_HOMEWORK_MAIN_MOVIE_MANAGE_WINDOW_H

#include <gtk/gtk.h>

#include "DataStruct.h"
#include "CloseEvents.h"
#include "movie.h"

#include "MovieAddWindow.h"
#include "MovieDelWindow.h"
#include "MovieSearchWindow.h"
#include "MovieEditWindow.h"

void MainMovieManageWindow(GtkWidget *button, gpointer data);

void MovieManageWindow(GtkWidget *button, gpointer data);
void MovieTimesManageWindow(GtkWidget *button, gpointer data);
void TicketManageWindow(GtkWidget *button, gpointer data);

void refreshMovieTable(GtkWidget *button, gpointer data);
void on_sort_year_button_clicked(GtkWidget *button, gpointer data);

void on_menu_item_clicked_add_movie(GtkMenuItem *menu_item, gpointer user_data);
void on_menu_item_clicked_delete_movie(GtkMenuItem *menu_item, gpointer user_data);
void on_menu_item_clicked_edit_movie(GtkMenuItem *menu_item, gpointer user_data);
void on_menu_item_clicked_search_movie(GtkMenuItem *menu_item, gpointer user_data);

#endif  // A660_C_HOMEWORK_MAIN_MOVIE_MANAGE_WINDOW_H
