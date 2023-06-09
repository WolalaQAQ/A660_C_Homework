//
// Created by Adminstrator on 2023/3/21.
//

#ifndef A660_C_HOMEWORK_MOVIE_H
#define A660_C_HOMEWORK_MOVIE_H

#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "vector.h"

struct Movie {
  char name[100];
  int year;
  char director[500];
  char actor[500];
  char country[15];
  char language[15];
  char introduction[1000];
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

enum MovieSortType {
  MOVIE_SORT_BY_YEAR_ASC,
  MOVIE_SORT_BY_YEAR_DESC,
  MOVIE_SORT_BY_SCORE_ASC,
  MOVIE_SORT_BY_SCORE_DESC
};

void generateKey(struct Ticket* ticket);

FILE* readMovieFile();
void writeMovieFile(struct Movie* movie);
void overWriteMovieFile(Node* head);
Node* getMovieList(FILE* movie_file);
void printMovieList(Node* head);
int findMovieNode(Node* head, struct Movie* movie);
float compareMovieNode(struct Movie* movie1, struct Movie* movie2, enum MovieSortType sort_type);
void sortMovieList(Node** head, enum MovieSortType sort_type);

FILE* readMovieTimesFile();
void writeMovieTimesFile(struct MovieTimes* movie_times);
Node* getMovieTimesList(FILE* movie_times_file);
void printMovieTimesList(Node* head);

FILE* readTicketFile();
void writeTicketFile(struct Ticket* ticket);
Node* getTicketList(FILE* ticket_file);
void printTicketList(Node* head);

#endif  // A660_C_HOMEWORK_MOVIE_H
