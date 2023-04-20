//
// Created by Adminstrator on 2023/3/21.
//

#include "movie.h"
//类似于票据或凭证的唯一标识
void generateKey(struct Ticket* ticket) {
  int i;
  for (i = 0; i < 10; i++) {
    ticket->key[i] = rand() % 10;
  }
}

// 打开电影信息文件
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
 // 以追加和读取方式打开电影信息文件
void writeMovieFile(struct Movie* movie) {
  FILE* file = fopen("./data/movie.txt", "a+");
  if (file == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }
  // 将电影信息写入文件
  fprintf(file, "%s %d %s %s %s %s %s %f\n", movie->name, movie->year,
          movie->director, movie->actor, movie->country, movie->language,
          movie->introduction, movie->score);
  fclose(file);
}

 // 以覆盖和读取方式打开电影信息文件
void overWriteMovieFile(Node* head) {
  FILE* file = fopen("./data/movie.txt", "w");
  if (file == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }
  // 将所有电影信息写入文件
  Node* current = head;
  while (current != NULL) {
    struct Movie* movie = (struct Movie*) current->data;
    fprintf(file, "%s %d %s %s %s %s %s %f\n", movie->name, movie->year,
            movie->director, movie->actor, movie->country, movie->language,
            movie->introduction, movie->score);
    current = current->next;
  }
  fclose(file);
}


//提供了一种从文件中读取电影信息的方法，并将这些信息以链表的形式进行存储，便于系统后续对电影信息的操作。
Node* getMovieList(FILE* movie_file) {
  Node* head = NULL;
  char name[100], director[500], actor[500], country[15], language[15], introduction[1000];
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

 // 遍历链表并打印电影信息
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

//在链表中查找特定电影节点
int findMovieNode(Node* head, struct Movie* movie) {
  Node* current = head;
  int index = 0;
  while (current != NULL) {
        struct Movie* current_movie = (struct Movie*)current->data;
        if (strcmp(current_movie->name, movie->name) == 0) {
          return index;
        }
        current = current->next;
        index++;
  }
  return -1;
}

float compareMovieNode(struct Movie* movie1, struct Movie* movie2, enum MovieSortType sort_type) {
  switch(sort_type) {
        case MOVIE_SORT_BY_YEAR_ASC:
          return movie1->year - movie2->year;
          break;
        case MOVIE_SORT_BY_YEAR_DESC:
          return movie2->year - movie1->year;
          break;
        case MOVIE_SORT_BY_SCORE_ASC:
          return movie1->score - movie2->score;
          break;
        case MOVIE_SORT_BY_SCORE_DESC:
          return movie2->score - movie1->score;
          break;
        default:
          return 0;
  }
}

void sortMovieList(Node** head, enum MovieSortType sort_type) {
  Node* current = *head;
  Node* index = NULL;
  struct Movie* temp;
  if (*head == NULL) {
        return;
  } else {
        while (current != NULL) {
          index = current->next;
          while (index != NULL) {
            if (compareMovieNode((struct Movie*)current->data,
                                 (struct Movie*)index->data, sort_type) > 0) {
              temp = (struct Movie*)current->data;
              current->data = index->data;
              index->data = temp;
            }
            index = index->next;
          }
          current = current->next;
        }
  }
}

//读取电影场次信息
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

//以MovieTimes结构体类型的变量写入到文件中
void writeMovieTimesFile(struct MovieTimes* movie_times) {
  FILE* file = fopen("./data/movie_times.txt", "a+");
  if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
  }
  fprintf(file, "%s %s %f %d %s %d %s %s %s %s %s %f\n",
          movie_times->time, movie_times->cinema, movie_times->price, movie_times->seat_remain,
          movie_times->movie->name, movie_times->movie->year, movie_times->movie->director, movie_times->movie->actor,
          movie_times->movie->country, movie_times->movie->language, movie_times->movie->introduction, movie_times->movie->score);
  fclose(file);
}

//从文件中读取电影场次信息并存储在一个链表中
Node* getMovieTimesList(FILE* movie_times_file) {
  Node* head = NULL;
  //电影场次信息临时变量
  char time[30], cinema[30];
  float price;
  int seat_remain;
  //电影信息临时变量
  char name[20];
  int year;
  char director[500];
  char actor[500];
  char country[15];
  char language[15];
  char introduction[1000];
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

//打印一个电影场次信息的链表中每个节点的数据
void printMovieTimesList(Node* head) {
  Node* current = head;
  while (current != NULL) {
    struct MovieTimes* movie_times = (struct MovieTimes*) current->data;
    printf("%s %s %s %.2f %d\n", movie_times->movie->name, movie_times->time, movie_times->cinema, movie_times->price, movie_times->seat_remain);
    current = current->next;
  }
}

//读取保存电影票信息的文本文件 
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

//将一个电影票的信息写入文件中
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

//读取电影票信息并将其存储在一个链表中并返回该链表的头节点指针
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
  char director[500];
  char actor[500];
  char country[15];
  char language[15];
  char introduction[1000];
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

//打印电影票链表
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


