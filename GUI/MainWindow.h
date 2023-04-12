//
// Created by wolala on 23-4-13.
//
#ifndef A660_C_HOMEWORK_MAINWINDOW_H
#define A660_C_HOMEWORK_MAINWINDOW_H

#include <gtk/gtk.h>

#include "DataStruct.h"
#include "CloseEvents.h"
#include "LoginRegisterWindow.h"

void MainWindow(GtkWidget *button, gpointer data);

void on_button_clicked_login(GtkWidget *widget, gpointer data);
void on_button_clicked_register(GtkWidget *widget, gpointer data);

#endif  // A660_C_HOMEWORK_MAINWINDOW_H
