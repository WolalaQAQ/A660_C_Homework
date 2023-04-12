//
// Created by wolala on 23-4-13.
//

#ifndef A660_C_HOMEWORK_LOGINREGISTERWINDOW_H
#define A660_C_HOMEWORK_LOGINREGISTERWINDOW_H

#include <gtk/gtk.h>

#include "DataStruct.h"
#include "CloseEvents.h"
#include "ManageWindow.h"
#include "users.h"

void LoginWindow(GtkWidget *button, gpointer data);
void RegisterWindow(GtkWidget *button, gpointer data);

void on_button_clicked_login_confirm(GtkWidget *widget, LoginData *data);
void on_button_clicked_register_confirm(GtkWidget *widget, RegistrationData *data);

#endif  // A660_C_HOMEWORK_LOGINREGISTERWINDOW_H
