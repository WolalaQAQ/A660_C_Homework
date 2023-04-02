//
// Created by Adminstrator on 2023/3/21.
//

#ifndef A660_C_HOMEWORK_MOVIE_H
#define A660_C_HOMEWORK_MOVIE_H

#include <stdio.h>
#include <stdlib.h>

struct Movie {
  char name[20];
  int year;
  char director[20];
  char actor[20];
  char country[15];
  char language[15];
  char introduction[200];
  float score;
};

struct MovieTimes {
  struct Movie* movie;
  char time[30];
  char cinema[30];
  float price;
  int seat_remain;
};

struct Ticket {
  struct MovieTimes* movie_times;
  char seat_number[10];
  char key[10];
};

void generateKey(struct Ticket* ticket);
FILE* openFile(char* path, char* mode);

#endif  // A660_C_HOMEWORK_MOVIE_H
