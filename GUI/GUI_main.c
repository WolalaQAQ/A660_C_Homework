#include "GUI_main.h"

void Gmain(int argc, char *argv[]) {
  gtk_init(&argc, &argv);

  // 创建一个新窗口
  GtkWidget *window_pass = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window_pass), "登录&注册");
  gtk_window_set_default_size(GTK_WINDOW(window_pass), 769, 615);
  gtk_window_set_deletable(GTK_WINDOW(window_pass), TRUE);

  // 创建一个布局容器
  GtkWidget *layout = gtk_layout_new(NULL, NULL);
  gtk_container_add(GTK_CONTAINER(window_pass), layout);

  // 加载图片
  GtkWidget *image =
      gtk_image_new_from_file("C:\\Users\\wangziyi\\Desktop\\GUI\\log-in-2.jpg");

  // 将图片添加到布局容器中
  gtk_layout_put(GTK_LAYOUT(layout), image, 0, 0);

    // 创建一个标题
  GtkWidget *label = gtk_label_new("欢迎来到本电影院");
  gtk_widget_set_size_request(label, 600, 100);

  // 设置标签的字体大小
  PangoFontDescription *font_desc = pango_font_description_from_string("STKaiti 32");
  gtk_widget_override_font(label, font_desc);

  gtk_layout_put(GTK_LAYOUT(layout), label, 90, 10);

  // 创建一个按钮
  GtkWidget *button1 = gtk_button_new_with_label("登录");
  gtk_widget_set_size_request(button1, 600, 100);
  gtk_layout_put(GTK_LAYOUT(layout), button1, 90, 170);
  // 设置按钮的字体大小
  PangoFontDescription *font_desc1 =
      pango_font_description_from_string("STKaiti 28");
  gtk_widget_override_font(button1, font_desc1);

  // 创建一个按钮
  GtkWidget *button2 = gtk_button_new_with_label("注册");
  gtk_widget_set_size_request(button2, 600, 100);
  gtk_layout_put(GTK_LAYOUT(layout), button2, 90, 330);
  // 设置按钮的字体大小
  PangoFontDescription *font_desc2 =
      pango_font_description_from_string("STKaiti 28");
  gtk_widget_override_font(button2, font_desc2);
  // 连接按钮的 "clicked" 事件信号

  g_signal_connect(button1, "clicked",G_CALLBACK(on_button_clicked_login),
                   "background1.png");
  g_signal_connect(button2, "clicked", G_CALLBACK(on_button_clicked_register),
                   "background3.png");
  g_signal_connect(G_OBJECT(window_pass), "delete-event", G_CALLBACK(on_window_close), NULL);

  // 显示窗口和所有控件
  gtk_widget_show_all(window_pass);
  gtk_main();
}
