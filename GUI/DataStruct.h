//
// Created by wolala on 23-4-13.
//

#ifndef A660_C_HOMEWORK_DATASTRUCT_H
#define A660_C_HOMEWORK_DATASTRUCT_H

#include <gtk/gtk.h>

#include "list.h"

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

typedef struct {
  GtkWidget *window;
  GtkWidget *grid;
  Node *movie_node;
} MovieData;

typedef struct {
  GtkWidget *search_entry;
  GtkWidget *grid;
  Node* head;
} SearchData;

typedef struct {
  GtkWidget *window;
  GtkWidget *grid;
  gboolean sort_by_asc;
  int list_length;
  Node *head;
} SortData;
#endif  // A660_C_HOMEWORK_DATASTRUCT_H
