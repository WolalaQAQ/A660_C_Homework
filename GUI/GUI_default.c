//
// Created by wolala on 23-4-8.
//
#include "GUI_default.h"

//关闭窗口
void on_window_close(GtkWidget *widget, gpointer data) {
  gtk_main_quit();
}

//打开登录输入界面
void on_button_clicked_login() {
  // 创建一个新窗口和布局容器
  GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "登录");
  gtk_window_set_default_size(GTK_WINDOW(window), 350, 300);
  GtkWidget *layout = gtk_layout_new(NULL, NULL);
  gtk_container_add(GTK_CONTAINER(window), layout);
  // 创建用户名文本框
  GtkWidget *username_label = gtk_label_new("用户名：");
  gtk_layout_put(GTK_LAYOUT(layout), username_label, 50, 100);
  GtkWidget *username_entry = gtk_entry_new();
  gtk_layout_put(GTK_LAYOUT(layout), username_entry, 120, 100);
  // 创建密码文本框
  GtkWidget *password_label = gtk_label_new("密码：");
  gtk_layout_put(GTK_LAYOUT(layout), password_label, 50, 150);
  GtkWidget *password_entry = gtk_entry_new();
  gtk_entry_set_visibility(GTK_ENTRY(password_entry), FALSE);
  gtk_layout_put(GTK_LAYOUT(layout), password_entry, 120, 150);
  // 创建确认按钮
  GtkWidget *confirm_button = gtk_button_new_with_label("登录");
  gtk_layout_put(GTK_LAYOUT(layout), confirm_button, 170, 220);
  // 将每个控件分配给变量
  GtkEntry *username_entry_widget = GTK_ENTRY(username_entry);
  GtkEntry *password_entry_widget = GTK_ENTRY(password_entry);
  // 创建 LoginData 结构体并将其传递给回调函数
  LoginData *data = g_new(LoginData, 1);
  data->login_window = window;
  data->username_entry = username_entry_widget;
  data->password_entry = password_entry_widget;
  // 连接按钮的 "clicked" 事件信号
  g_signal_connect(confirm_button, "clicked", G_CALLBACK(on_button_clicked_login_confirm), data);
  // 显示窗口和所有控件
  gtk_widget_show_all(window);
}

//登录界面的确认登录按钮
void on_button_clicked_login_confirm(GtkWidget *widget, LoginData *data) {
  // 获取账号文本框中的内容
  const gchar *username_text = gtk_entry_get_text(data->username_entry);
  const gchar *password_text = gtk_entry_get_text(data->password_entry);
  // 读取用户文件
  FILE* current_user_file = readUserFile();
  Node* current_user_list = getUserList(current_user_file);
  struct User* login_user = (struct User*)malloc(sizeof(struct User));
  strcpy(login_user->name, username_text);
  strcpy(login_user->password, password_text);
  // 检查用户是否存在
  if (!findUserNode(current_user_list, login_user, VERIFY_MODE_LOGIN)) {
    GtkWidget *dialog = gtk_message_dialog_new(NULL,
                                               GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
                                               GTK_MESSAGE_WARNING,
                                               GTK_BUTTONS_OK,
                                               "用户名不存在或密码错误！");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
    return;
  } else {
    GtkWidget *dialog = gtk_message_dialog_new(NULL,
                                               GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
                                               GTK_MESSAGE_INFO,
                                               GTK_BUTTONS_OK,
                                               "登陆成功！");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
    WindowAdministor();
    // 销毁登录窗口
    gtk_widget_destroy(data->login_window);
  }
  g_free(data);
  free(login_user);
  free(current_user_list);
  fclose(current_user_file);
}

//打开注册输入界面
void on_button_clicked_register() {
  // 创建一个新窗口和布局容器
  GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "注册");
  gtk_window_set_default_size(GTK_WINDOW(window), 350, 300);
  GtkWidget *layout = gtk_layout_new(NULL, NULL);

  gtk_container_add(GTK_CONTAINER(window), layout);

  // 创建下拉菜单
  GtkWidget *combo_box = gtk_combo_box_text_new();
  gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(combo_box), "0", "顾客");
  gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(combo_box), "1", "管理员");
  gtk_layout_put(GTK_LAYOUT(layout), combo_box, 50, 50);

  // 创建用户名文本框
  GtkWidget *username_label = gtk_label_new("用户名：");
  gtk_layout_put(GTK_LAYOUT(layout), username_label, 50, 100);
  GtkWidget *username_entry = gtk_entry_new();
  gtk_layout_put(GTK_LAYOUT(layout), username_entry, 120, 100);

  // 创建密码文本框
  GtkWidget *password_label = gtk_label_new("密码：");
  gtk_layout_put(GTK_LAYOUT(layout), password_label, 50, 150);
  GtkWidget *password_entry = gtk_entry_new();
  gtk_entry_set_visibility(GTK_ENTRY(password_entry), FALSE);
  gtk_layout_put(GTK_LAYOUT(layout), password_entry, 120, 150);

  // 创建确认按钮
  GtkWidget *confirm_button = gtk_button_new_with_label("注册");
  gtk_layout_put(GTK_LAYOUT(layout), confirm_button, 170, 220);

  // 将每个控件分配给变量
  GtkComboBox *combo_box_widget = GTK_COMBO_BOX(combo_box);
  GtkEntry *username_entry_widget = GTK_ENTRY(username_entry);
  GtkEntry *password_entry_widget = GTK_ENTRY(password_entry);

  // 创建 RegistrationData 结构体并将其传递给回调函数
  RegistrationData *data = g_new(RegistrationData, 1);
  data->register_window = window;
  data->combo_box = combo_box_widget;
  data->username_entry = username_entry_widget;
  data->password_entry = password_entry_widget;

  // 连接确认按钮的回调函数
  g_signal_connect(G_OBJECT(confirm_button), "clicked",
                   G_CALLBACK(on_button_clicked_register_confirm), data);

  // 显示窗口和所有控件
  gtk_widget_show_all(window);
}

