//
// Created by wolala on 23-4-15.
//

#include "MovieEditWindow.h"

void EditMovieWindow(GtkWidget *button, gpointer data) {
  Node* movie_list = data;
  // 创建一个新窗口和表格
  GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "修改电影");
  gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
  // 创建一个表格，用于放置标签和输入框
  GtkWidget *grid = gtk_grid_new();
  gtk_grid_set_column_spacing(GTK_GRID(grid), 5);
  gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
  gtk_container_add(GTK_CONTAINER(window), grid);
  // 创建标签和输入框，用于输入电影信息
  GtkWidget *name_label = gtk_label_new("片名:");
  GtkWidget *name_entry = gtk_entry_new();
  GtkWidget *year_label = gtk_label_new("上映年份:");
  GtkWidget *year_entry = gtk_entry_new();
  GtkWidget *director_label = gtk_label_new("导演:");
  GtkWidget *director_entry = gtk_entry_new();
  GtkWidget *actor_label = gtk_label_new("主演:");
  GtkWidget *actor_entry = gtk_entry_new();
  GtkWidget *country_label = gtk_label_new("国家:");
  GtkWidget *country_entry = gtk_entry_new();
  GtkWidget *language_label = gtk_label_new("语言:");
  GtkWidget *language_entry = gtk_entry_new();
  GtkWidget *introduction_label = gtk_label_new("简介:");
  GtkWidget *introduction_entry = gtk_entry_new();
  GtkWidget *score_label = gtk_label_new("评分:");
  GtkWidget *score_entry = gtk_entry_new();
  // 将标签和输入框添加到表格中
  gtk_grid_attach(GTK_GRID(grid), name_label, 0, 0, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), name_entry, 1, 0, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), year_label, 0, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), year_entry, 1, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), director_label, 0, 2, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), director_entry, 1, 2, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), actor_label, 0, 3, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), actor_entry, 1, 3, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), country_label, 0, 4, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), country_entry, 1, 4, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), language_label, 0, 5, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), language_entry, 1, 5, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), introduction_label, 0, 6, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), introduction_entry, 1, 6, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), score_label, 0, 7, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), score_entry, 1, 7, 1, 1);
  // 创建“确认”按钮和“取消”按钮
  GtkWidget *ok_button = gtk_button_new_with_label("确认");
  // 将按钮添加到表格中
  gtk_grid_attach(GTK_GRID(grid), ok_button, 0, 8, 1, 1);
  // 为“确认”按钮连接回调函数
  g_signal_connect(ok_button, "clicked",
                   G_CALLBACK(on_edit_movie_ok_button_clicked), window);
  // 显示窗口和所有控件
  gtk_widget_show_all(window);
}

void on_edit_movie_ok_button_clicked(GtkWidget* button, gpointer data) {
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