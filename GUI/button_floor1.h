// 该头文件用于存放第一级窗口界面的回调函数
#ifndef BUTTON_FLOOR1_C
#define BUTTON_FLOOR1_C
#include"button_floor2.h"

void on_button_clicked_movie(GtkWidget *button, gpointer data) {
  // 创建一个新窗口
  GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "电影管理");
  gtk_window_set_default_size(GTK_WINDOW(window), 600, 600);

  // 创建一个布局容器
  GtkWidget *layout = gtk_layout_new(NULL, NULL);
  gtk_container_add(GTK_CONTAINER(window), layout);

  // 加载图片
  GtkWidget *image =
      gtk_image_new_from_file("C:\\Users\\wangziyi\\Desktop\\GUI\\bk2_S.jpg");

  // 将图片添加到布局容器中
  gtk_layout_put(GTK_LAYOUT(layout), image, 0, 0);

  // 创建一个按钮
  GtkWidget *button1 = gtk_button_new_with_label("场次管理");
  gtk_widget_set_size_request(button1, 300, 120);
  gtk_layout_put(GTK_LAYOUT(layout), button1, 150, 40);
  PangoFontDescription *font_desc1 =
      pango_font_description_from_string("STKaiti 24");
  gtk_widget_override_font(button1, font_desc1);

  // 创建一个按钮
  GtkWidget *button2 = gtk_button_new_with_label("基础信息");
  gtk_widget_set_size_request(button2, 300, 120);
  gtk_layout_put(GTK_LAYOUT(layout), button2, 150, 240);
  PangoFontDescription *font_desc2 =
      pango_font_description_from_string("STKaiti 24");
  gtk_widget_override_font(button2, font_desc2);


  // 连接按钮的 "clicked" 事件信号,点击按钮的事件在此处添加
  g_signal_connect(button1, "clicked", G_CALLBACK(on_button_clicked_movie_button1),
                   "background1.png");
  g_signal_connect(button2, "clicked", G_CALLBACK(on_button_clicked_movie_button2),
                   "background3.png");

  // 显示窗口和所有控件
  gtk_widget_show_all(window);
}



void on_button_clicked_guest(GtkWidget *button, gpointer data) {
  // 创建一个新窗口
  GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "人员管理");
  gtk_window_set_default_size(GTK_WINDOW(window), 600, 600);

  // 创建一个布局容器
  GtkWidget *layout = gtk_layout_new(NULL, NULL);
  gtk_container_add(GTK_CONTAINER(window), layout);

  // 加载图片
  GtkWidget *image =
      gtk_image_new_from_file("C:\\Users\\wangziyi\\Desktop\\GUI\\bk2_S.jpg");

  // 将图片添加到布局容器中
  gtk_layout_put(GTK_LAYOUT(layout), image, 0, 0);

  GtkWidget *button1 = gtk_button_new_with_label("会员信息");
  gtk_widget_set_size_request(button1, 300, 120);
  gtk_layout_put(GTK_LAYOUT(layout), button1, 150, 40);
  PangoFontDescription *font_desc1 =
      pango_font_description_from_string("STKaiti 24");
  gtk_widget_override_font(button1, font_desc1);

  // 创建一个按钮
  GtkWidget *button2 = gtk_button_new_with_label("员工信息");
  gtk_widget_set_size_request(button2, 300, 120);
  gtk_layout_put(GTK_LAYOUT(layout), button2, 150, 240);
  PangoFontDescription *font_desc2 =
      pango_font_description_from_string("STKaiti 24");
  gtk_widget_override_font(button2, font_desc2);

// 连接按钮的 "clicked" 事件信号,点击按钮的事件在此处添加
  g_signal_connect(button1, "clicked",
                   G_CALLBACK(on_button_clicked_guest_button1),
                   "background1.png");
  g_signal_connect(button2, "clicked",
                   G_CALLBACK(on_button_clicked_guest_button2),
                   "background3.png");

  // 显示窗口和所有控件
  gtk_widget_show_all(window);
}



