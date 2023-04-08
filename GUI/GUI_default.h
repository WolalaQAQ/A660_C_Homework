//登录界面用到的子函数和一些临时测试用的函数
#ifndef GUI_DEFAULT_C
#define GUI_DEFAULT_C

#include <gtk/gtk.h>

#include "button_floor1.h"
#include "button_floor2.h"
#include "button_floor3.h"

#include "users.h"
typedef struct {
  GtkWidget *login_window;
  GtkEntry *username_entry;
  GtkEntry *password_entry;
} LoginData;

typedef struct {
  GtkWidget *register_window;
  GtkComboBox *combo_box;
  GtkEntry *username_entry;
  GtkEntry *password_entry;
} RegistrationData;

void on_window_close(GtkWidget *widget, gpointer data);

void on_button_clicked_login();
void on_button_clicked_login_confirm(GtkWidget *widget, LoginData *data);
void on_button_clicked_register();
void on_button_clicked_register_confirm(GtkWidget *button, RegistrationData *data);

void on_button_clicked_movie(GtkWidget *button, gpointer data);
void on_button_clicked_guest(GtkWidget *button, gpointer data);
void on_button_clicked_sell(GtkWidget *button, gpointer data);
void WindowAdministor();

#endif  // GUI_DEFAULT_C