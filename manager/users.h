//
// Created by Adminstrator on 2023/3/21.
//

#ifndef A660_C_HOMEWORK_USERS_H
#define A660_C_HOMEWORK_USERS_H

#include "movie.h"
#include "store.h"
#include "list.h"

struct User {
  int isAdmin;
  char name[20];
  char password[20];
  float balance;
};

FILE* readUserFile();
void writeUserFile(struct User* user);
Node* getUserList(FILE* user_file);
void printUserList(Node* head, int identity);

#endif  // A660_C_HOMEWORK_USERS_H
