//
// Created by Adminstrator on 2023/3/21.
//

#ifndef A660_C_HOMEWORK_STORE_H
#define A660_C_HOMEWORK_STORE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "list.h"

enum GoodType {
  FOOD_TYPE_DRINK = 0,
  FOOD_TYPE_SNACK = 1,
  FOOD_TYPE_DERIVATIVE = 2
};

struct Good {
  enum GoodType type;
  char name[50];
  char description[200];
  float price;
};

FILE* readGoodFile();
void writeGoodFile(struct Good* good);
Node* getGoodList(FILE* good_file);
void printGoodList(Node* head, enum GoodType type);

#endif  // A660_C_HOMEWORK_STORE_H
