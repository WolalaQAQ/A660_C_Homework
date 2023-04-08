//
// Created by Adminstrator on 2023/3/21.
//

#ifndef A660_C_HOMEWORK_USERS_H
#define A660_C_HOMEWORK_USERS_H

#include "movie.h"
#include "store.h"
#include "vector.h"

struct User {
  int identity;
  char name[20];
  char password[20];
  float balance;
  Vector* tickets;
  Vector* foods;
};

#endif  // A660_C_HOMEWORK_USERS_H
