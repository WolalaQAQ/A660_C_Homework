//
// Created by wolala on 23-4-8.
//
#include "GUI_default.h"

gchar *administor_password= "password_default";
gchar *temp_password ;
void on_button_clicked_login_text(GtkWidget *widget, gpointer data) {
  // 获取账号文本框中的内容
  GtkWidget *entry1 = GTK_WIDGET(data);
  const gchar *id = gtk_entry_get_text(GTK_ENTRY(entry1));
  // 获取文本框中的内容
  GtkWidget *entry2 = GTK_WIDGET(data);
  const gchar *password = gtk_entry_get_text(GTK_ENTRY(entry2));

  // 在控制台中打印文本框中的内容
  g_print("账号: %s\n", id);
  g_print("密码: %s\n", password);
  temp_password = password;
}

void on_button_clicked_login() {
  // 创建一个新窗口
  GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "账号&密码");
  gtk_window_set_default_size(GTK_WINDOW(window), 300, 250);

  // 创建一个布局容器
  GtkWidget *layout = gtk_layout_new(NULL, NULL);
  gtk_container_add(GTK_CONTAINER(window), layout);

  // 创建一个账号文本框
  GtkWidget *entry1 = gtk_entry_new();
  gtk_entry_set_max_length(GTK_ENTRY(entry1), 100);
  gtk_entry_set_text(GTK_ENTRY(entry1), "此处输入账号");
  gtk_layout_put(GTK_LAYOUT(layout), entry1, 70, 50);


  // 创建一个文本框
  GtkWidget *entry2 = gtk_entry_new();
  gtk_entry_set_visibility(GTK_ENTRY(entry2), FALSE);
  gtk_entry_set_max_length(GTK_ENTRY(entry2), 100);
  gtk_layout_put(GTK_LAYOUT(layout), entry2, 70, 100);
  gtk_entry_set_text(GTK_ENTRY(entry2), "");


  // 创建一个按钮
  GtkWidget *button = gtk_button_new_with_label("信息输入完成");
  gtk_widget_set_size_request(button, 80, 40);
  gtk_layout_put(GTK_LAYOUT(layout), button, 83, 150);

  // 连接按钮的 "clicked" 事件信号
  g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked_login_text),
                   entry2);
  //if (temp_password == administor_password)
  g_signal_connect(button, "clicked", G_CALLBACK(Administor), "passed");


  // 显示窗口和所有控件
  gtk_widget_show_all(window);
}



void on_button_clicked_register_() {}

void on_button_clicked_register() {
  // 创建一个新窗口
  GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "影院管理系统");
  gtk_window_set_default_size(GTK_WINDOW(window), 900, 1200);

  // 创建一个布局容器
  GtkWidget *layout = gtk_layout_new(NULL, NULL);
  gtk_container_add(GTK_CONTAINER(window), layout);

  // 加载图片
  GtkWidget *image =
      gtk_image_new_from_file("C:\\Users\\wangziyi\\Desktop\\GUI\\bk1.jpg");

  // 将图片添加到布局容器中
  gtk_layout_put(GTK_LAYOUT(layout), image, 0, 0);

  // 显示窗口和所有控件
  gtk_widget_show_all(window);
}