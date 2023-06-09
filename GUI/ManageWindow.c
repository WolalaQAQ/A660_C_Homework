//
// Created by wolala on 23-4-13.
//
#include "ManageWindow.h"

void MainManageWindow(GtkWidget *button, gpointer data) {
  // 创建一个新窗口
  GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "影院管理系统");
  gtk_window_set_default_size(GTK_WINDOW(window), 900, 600);
  // 创建一个布局容器
  GtkWidget *layout = gtk_layout_new(NULL, NULL);
  gtk_container_add(GTK_CONTAINER(window), layout);
  // 加载图片
  GtkWidget *image =
      gtk_image_new_from_file("C:\\Users\\wangziyi\\Desktop\\GUI\\bk1.jpg");
  // 将图片添加到布局容器中
  gtk_layout_put(GTK_LAYOUT(layout), image, 0, 0);
  // 创建一个按钮
  GtkWidget *button1 = gtk_button_new_with_label("电影和场次管理");
  gtk_widget_set_size_request(button1, 600, 100);
  gtk_layout_put(GTK_LAYOUT(layout), button1, 150, 20);
  // 设置按钮的字体大小
  PangoContext *context = gtk_widget_get_pango_context(button1);
  PangoFontDescription *font_desc1 =
      pango_font_description_from_string("STKaiti 30");
  gtk_widget_override_font(button1, font_desc1);
  // 创建一个按钮
  GtkWidget *button2 = gtk_button_new_with_label("用户管理");
  gtk_widget_set_size_request(button2, 600, 100);
  gtk_layout_put(GTK_LAYOUT(layout), button2, 150, 180);
  // 设置按钮的字体大小
  PangoFontDescription *font_desc2 =
      pango_font_description_from_string("STKaiti 30");
  gtk_widget_override_font(button2, font_desc2);
  // 创建一个按钮
  GtkWidget *button3 = gtk_button_new_with_label("商品售卖管理");
  gtk_widget_set_size_request(button3, 600, 100);
  // gtk_widget_set_halign(button3, GTK_ALIGN_END);
  gtk_layout_put(GTK_LAYOUT(layout), button3, 150, 340);
  // 设置按钮的字体大小
  PangoFontDescription *font_desc3 =
      pango_font_description_from_string("STKaiti 30");
  gtk_widget_override_font(button3, font_desc3);
  // 连接按钮的 "clicked" 事件信号
  g_signal_connect(button1, "clicked", G_CALLBACK(MainMovieManageWindow),
                   NULL);
  g_signal_connect(button2, "clicked", G_CALLBACK(MainUserManageWindow),
                   NULL);
  g_signal_connect(button3, "clicked", G_CALLBACK(MainGoodManageWindow),
                   NULL);
  // 连接窗口的 "destroy" 事件信号
  g_signal_connect(window, "destroy", G_CALLBACK(on_window_close_show_main_window), NULL);
  // 显示窗口和所有控件
  gtk_widget_show_all(window);
}