//
// Created by wolala on 23-4-13.
//
#include "CloseEvents.h"


//关闭窗口并打开主窗口
void on_window_close_show_main_window(GtkWidget *widget, gpointer data) {
  gtk_widget_destroy(widget);
  MainWindow(NULL, NULL);
}

//关闭窗口时恢复显示父窗口
gboolean on_window_close_show_parent_window(GtkWidget *widget, GdkEvent *event, gpointer data) {
  GtkWidget *window_parent = (GtkWidget *)data;
  // 销毁下级窗口
  gtk_widget_destroy(widget);
  // 显示上级窗口
  gtk_widget_show_all(window_parent);
  // 阻止默认的 "delete-event" 处理
  return TRUE;
}