//
// Created by wolala on 23-4-8.
//
#include "button_floor2.h"

void on_button_clicked_movie_button1(GtkWidget* button, gpointer data) {

}
void on_button_clicked_movie_button2(GtkWidget* button, gpointer data) {
  FILE* current_movie_data = readMovieFile();
  Node* current_movie_node = getMovieList(current_movie_data);
  printMovieList(current_movie_node);
}
void on_button_clicked_guest_button1(GtkWidget* button, gpointer data) {
  FILE* current_user_data = readUserFile();
  Node* current_user_node = getUserList(current_user_data);
  printUserList(current_user_node, USER_TYPE_GUEST);
}
void on_button_clicked_guest_button2(GtkWidget* button, gpointer data) {
  FILE* current_user_data = readUserFile();
  Node* current_user_node = getUserList(current_user_data);
  printUserList(current_user_node, USER_TYPE_ADMIN);
}
void on_button_clicked_sell_button1(GtkWidget* button, gpointer data) {
  FILE* current_good_data = readGoodFile();
  Node* current_good_node = getGoodList(current_good_data);
  printGoodList(current_good_node, FOOD_TYPE_SNACK);
  printGoodList(current_good_node, FOOD_TYPE_DRINK);
}
void on_button_clicked_sell_button2(GtkWidget* button, gpointer data) {
  FILE* current_good_data = readGoodFile();
  Node* current_good_node = getGoodList(current_good_data);
  printGoodList(current_good_node, FOOD_TYPE_DERIVATIVE);
}
void on_button_clicked_sell_button3(GtkWidget* button, gpointer data) {
  FILE* current_ticket_data = readTicketFile();
  Node* current_ticket_node = getTicketList(current_ticket_data);
  printTicketList(current_ticket_node);
}