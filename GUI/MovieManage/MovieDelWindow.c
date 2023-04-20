//
// Created by wolala on 23-4-15.
//

#include "MovieDelWindow.h"

void DeleteMovieWindow(GtkWidget *button, gpointer data) {
  Node *current_movie_list = data;
  // 创建一个新窗口和表格
  GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "删除电影");
  gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
  // 创建一个表格，用于放置标签和输入框
  GtkWidget *grid = gtk_grid_new();
  gtk_grid_set_column_spacing(GTK_GRID(grid), 5);
  gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
  gtk_container_add(GTK_CONTAINER(window), grid);
  // 创建标签和输入框，用于输入电影信息
  GtkWidget *name_label = gtk_label_new("片名:");
  GtkWidget *name_entry = gtk_entry_new();
  // 将标签和输入框添加到表格中
  gtk_grid_attach(GTK_GRID(grid), name_label, 0, 0, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), name_entry, 1, 0, 1, 1);
  // 创建“确认”按钮和“取消”按钮
  GtkWidget *ok_button = gtk_button_new_with_label("确认");
  // 将按钮添加到表格中
  gtk_grid_attach(GTK_GRID(grid), ok_button, 0, 8, 1, 1);
  // 为“确认”按钮和“取消”按钮连接回调函数
  MovieData *movie_data = g_new(MovieData, 1);
  movie_data->movie_node = current_movie_list;
  movie_data->window = window;
  g_signal_connect(ok_button, "clicked",
                   G_CALLBACK(on_del_movie_ok_button_clicked), movie_data);
  // 显示窗口和所有控件
  gtk_widget_show_all(window);
}

void on_del_movie_ok_button_clicked(GtkWidget *button, gpointer data) {
  MovieData *movie_data = data;
  // 获取输入框中的电影信息
  GtkWidget *window = movie_data->window;
  GtkWidget *grid = gtk_bin_get_child(GTK_BIN(window));
  GtkWidget *name_entry = gtk_grid_get_child_at(GTK_GRID(grid), 1, 0);
  const gchar *name = gtk_entry_get_text(GTK_ENTRY(name_entry));
  // 写入
  struct Movie *new_movie = (struct Movie *)malloc(sizeof(struct Movie));
  strcpy(new_movie->name, name);
  int index = findMovieNode(movie_data->movie_node, new_movie);
  if (index == -1) {
    // 如果没有找到指定的电影，弹出一个警告对话框
    GtkWidget *dialog = gtk_message_dialog_new(
        NULL, GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
        GTK_MESSAGE_WARNING, GTK_BUTTONS_OK, "电影不存在！");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
    free(new_movie);
    return;
  } else {
    deleteNodeByIndex(&movie_data->movie_node, index);
    overWriteMovieFile(movie_data->movie_node);
    GtkWidget *dialog = gtk_message_dialog_new(
        NULL, GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
        GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "删除成功！");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
    gtk_widget_destroy(movie_data->window);
    free(new_movie);
  }
  MovieManageWindow(NULL, NULL);
}
