//
// Created by Adminstrator on 2023/3/21.
//
#include "users.h"

FILE* readUserFile() {
  FILE* file = fopen("./data/user.txt", "r");
  if (file == NULL) {
    printf("File does not exist. Creating new file...\n");
    file = fopen("./data/user.txt", "w");
    if (file == NULL) {
      printf("Failed to create file.\n");
      exit(1);
    }
  }
  return file;
}

void writeUserFile(struct User* user) {
  FILE* file = fopen("./data/user.txt", "a+");
  if (file == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }
  fprintf(file, "%d %s %s %f", user->identity, user->name, user->password, user->balance);
}

Node* getUserList(FILE* user_file) {
  Node* head = NULL;
  enum identity identity;
  char name[20];
  char password[20];
  float balance;
  while (fscanf(user_file, "%d %s %s %f", &identity, name, password, &balance) == 4) {
    struct User* user = malloc(sizeof(struct User));
    user->identity = identity;
    strcpy(user->name, name);
    strcpy(user->password, password);
    user->balance = balance;
    insertAtTail(&head, user);
  }
  return head;
}

void printUserList(Node* head, enum identity identity) {
  Node* current = head;
  while (current != NULL) {
    struct User* user = (struct User*)current->data;
    if(user->identity != identity) {
      current = current->next;
      continue;
    }
    printf("%s %s %.2f\n", user->name, user->password,
           user->balance);
    current = current->next;
  }
}