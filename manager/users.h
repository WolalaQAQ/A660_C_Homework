//
// Created by Adminstrator on 2023/3/21.
//

#ifndef A660_C_HOMEWORK_USERS_H
#define A660_C_HOMEWORK_USERS_H

#include "movie.h"
#include "store.h"

struct User {
  int identity;
  char name[20];
  char password[20];
  float balance;
  struct Vector* tickets;
  struct Vector* foods;
};

#endif  // A660_C_HOMEWORK_USERS_H
