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
