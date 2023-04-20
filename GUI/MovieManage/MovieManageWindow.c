//
// Created by wolala on 23-4-13.
//

#include "MovieManageWindow.h"

void MainMovieManageWindow(GtkWidget *button, gpointer data) {
  // 创建一个新窗口
  GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "电影和场次管理");
  gtk_window_set_default_size(GTK_WINDOW(window), 600, 600);
  // 创建一个布局容器
  GtkWidget *layout = gtk_layout_new(NULL, NULL);
  gtk_container_add(GTK_CONTAINER(window), layout);
  // 加载图片
  GtkWidget *image =
      gtk_image_new_from_file("C:\\Users\\wangziyi\\Desktop\\GUI\\bk2_S.jpg");
  // 将图片添加到布局容器中
  gtk_layout_put(GTK_LAYOUT(layout), image, 0, 0);

  GtkWidget *movie_manager_button = gtk_button_new_with_label("电影管理");
  gtk_widget_set_size_request(movie_manager_button, 300, 120);
  gtk_layout_put(GTK_LAYOUT(layout), movie_manager_button, 150, 40);
  PangoFontDescription *font_desc1 =
      pango_font_description_from_string("STKaiti 24");
  gtk_widget_override_font(movie_manager_button, font_desc1);

  GtkWidget *movie_times_manager_button = gtk_button_new_with_label("场次管理");
  gtk_widget_set_size_request(movie_times_manager_button, 300, 120);
  gtk_layout_put(GTK_LAYOUT(layout), movie_times_manager_button, 150, 240);
  PangoFontDescription *font_desc2 =
      pango_font_description_from_string("STKaiti 24");
  gtk_widget_override_font(movie_times_manager_button, font_desc2);

  GtkWidget *ticket_manager_button = gtk_button_new_with_label("票务管理");
  gtk_widget_set_size_request(ticket_manager_button, 300, 120);
  gtk_layout_put(GTK_LAYOUT(layout), ticket_manager_button, 150, 440);
  PangoFontDescription *font_desc3 =
      pango_font_description_from_string("STKaiti 24");
  gtk_widget_override_font(ticket_manager_button, font_desc3);

  // 连接按钮的 "clicked" 事件信号,点击按钮的事件在此处添加
  g_signal_connect(movie_manager_button, "clicked",
                   G_CALLBACK(MovieManageWindow), NULL);
  g_signal_connect(movie_times_manager_button, "clicked",
                   G_CALLBACK(MovieTimesManageWindow), NULL);
  g_signal_connect(ticket_manager_button, "clicked",
                   G_CALLBACK(TicketManageWindow), NULL),
      // 显示窗口和所有控件
      gtk_widget_show_all(window);
}

