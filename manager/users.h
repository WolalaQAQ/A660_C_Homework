//
// Created by Adminstrator on 2023/3/21.
//

#ifndef A660_C_HOMEWORK_USERS_H
#define A660_C_HOMEWORK_USERS_H

#include "good.h"
#include "list.h"
#include "movie.h"

enum Identity {
  USER_TYPE_GUEST = 0,
  USER_TYPE_ADMIN = 1
};

enum VerifyMode {
  VERIFY_MODE_LOGIN = 0,
  VERIFY_MODE_REGISTER = 1
};

struct User {
  enum Identity identity;
  char name[20];
  char password[20];
  float balance;
};

FILE* readUserFile();
void writeUserFile(struct User* user);
Node* getUserList(FILE* user_file);
void printUserList(Node* head, enum Identity identity);

int findUserNode(Node* head, struct User* user, enum VerifyMode mode);

#endif  // A660_C_HOMEWORK_USERS_H
