//
// Created by wolala on 23-4-13.
//
#include "GoodManageWindow.h"

void MainGoodManageWindow(GtkWidget *button, gpointer data) {
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
  // 连接按钮的 "clicked" 事件信号,点击按钮的事件在此处添加
  g_signal_connect(button1, "clicked",
                   G_CALLBACK(on_button_clicked_good_button1),
                   "background1.png");
  g_signal_connect(button2, "clicked",
                   G_CALLBACK(on_button_clicked_good_button2),
                   "background3.png");
  // 显示窗口和所有控件
  gtk_widget_show_all(window);
}


void on_button_clicked_good_button1(GtkWidget* button, gpointer data) {
  FILE* current_good_data = readGoodFile();
  Node* current_good_node = getGoodList(current_good_data);
  printGoodList(current_good_node, FOOD_TYPE_SNACK);
  printGoodList(current_good_node, FOOD_TYPE_DRINK);
}


void on_button_clicked_good_button2(GtkWidget* button, gpointer data) {
  FILE* current_good_data = readGoodFile();
  Node* current_good_node = getGoodList(current_good_data);
  printGoodList(current_good_node, FOOD_TYPE_DERIVATIVE);
}