//
// Created by Adminstrator on 2023/3/21.
//

#include "movie.h"

void generateKey(struct Ticket* ticket) {
  int i;
  for (i = 0; i < 10; i++) {
    ticket->key[i] = rand() % 10;
  }
}

FILE* readMovieFile() {
  FILE* file = fopen("./data/movie.txt", "r");
  if (file == NULL) {
    printf("File does not exist. Creating new file...\n");
    file = fopen("./data/movie.txt", "w");
    if (file == NULL) {
      printf("Failed to create file.\n");
      exit(1);
    }
  }
  return file;
}

void writeMovieFile(struct Movie* movie) {
  FILE* file = fopen("movie.txt", "a+");
  if (file == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }
  fprintf(file, "%s %d %s %s %s %s %s %f", movie->name, movie->year,
          movie->director, movie->actor, movie->country, movie->language,
          movie->introduction, movie->score);
  fclose(file);
}

Node* getMovieList(FILE* movie_file) {
  Node* head = NULL;
  char name[20], director[20], actor[20], country[15], language[15], introduction[200];
  int year;
  float score;
  while (fscanf(movie_file, "%s %d %s %s %s %s %s %f", name, &year, director, actor, country, language, introduction, &score) == 8) {
    struct Movie* movie = malloc(sizeof(struct Movie));
    strcpy(movie->name, name);
    movie->year = year;
    strcpy(movie->director, director);
    strcpy(movie->actor, actor);
    strcpy(movie->country, country);
    strcpy(movie->language, language);
    strcpy(movie->introduction, introduction);
    movie->score = score;
    insertAtTail(&head, movie);
  }
  return head;
}

void printMovieList(Node* head) {
  Node* current = head;
  while (current != NULL) {
        struct Movie* movie = (struct Movie*) current->data;
        printf("%s %d %s %s %s %s %s %.1f\n", movie->name, movie->year,
               movie->director, movie->actor, movie->country, movie->language,
               movie->introduction, movie->score);
        current = current->next;
  }
}

FILE* readMovieTimesFile() {
  FILE* file = fopen("./data/movie_times.txt", "r");
  if (file == NULL) {
        printf("File does not exist. Creating new file...\n");
        file = fopen("./data/movie_times.txt", "w");
        if (file == NULL) {
      printf("Failed to create file.\n");
      exit(1);
        }
  }
  return file;
}

void writeMovieTimesFile(struct MovieTimes* movie_times) {
  FILE* file = fopen("./data/movie_times.txt", "a+");
  if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
  }
  fprintf(file, "%s %s %f %d %s %d %s %s %s %s %s %f",
          movie_times->time, movie_times->cinema, movie_times->price, movie_times->seat_remain,
          movie_times->movie->name, movie_times->movie->year, movie_times->movie->director, movie_times->movie->actor,
          movie_times->movie->country, movie_times->movie->language, movie_times->movie->introduction, movie_times->movie->score);
  fclose(file);
}

Node* getMovieTimesList(FILE* movie_times_file) {
  Node* head = NULL;
  //电影场次信息临时变量
  char time[30], cinema[30];
  float price;
  int seat_remain;

  //电影信息临时变量
  char name[20];
  int year;
  char director[100];
  char actor[100];
  char country[15];
  char language[15];
  char introduction[200];
  float score;

  while (fscanf(movie_times_file, "%s %s %f %d %s %d %s %s %s %s %s %f", time, cinema, &price, &seat_remain,
                name, &year, director, actor,
                country, language, introduction, &score) == 12) {
    struct MovieTimes* movie_times = malloc(sizeof(struct MovieTimes));
    strcpy(movie_times->time, time);
    strcpy(movie_times->cinema, cinema);
    movie_times->price = price;
    movie_times->seat_remain = seat_remain;

    strcpy(movie_times->movie->name, name);
    movie_times->movie->year = year;
    strcpy(movie_times->movie->director, director);
    strcpy(movie_times->movie->actor, actor);
    strcpy(movie_times->movie->country, country);
    strcpy(movie_times->movie->language, language);
    strcpy(movie_times->movie->introduction, introduction);
    movie_times->movie->score = score;

    insertAtTail(&head, movie_times);
  }
  return head;
}

