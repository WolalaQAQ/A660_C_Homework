//
// Created by wolala on 23-4-15.
//
#include "MovieAddWindow.h"

void AddMovieWindow(GtkWidget *button, gpointer data) {
  // 创建一个新窗口和表格
  GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "添加电影");
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
                   G_CALLBACK(on_add_movie_ok_button_clicked), window);
  // 显示窗口和所有控件
  gtk_widget_show_all(window);
}

void on_add_movie_ok_button_clicked(GtkWidget *button, gpointer data) {
  // 获取输入框中的电影信息
  GtkWidget *window = data;
  GtkWidget *grid = gtk_bin_get_child(GTK_BIN(window));
  GtkWidget *name_entry = gtk_grid_get_child_at(GTK_GRID(grid), 1, 0);
  GtkWidget *year_entry = gtk_grid_get_child_at(GTK_GRID(grid), 1, 1);
  GtkWidget *director_entry = gtk_grid_get_child_at(GTK_GRID(grid), 1, 2);
  GtkWidget *actor_entry = gtk_grid_get_child_at(GTK_GRID(grid), 1, 3);
  GtkWidget *country_entry = gtk_grid_get_child_at(GTK_GRID(grid), 1, 4);
  GtkWidget *language_entry = gtk_grid_get_child_at(GTK_GRID(grid), 1, 5);
  GtkWidget *introduction_entry = gtk_grid_get_child_at(GTK_GRID(grid), 1, 6);
  GtkWidget *score_entry = gtk_grid_get_child_at(GTK_GRID(grid), 1, 7);
  const gchar *name = gtk_entry_get_text(GTK_ENTRY(name_entry));
  const gchar *year = gtk_entry_get_text(GTK_ENTRY(year_entry));
  const gchar *director = gtk_entry_get_text(GTK_ENTRY(director_entry));
  const gchar *actor = gtk_entry_get_text(GTK_ENTRY(actor_entry));
  const gchar *country = gtk_entry_get_text(GTK_ENTRY(country_entry));
  const gchar *language = gtk_entry_get_text(GTK_ENTRY(language_entry));
  const gchar *introduction = gtk_entry_get_text(GTK_ENTRY(introduction_entry));
  const gchar *score = gtk_entry_get_text(GTK_ENTRY(score_entry));
  // 写入
  struct Movie *new_movie = (struct Movie *)malloc(sizeof(struct Movie));
  strcpy(new_movie->name, name);
  new_movie->year = atoi(year);
  strcpy(new_movie->director, director);
  strcpy(new_movie->actor, actor);
  strcpy(new_movie->country, country);
  strcpy(new_movie->language, language);
  strcpy(new_movie->introduction, introduction);
  new_movie->score = atof(score);
  writeMovieFile(new_movie);
  // 关闭窗口
  gtk_widget_destroy(window);
  MovieManageWindow(NULL, NULL);
}