void on_button_clicked_register_confirm(GtkWidget *button, RegistrationData *data) {
  // 获取下拉菜单选项
  gint active_index = gtk_combo_box_get_active(data->combo_box);
  const gchar *active_text = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(data->combo_box));

  int user_type = -1;
  // 检查是否有选项被选择
  if (active_text == NULL) {
    // 如果没有选项被选择，弹出一个警告对话框
    GtkWidget *dialog = gtk_message_dialog_new(NULL,
                                               GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
                                               GTK_MESSAGE_WARNING,
                                               GTK_BUTTONS_OK,
                                               "请选择用户类型！");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
    return;
  } else {
    // 如果有选项被选择，继续执行校验机制
    if (strcmp(active_text, "管理员") == 0) {
      user_type = 1;
    } else if (strcmp(active_text, "顾客") == 0) {
      user_type = 0;
    }
  }

  // 获取用户名和密码文本框内容
  const gchar *username_text = gtk_entry_get_text(data->username_entry);
  const gchar *password_text = gtk_entry_get_text(data->password_entry);

  // 检查用户名和密码是否为空
  if (username_text[0] == '\0' || password_text[0] == '\0' || username_text[0] == ' ' || password_text[0] == ' ') {
    // 如果任何一个文本框为空，弹出一个警告对话框
    GtkWidget *dialog = gtk_message_dialog_new(NULL,
                                               GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
                                               GTK_MESSAGE_WARNING,
                                               GTK_BUTTONS_OK,
                                               "用户名和密码不能为空！");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
    return;
  } else {
    // 如果所有文本框都非空，打印用户信息并释放 RegistrationData 结构体所占用的内存
    FILE* current_user_file = readUserFile();
    Node* current_user_list = getUserList(current_user_file);
    struct User* new_user = (struct User*)malloc(sizeof(struct User));
    new_user->identity = user_type;
    strcpy(new_user->name, username_text);
    strcpy(new_user->password, password_text);
    new_user->balance = 0.0f;
    if(!findUserNode(current_user_list, new_user, VERIFY_MODE_REGISTER)) {
      insertAtTail(&current_user_list, new_user);
      writeUserFile(new_user);
      GtkWidget *dialog = gtk_message_dialog_new(NULL,
                                                 GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
                                                 GTK_MESSAGE_INFO,
                                                 GTK_BUTTONS_OK,
                                                 "注册成功！");
      gtk_dialog_run(GTK_DIALOG(dialog));
      gtk_widget_destroy(dialog);
      gtk_widget_destroy(data->register_window);
    } else {
      GtkWidget *dialog = gtk_message_dialog_new(NULL,
                                                 GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
                                                 GTK_MESSAGE_WARNING,
                                                 GTK_BUTTONS_OK,
                                                 "用户名已存在！");
      gtk_dialog_run(GTK_DIALOG(dialog));
      gtk_widget_destroy(dialog);
      return;
    }
    g_free(data);
    freeList(current_user_list);
    free(new_user);
    fclose(current_user_file);
  }
}

void on_button_clicked_movie(GtkWidget *button, gpointer data) {
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

  // 创建一个按钮
  GtkWidget *movie_manager_button = gtk_button_new_with_label("电影管理");
  gtk_widget_set_size_request(movie_manager_button, 300, 120);
  gtk_layout_put(GTK_LAYOUT(layout), movie_manager_button, 150, 40);
  PangoFontDescription *font_desc1 =
      pango_font_description_from_string("STKaiti 24");
  gtk_widget_override_font(movie_manager_button, font_desc1);

  // 创建一个按钮
  GtkWidget *movie_times_manager_button = gtk_button_new_with_label("场次管理");
  gtk_widget_set_size_request(movie_times_manager_button, 300, 120);
  gtk_layout_put(GTK_LAYOUT(layout), movie_times_manager_button, 150, 240);
  PangoFontDescription *font_desc2 =
      pango_font_description_from_string("STKaiti 24");
  gtk_widget_override_font(movie_times_manager_button, font_desc2);


  // 连接按钮的 "clicked" 事件信号,点击按钮的事件在此处添加
  g_signal_connect(movie_manager_button, "clicked", G_CALLBACK(WindowMovieManager),
                   "background1.png");
  g_signal_connect(movie_times_manager_button, "clicked", G_CALLBACK(on_button_clicked_movie_times_manager),
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

void WindowAdministor()
{
  // 创建一个新窗口
  GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "影院管理系统(floor1)");
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