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

// 清空表格中的所有行
void clearTableRows(GtkWidget *grid, int start_row) {
  // 从指定的行开始，遍历所有行和列，将每个单元格中的控件都从表格中移除
  int num_rows = 0;
  for (int row = start_row; ; row++) {
    if (gtk_grid_get_child_at(GTK_GRID(grid), 0, row) == NULL) {
      num_rows = row - start_row;
      break;
    }
  }
  for (int row = start_row; row < start_row + num_rows; row++) {
    for (int col = 0; ; col++) {
      GtkWidget *widget = gtk_grid_get_child_at(GTK_GRID(grid), col, row);
      if (widget != NULL) {
        gtk_container_remove(GTK_CONTAINER(grid), widget);
      }
      else {
        break;
      }
    }
  }
}

