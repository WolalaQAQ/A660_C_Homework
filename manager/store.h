//
// Created by Adminstrator on 2023/3/21.
//

#ifndef A660_C_HOMEWORK_STORE_H
#define A660_C_HOMEWORK_STORE_H

enum FoodType {
  FOOD_TYPE_DRINK = 0,
  FOOD_TYPE_SNACK = 1,
  FOOD_TYPE_DERIVATIVE = 2
};

struct Food {
  char name[20];
  float price;
  enum FoodType type;
};

#endif  // A660_C_HOMEWORK_STORE_H
