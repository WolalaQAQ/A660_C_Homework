//
// Created by wolala on 23-4-8.
//
#include "button_floor2.h"

void on_button_clicked_movie_manager(GtkWidget* button, gpointer data) {
  // 创建表格
  GtkWidget *grid = gtk_grid_new();
  gtk_grid_set_column_spacing(GTK_GRID(grid), 5);
  gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
  // 添加表头
  gtk_grid_attach(GTK_GRID(grid), gtk_label_new("片名"), 0, 0, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), gtk_label_new("上映年份"), 1, 0, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), gtk_label_new("导演"), 2, 0, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), gtk_label_new("主演"), 3, 0, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), gtk_label_new("国家"), 4, 0, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), gtk_label_new("语言"), 5, 0, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), gtk_label_new("简介"), 6, 0, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), gtk_label_new("评分"), 7, 0, 1, 1);
  // 获取电影信息链表
  FILE* current_movie_data = readMovieFile();
  Node* current_movie_node = getMovieList(current_movie_data);
  struct Movie* current_movie = (struct Movie*)current_movie_node->data;
  int row = 1;
  // 循环遍历电影信息链表
  while (current_movie_node != NULL) {
    // 创建框架和标签，用于显示电影信息
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
    // 移动到下一个节点
    current_movie_node = current_movie_node->next;
  }
  // 创建一个可滚动的窗口，将表格添加到其中
  GtkWidget *scroll_window = gtk_scrolled_window_new(NULL, NULL);
  gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scroll_window), GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);
  gtk_container_add(GTK_CONTAINER(scroll_window), grid);
  // 创建新窗口并将可滚动窗口添加到其中
  GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "电影管理");
  gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
  gtk_container_add(GTK_CONTAINER(window), scroll_window);
  // 加载样式表
  GtkCssProvider *provider = gtk_css_provider_new();
  gtk_css_provider_load_from_path(provider, "./css/movie_table.css", NULL);
  GtkStyleContext *context = gtk_widget_get_style_context(window);
  gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
  g_object_unref(provider);
  // 释放链表和文件资源
  free(current_movie_node);
  fclose(current_movie_data);
  // 显示窗口和所有控件
  gtk_widget_show_all(window);
}
void on_button_clicked_movie_times_manager(GtkWidget* button, gpointer data) {

}
void on_button_clicked_guest_button1(GtkWidget* button, gpointer data) {
  FILE* current_user_data = readUserFile();
  Node* current_user_node = getUserList(current_user_data);
  printUserList(current_user_node, USER_TYPE_GUEST);
}
void on_button_clicked_guest_button2(GtkWidget* button, gpointer data) {
  FILE* current_user_data = readUserFile();
  Node* current_user_node = getUserList(current_user_data);
  printUserList(current_user_node, USER_TYPE_ADMIN);
}
void on_button_clicked_sell_button1(GtkWidget* button, gpointer data) {
  FILE* current_good_data = readGoodFile();
  Node* current_good_node = getGoodList(current_good_data);
  printGoodList(current_good_node, FOOD_TYPE_SNACK);
  printGoodList(current_good_node, FOOD_TYPE_DRINK);
}
void on_button_clicked_sell_button2(GtkWidget* button, gpointer data) {
  FILE* current_good_data = readGoodFile();
  Node* current_good_node = getGoodList(current_good_data);
  printGoodList(current_good_node, FOOD_TYPE_DERIVATIVE);
}
void on_button_clicked_sell_button3(GtkWidget* button, gpointer data) {
  FILE* current_ticket_data = readTicketFile();
  Node* current_ticket_node = getTicketList(current_ticket_data);
  printTicketList(current_ticket_node);
}