void MovieManageWindow(GtkWidget *button, gpointer data) {
  // 创建新窗口
  GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "电影管理");
  gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
  // 加载样式表
  GtkCssProvider *provider = gtk_css_provider_new();
  gtk_css_provider_load_from_path(provider, "./css/movie_table.css", NULL);
  GtkStyleContext *context = gtk_widget_get_style_context(window);
  gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(provider),
                                 GTK_STYLE_PROVIDER_PRIORITY_USER);
  g_object_unref(provider);
  // 获取电影信息链表
  FILE *current_movie_data = readMovieFile();
  Node *current_movie_node = getMovieList(current_movie_data);
  int length = getListLength(current_movie_node);
  fclose(current_movie_data);
  // 创建表格
  GtkWidget *grid = gtk_grid_new();
  gtk_grid_set_column_spacing(GTK_GRID(grid), 5);
  gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
  // 创建菜单按钮
  GtkWidget *menu_button = gtk_menu_button_new();
  // 创建菜单和菜单项
  GtkWidget *menu = gtk_menu_new();
  GtkWidget *add_movie = gtk_menu_item_new_with_label("添加电影");
  GtkWidget *del_movie = gtk_menu_item_new_with_label("删除电影");
  GtkWidget *search_movie = gtk_menu_item_new_with_label("搜索电影");
  GtkWidget *edit_movie = gtk_menu_item_new_with_label("修改电影");
  // 设置菜单按钮的菜单
  gtk_menu_shell_append(GTK_MENU_SHELL(menu), add_movie);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu), del_movie);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu), search_movie);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu), edit_movie);
  gtk_widget_show_all(menu);
  gtk_menu_button_set_direction(GTK_MENU_BUTTON(menu_button), GTK_ARROW_DOWN);
  gtk_menu_button_set_popup(GTK_MENU_BUTTON(menu_button), menu);
  // 将菜单项添加到菜单按钮的菜单中
  g_signal_connect(add_movie, "activate",
                   G_CALLBACK(on_menu_item_clicked_add_movie), window);
  MovieData *movie_data = g_new(MovieData, 1);
  movie_data->window = window;
  movie_data->movie_node = current_movie_node;
  g_signal_connect(del_movie, "activate",
                   G_CALLBACK(on_menu_item_clicked_delete_movie), movie_data);
  g_signal_connect(search_movie, "activate",
                   G_CALLBACK(on_menu_item_clicked_search_movie), movie_data);
  g_signal_connect(edit_movie, "activate",
                   G_CALLBACK(on_menu_item_clicked_edit_movie), movie_data);
  // 添加表头
  gtk_grid_attach(GTK_GRID(grid), menu_button, 0, 0, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), gtk_label_new("片名"), 0, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), gtk_label_new("上映年份"), 1, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), gtk_label_new("导演"), 2, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), gtk_label_new("主演"), 3, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), gtk_label_new("国家"), 4, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), gtk_label_new("语言"), 5, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), gtk_label_new("简介"), 6, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), gtk_label_new("评分"), 7, 1, 1, 1);
  // 判断链表是否为空
  if (length == 0) {
    // 链表为空，创建空表格并将其添加到窗口中
    GtkWidget *empty_label = gtk_label_new("没有电影信息");
    GtkWidget *empty_frame = gtk_frame_new(NULL);
    gtk_container_add(GTK_CONTAINER(empty_frame), empty_label);
    gtk_grid_attach(GTK_GRID(grid), empty_frame, 0, 2, 8, 1);
  } else {
    // 链表不为空，继续执行代码
    int row = 2;
    // 循环遍历电影信息链表
    while (current_movie_node != NULL) {
      struct Movie *current_movie = current_movie_node->data;
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
      GtkWidget *year =
          gtk_label_new(g_strdup_printf("%d", current_movie->year));
      GtkWidget *director = gtk_label_new(current_movie->director);
      GtkWidget *actor = gtk_label_new(current_movie->actor);
      GtkWidget *country = gtk_label_new(current_movie->country);
      GtkWidget *language = gtk_label_new(current_movie->language);
      GtkWidget *introduction = gtk_label_new(current_movie->introduction);
      GtkWidget *score =
          gtk_label_new(g_strdup_printf("%.1f", current_movie->score));
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
  }
  // 创建一个可滚动的窗口，将表格添加到其中
  GtkWidget *scroll_window = gtk_scrolled_window_new(NULL, NULL);
  gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scroll_window),
                                 GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);
  gtk_container_add(GTK_CONTAINER(scroll_window), grid);
  gtk_container_add(GTK_CONTAINER(window), scroll_window);
  // 释放链表和文件资源
  freeList(current_movie_node);
  // 显示窗口和所有控件
  gtk_widget_show_all(window);
}

void MovieTimesManageWindow(GtkWidget *button, gpointer data) {}

void TicketManageWindow(GtkWidget *button, gpointer data) {}

void on_menu_item_clicked_add_movie(GtkMenuItem *menu_item,
                                    gpointer user_data) {
  gtk_widget_destroy(user_data);
  AddMovieWindow(NULL, NULL);
}

void on_menu_item_clicked_delete_movie(GtkMenuItem *menu_item,
                                       gpointer user_data) {
  MovieData *current_del_data = user_data;
  GtkWidget *current_window = current_del_data->window;
  Node *current_movie_list = current_del_data->movie_node;
  gtk_widget_destroy(current_window);
  DeleteMovieWindow(NULL, current_movie_list);
}

void on_menu_item_clicked_search_movie(GtkMenuItem *menu_item,
                                       gpointer user_data) {
  SearchMovieWindow(NULL, user_data);
}

void on_menu_item_clicked_edit_movie(GtkMenuItem *menu_item,
                                       gpointer user_data) {
  MovieData *movie_data = user_data;
  gtk_widget_destroy(movie_data->window);
  EditMovieWindow(NULL, movie_data->movie_node);
}