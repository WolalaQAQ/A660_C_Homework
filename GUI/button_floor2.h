// 该头文件用于存放第二级窗口界面的回调函数
#ifndef BUTTON_FLOOR2_C//
#define BUTTON_FLOOR2_C

#include <gtk/gtk.h>

#include "button_floor3.h"
#include "movie.h"
#include "users.h"

void on_button_clicked_movie_manager(GtkWidget* button, gpointer data);
void on_button_clicked_movie_times_manager(GtkWidget* button, gpointer data);
void on_button_clicked_guest_button1(GtkWidget* button, gpointer data);
void on_button_clicked_guest_button2(GtkWidget* button, gpointer data);
void on_button_clicked_sell_button1(GtkWidget* button, gpointer data);
void on_button_clicked_sell_button2(GtkWidget* button, gpointer data);
void on_button_clicked_sell_button3(GtkWidget* button, gpointer data);

#endif  // BUTTON_FLOOR2_C