void printMovieTimesList(Node* head) {
  Node* current = head;
  while (current != NULL) {
    struct MovieTimes* movie_times = (struct MovieTimes*) current->data;
    printf("%s %s %s %.2f %d\n", movie_times->movie->name, movie_times->time, movie_times->cinema, movie_times->price, movie_times->seat_remain);
    current = current->next;
  }
}

FILE* readTicketFile() {
  FILE* file = fopen("./data/ticket.txt", "r");
  if (file == NULL) {
    printf("File does not exist. Creating new file...\n");
    file = fopen("./data/ticket.txt", "w");
    if (file == NULL) {
      printf("Failed to create file.\n");
      exit(1);
    }
  }
  return file;
}

void writeTicketFile(struct Ticket* ticket) {
  FILE* file = fopen("./data/ticket.txt", "a+");
  if (file == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }
  fprintf(file, "%s %s %s %s %f %s %d %s %s %s %s %s %f",
          ticket->seat_number, ticket->key, ticket->movie_times->time, ticket->movie_times->cinema,
          ticket->movie_times->price, ticket->movie_times->movie->name, ticket->movie_times->movie->year,
          ticket->movie_times->movie->director, ticket->movie_times->movie->actor, ticket->movie_times->movie->country,
          ticket->movie_times->movie->language, ticket->movie_times->movie->introduction, ticket->movie_times->movie->score);
  fclose(file);
}

Node* getTicketList(FILE* ticket_file) {
  Node* head = NULL;
  //电影票信息临时变量
  char seat_number[30], key[30];

  //电影场次信息临时变量
  char time[30], cinema[30];
  float price;

  //电影信息临时变量
  char name[20];
  int year;
  char director[100];
  char actor[100];
  char country[15];
  char language[15];
  char introduction[200];
  float score;

  while (fscanf(ticket_file, "%s %s %s %s %f %s %d %s %s %s %s %s %f", seat_number, key, time, cinema, &price,
                name, &year, director, actor,
                country, language, introduction, &score) == 13) {
    struct Ticket* ticket = malloc(sizeof(struct Ticket));
    strcpy(ticket->seat_number, seat_number);
    strcpy(ticket->key, key);

    strcpy(ticket->movie_times->time, time);
    strcpy(ticket->movie_times->cinema, cinema);
    ticket->movie_times->price = price;

    strcpy(ticket->movie_times->movie->name, name);
    ticket->movie_times->movie->year = year;
    strcpy(ticket->movie_times->movie->director, director);
    strcpy(ticket->movie_times->movie->actor, actor);
    strcpy(ticket->movie_times->movie->country, country);
    strcpy(ticket->movie_times->movie->language, language);
    strcpy(ticket->movie_times->movie->introduction, introduction);
    ticket->movie_times->movie->score = score;

    insertAtTail(&head, ticket);
  }
  return head;
}

void printTicketList(Node* head) {
  Node* current = head;
  while (current != NULL) {
    struct Ticket* ticket = (struct Ticket*) current->data;
    printf("%s %s %s %s %.2f %s %d %s %s %s %s %s %f\n", ticket->seat_number, ticket->key, ticket->movie_times->time, ticket->movie_times->cinema,
           ticket->movie_times->price, ticket->movie_times->movie->name, ticket->movie_times->movie->year,
           ticket->movie_times->movie->director, ticket->movie_times->movie->actor, ticket->movie_times->movie->country,
           ticket->movie_times->movie->language, ticket->movie_times->movie->introduction, ticket->movie_times->movie->score);
    current = current->next;
  }
}