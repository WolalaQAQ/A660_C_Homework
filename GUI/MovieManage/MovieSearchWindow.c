//
// Created by wolala on 23-4-15.
//

#include "MovieSearchWindow.h"

void SearchMovieWindow(GtkWidget *button, gpointer data) {
  // 获取电影信息链表
  MovieData *movie_data = (MovieData *)data;
  Node *current_movie_node = movie_data->movie_node;
  // 创建新窗口
  GtkWidget *search_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(search_window), "搜索电影");
  gtk_window_set_default_size(GTK_WINDOW(search_window), 400, 300);
  // 加载样式表
  GtkCssProvider *provider = gtk_css_provider_new();
  gtk_css_provider_load_from_path(provider, "./css/movie_table.css", NULL);
  GtkStyleContext *context = gtk_widget_get_style_context(search_window);
  gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
  g_object_unref(provider);
  // 创建搜索框和按钮
  GtkWidget *search_entry = gtk_search_entry_new();
  GtkWidget *search_button = gtk_button_new_with_label("搜索");
  // 创建表格用于显示搜索结果
  GtkWidget *grid = gtk_grid_new();
  gtk_grid_set_column_spacing(GTK_GRID(grid), 5);
  gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
  // 添加表头
  gtk_grid_attach(GTK_GRID(grid), gtk_label_new("片名"), 0, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), gtk_label_new("上映年份"), 1, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), gtk_label_new("导演"), 2, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), gtk_label_new("主演"), 3, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), gtk_label_new("国家"), 4, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), gtk_label_new("语言"), 5, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), gtk_label_new("简介"), 6, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), gtk_label_new("评分"), 7, 1, 1, 1);
  // 在搜索窗口中显示搜索框和搜索按钮
  gtk_grid_attach(GTK_GRID(grid), search_entry, 0, 0, 7, 1);
  gtk_grid_attach(GTK_GRID(grid), search_button, 7, 0, 1, 1);
  SearchData *search_data = g_new(SearchData, 1);
  search_data->search_entry = search_entry;
  search_data->grid = grid;
  search_data->head = current_movie_node;
  g_signal_connect(search_button, "clicked", G_CALLBACK(on_search_movie_ok_button_clicked), search_data);
  // 创建一个可滚动的窗口，将表格添加到其中
  GtkWidget *scroll_window = gtk_scrolled_window_new(NULL, NULL);
  gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scroll_window), GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);
  gtk_container_add(GTK_CONTAINER(scroll_window), grid);
  gtk_container_add(GTK_CONTAINER(search_window), scroll_window);
  // 显示窗口和所有控件
  gtk_widget_show_all(search_window);
}

void on_search_movie_ok_button_clicked(GtkWidget *button, gpointer data) {
  SearchData *search_data = data;
  Node* current_movie_node = search_data->head;
  GtkWidget *search_entry = search_data->search_entry;
  GtkWidget *grid = search_data->grid;
  const gchar *search_text = gtk_entry_get_text(GTK_ENTRY(search_entry));
  // 清空表格中的数据
  clearTableRows(grid, 2);
  // 搜索文本不为空，继续执行代码
  int row = 2;
  // 循环遍历电影信息链表
  while (current_movie_node != NULL) {
    struct Movie *current_movie = current_movie_node->data;
    // 判断电影名称是否包含搜索文本
    if (g_strstr_len(current_movie->name, -1, search_text) != NULL) {
      // 电影名称包含搜索文本，创建框架和标签，用于显示电影信息
      GtkWidget *name_frame = gtk_frame_new(NULL);
      GtkWidget *year_frame = gtk_frame_new(NULL);
      GtkWidget *director_frame = gtk_frame_new(NULL);
      GtkWidget *actor_frame = gtk_frame_new(NULL);
      GtkWidget *country_frame = gtk_frame_new(NULL);
      GtkWidget *language_frame = gtk_frame_new(NULL);
      GtkWidget *introduction_frame = gtk_frame_new(NULL);
      GtkWidget *score_frame = gtk_frame_new(NULL);

      GtkWidget *name = gtk_label_new(current_movie->name);
      GtkWidget *year = gtk_label_new(g_strdup_printf("%d", current_movie->year));
      GtkWidget *director = gtk_label_new(current_movie->director);
      GtkWidget *actor = gtk_label_new(current_movie->actor);
      GtkWidget *country = gtk_label_new(current_movie->country);
      GtkWidget *language = gtk_label_new(current_movie->language);
      GtkWidget *introduction = gtk_label_new(current_movie->introduction);
      GtkWidget *score = gtk_label_new(g_strdup_printf("%.1f", current_movie->score));
      // 将标签添加到框架中
      gtk_container_add(GTK_CONTAINER(name_frame), name);
      gtk_container_add(GTK_CONTAINER(year_frame), year);
      gtk_container_add(GTK_CONTAINER(director_frame), director);
      gtk_container_add(GTK_CONTAINER(actor_frame), actor);
      gtk_container_add(GTK_CONTAINER(country_frame), country);
      gtk_container_add(GTK_CONTAINER(language_frame), language);
      gtk_container_add(GTK_CONTAINER(introduction_frame), introduction);
      gtk_container_add(GTK_CONTAINER(score_frame), score);
      // 设置框架的大小和位置
      gtk_widget_set_size_request(name_frame, 100, 30);
      gtk_widget_set_size_request(year_frame, 50, 30);
      gtk_widget_set_size_request(director_frame, 150, 30);
      gtk_widget_set_size_request(actor_frame, 150, 30);
      gtk_widget_set_size_request(country_frame, 80, 30);
      gtk_widget_set_size_request(language_frame, 80, 30);
      gtk_widget_set_size_request(introduction_frame, 200, 30);
      gtk_widget_set_size_request(score_frame, 50, 30);
      // 将框架添加到表格中
      gtk_grid_attach(GTK_GRID(grid), name_frame, 0, row, 1, 1);
      gtk_grid_attach(GTK_GRID(grid), year_frame, 1, row, 1, 1);
      gtk_grid_attach(GTK_GRID(grid), director_frame, 2, row, 1, 1);
      gtk_grid_attach(GTK_GRID(grid), actor_frame, 3, row, 1, 1);
      gtk_grid_attach(GTK_GRID(grid), country_frame, 4, row, 1, 1);
      gtk_grid_attach(GTK_GRID(grid), language_frame, 5, row, 1, 1);
      gtk_grid_attach(GTK_GRID(grid), introduction_frame, 6, row, 1, 1);
      gtk_grid_attach(GTK_GRID(grid), score_frame, 7, row, 1, 1);
      // 将行号加 1
      row++;
    }
    // 移动到下一个节点
    current_movie_node = current_movie_node->next;
  }
  // 显示表格和所有控件
  gtk_widget_show_all(grid);
}