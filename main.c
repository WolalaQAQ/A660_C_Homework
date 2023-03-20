#include <gtk/gtk.h>

static void on_button_clicked(GtkWidget *widget, gpointer data) {
  g_print("Hello, GTK3!\n");
}

static void on_activate(GtkApplication *app, gpointer user_data) {
  GtkWidget *window;
  GtkWidget *button;

  // 创建窗口
  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "GTK3 Example");
  gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

  // 创建按钮并设置标签
  button = gtk_button_new_with_label("Click me!");
  g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);

  // 将按钮添加到窗口中
  gtk_container_add(GTK_CONTAINER(window), button);

  // 显示窗口及其所有子部件
  gtk_widget_show_all(window);
}

int main(int argc, char *argv[]) {
  GtkApplication *app;
  int status;

  app = gtk_application_new("com.example.gtk3", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  return status;
}
