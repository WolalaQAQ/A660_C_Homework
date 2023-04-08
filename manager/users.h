//
// Created by Adminstrator on 2023/3/21.
//

#ifndef A660_C_HOMEWORK_USERS_H
#define A660_C_HOMEWORK_USERS_H

#include "movie.h"
#include "store.h"
#include "list.h"

enum identity {
  USER_TYPE_GUEST = 0,
  USER_TYPE_ADMIN = 1
};

struct User {
  enum identity identity;
  char name[20];
  char password[20];
  float balance;
};

FILE* readUserFile();
void writeUserFile(struct User* user);
Node* getUserList(FILE* user_file);
void printUserList(Node* head, enum identity identity);

#endif  // A660_C_HOMEWORK_USERS_H
