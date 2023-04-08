// 该头文件用于存放第一级窗口界面的回调函数
#ifndef BUTTON_FLOOR1_C
#define BUTTON_FLOOR1_C
#include <gtk/gtk.h>
#include "button_floor2.h"
#include "button_floor3.h"

void on_button_clicked_movie(GtkWidget *button, gpointer data);
void on_button_clicked_guest(GtkWidget *button, gpointer data);
void on_button_clicked_sell(GtkWidget *button, gpointer data);
void Administor();

#endif //BUTTON_FLOOR1_C