void on_button_clicked_sell(GtkWidget *button, gpointer data) {
  // 创建一个新窗口
  GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "售卖管理");
  gtk_window_set_default_size(GTK_WINDOW(window), 600, 800);

  // 创建一个布局容器
  GtkWidget *layout = gtk_layout_new(NULL, NULL);
  gtk_container_add(GTK_CONTAINER(window), layout);

  // 加载图片
  GtkWidget *image =
      gtk_image_new_from_file("C:\\Users\\wangziyi\\Desktop\\GUI\\bk2_L.jpg");

  // 将图片添加到布局容器中
  gtk_layout_put(GTK_LAYOUT(layout), image, 0, 0);

  GtkWidget *button1 = gtk_button_new_with_label("餐饮管理");
  gtk_widget_set_size_request(button1, 300, 120);
  gtk_layout_put(GTK_LAYOUT(layout), button1, 150, 40);
  PangoFontDescription *font_desc1 =
      pango_font_description_from_string("STKaiti 24");
  gtk_widget_override_font(button1, font_desc1);

  // 创建一个按钮
  GtkWidget *button2 = gtk_button_new_with_label("周边管理");
  gtk_widget_set_size_request(button2, 300, 120);
  gtk_layout_put(GTK_LAYOUT(layout), button2, 150, 240);
  PangoFontDescription *font_desc2 =
      pango_font_description_from_string("STKaiti 24");
  gtk_widget_override_font(button2, font_desc2);

   // 创建一个按钮
  GtkWidget *button3 = gtk_button_new_with_label("售票系统");
  gtk_widget_set_size_request(button3, 300, 120);
  gtk_layout_put(GTK_LAYOUT(layout), button3, 150, 440);
  PangoFontDescription *font_desc3 =
  pango_font_description_from_string("STKaiti 24");
  gtk_widget_override_font(button3, font_desc3);

 
  // 连接按钮的 "clicked" 事件信号,点击按钮的事件在此处添加
  g_signal_connect(button1, "clicked",
                   G_CALLBACK(on_button_clicked_sell_button1),
                   "background1.png");
  g_signal_connect(button2, "clicked",
                   G_CALLBACK(on_button_clicked_sell_button2),
                   "background3.png");
  g_signal_connect(button2, "clicked",
                   G_CALLBACK(on_button_clicked_sell_button3),
                   "background3.png");


  // 显示窗口和所有控件
  gtk_widget_show_all(window);
}

void Administor()
{
  // 创建一个新窗口
  GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "影院管理系统(floor1)");
  gtk_window_set_default_size(GTK_WINDOW(window), 900, 1200);

  // 创建一个布局容器
  GtkWidget *layout = gtk_layout_new(NULL, NULL);
  gtk_container_add(GTK_CONTAINER(window), layout);

  // 加载图片
  GtkWidget *image =
      gtk_image_new_from_file("C:\\Users\\wangziyi\\Desktop\\GUI\\bk1.jpg");

  // 将图片添加到布局容器中
  gtk_layout_put(GTK_LAYOUT(layout), image, 0, 0);

  // 创建一个按钮
  GtkWidget *button1 = gtk_button_new_with_label("电影信息");
  gtk_widget_set_size_request(button1, 600, 100);
  gtk_layout_put(GTK_LAYOUT(layout), button1, 150, 20);
  // 设置按钮的字体大小
  PangoContext *context = gtk_widget_get_pango_context(button1);
  PangoFontDescription *font_desc1 =
      pango_font_description_from_string("STKaiti 30");
  gtk_widget_override_font(button1, font_desc1);

  // 创建一个按钮
  GtkWidget *button2 = gtk_button_new_with_label("用户信息");
  gtk_widget_set_size_request(button2, 600, 100);
  // gtk_widget_set_halign(button2, GTK_ALIGN_CENTER);
  gtk_layout_put(GTK_LAYOUT(layout), button2, 150, 180);
  // 设置按钮的字体大小
  PangoFontDescription *font_desc2 =
      pango_font_description_from_string("STKaiti 30");
  gtk_widget_override_font(button2, font_desc2);

  // 创建一个按钮
  GtkWidget *button3 = gtk_button_new_with_label("售卖管理");
  gtk_widget_set_size_request(button3, 600, 100);
  // gtk_widget_set_halign(button3, GTK_ALIGN_END);
  gtk_layout_put(GTK_LAYOUT(layout), button3, 150, 340);
  // 设置按钮的字体大小
  PangoFontDescription *font_desc3 =
      pango_font_description_from_string("STKaiti 30");
  gtk_widget_override_font(button3, font_desc3);

  // 连接按钮的 "clicked" 事件信号
  g_signal_connect(button1, "clicked", G_CALLBACK(on_button_clicked_movie),
                   "background1.png");
  g_signal_connect(button2, "clicked", G_CALLBACK(on_button_clicked_guest),
                   "background3.png");
  g_signal_connect(button3, "clicked", G_CALLBACK(on_button_clicked_sell),
                   "background4.png");

  // 显示窗口和所有控件
  gtk_widget_show_all(window);
}
#endif //BUTTON_FLOOR1_C