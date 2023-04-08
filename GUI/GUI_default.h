//登录界面用到的子函数和一些临时测试用的函数
#ifndef GUI_DEFAULT_C
#define GUI_DEFAULT_C

#include <gtk/gtk.h>

#include "button_floor1.h"
#include "button_floor2.h"
#include "button_floor3.h"

void on_window_close(GtkWidget *widget, gpointer data);

void on_button_clicked_login_text(GtkWidget *widget, gpointer data);
void on_button_clicked_login();
void on_button_clicked_register_();
void on_button_clicked_register();


void on_button_clicked_movie(GtkWidget *button, gpointer data);
void on_button_clicked_guest(GtkWidget *button, gpointer data);
void on_button_clicked_sell(GtkWidget *button, gpointer data);
void Administor(GtkWidget *button, gpointer data);

#endif  // GUI_DEFAULT_C