//
// Created by wolala on 23-4-13.
//
#include "LoginRegisterWindow.h"

void LoginWindow(GtkWidget *button, gpointer data) {
  // 获取父窗口
  GtkWidget *window_parent = (GtkWidget *)data;
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
  LoginData *login_data = g_new(LoginData, 1);
  login_data->login_window = window;
  login_data->username_entry = username_entry_widget;
  login_data->password_entry = password_entry_widget;
  // 连接按钮的 "clicked" 事件信号
  g_signal_connect(confirm_button, "clicked", G_CALLBACK(on_button_clicked_login_confirm), login_data);
  // 连接窗口的 "delete-event" 事件信号
  g_signal_connect(window, "delete-event", G_CALLBACK(on_window_close_show_parent_window), window_parent);
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
    MainManageWindow(NULL, NULL);
    // 销毁登录窗口
    gtk_widget_destroy(data->login_window);
  }
  g_free(data);
  free(login_user);
  free(current_user_list);
  fclose(current_user_file);
}

void RegisterWindow(GtkWidget *button, gpointer data) {
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
  RegistrationData *registration_data = g_new(RegistrationData, 1);
  registration_data->register_window = window;
  registration_data->combo_box = combo_box_widget;
  registration_data->username_entry = username_entry_widget;
  registration_data->password_entry = password_entry_widget;
  // 连接确认按钮的回调函数
  g_signal_connect(confirm_button, "clicked",
                   G_CALLBACK(on_button_clicked_register_confirm), registration_data);
  // 连接窗口的关闭事件
  g_signal_connect(window, "delete-event",
                   G_CALLBACK(MainWindow), NULL);
  // 显示窗口和所有控件
  gtk_widget_show_all(window);
}

//注册界面的确认注册按钮
void on_button_clicked_register_confirm(GtkWidget *widget, RegistrationData *data) {
  // 获取下拉菜单选项
  gint active_index = gtk_combo_box_get_active(data->combo_box);
  const gchar *active_text = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(data->combo_box));
  // 检查是否有选项被选择
  int user_type = -1;
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
      MainWindow(NULL, NULL);
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
