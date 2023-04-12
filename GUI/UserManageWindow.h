//
// Created by wolala on 23-4-13.
//

#ifndef A660_C_HOMEWORK_MAIN_USER_MANAGE_WINDOW_H
#define A660_C_HOMEWORK_MAIN_USER_MANAGE_WINDOW_H

#include <gtk/gtk.h>

#include "users.h"

void MainUserManageWindow(GtkWidget *button, gpointer data);

void on_button_clicked_user_button1(GtkWidget* button, gpointer data);
void on_button_clicked_user_button2(GtkWidget* button, gpointer data);

#endif  // A660_C_HOMEWORK_MAIN_USER_MANAGE_WINDOW_H
