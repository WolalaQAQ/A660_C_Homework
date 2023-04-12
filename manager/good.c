//
// Created by Adminstrator on 2023/3/21.
//
#include "good.h"

FILE* readGoodFile() {
  FILE* file = fopen("./data/good.txt", "r");
  if (file == NULL) {
    printf("File does not exist. Creating new file...\n");
    file = fopen("./data/good.txt", "w");
    if (file == NULL) {
      printf("Failed to create file.\n");
      exit(1);
    }
  }
  return file;
}

void writeGoodFile(struct Good* good) {
  FILE* file = fopen("./data/good.txt", "a+");
  if (file == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }
  fprintf(file, "%d %s %s %f", good->type, good->name, good->description, good->price);
}

Node* getGoodList(FILE* good_file) {
  Node* head = NULL;
  enum GoodType type;
  char name[50];
  char description[200];
  float price;
  while (fscanf(good_file, "%d %s %s %f", &type, name, description, &price) == 4) {
    struct Good* good = malloc(sizeof(struct Good));
    good->type = type;
    strcpy(good->name, name);
    strcpy(good->description, description);
    good->price = price;
    insertAtTail(&head, good);
  }
  return head;
}

void printGoodList(Node* head, enum GoodType type) {
  Node* current = head;
  while (current != NULL) {
    struct Good* good = (struct Good*)current->data;
    if(good->type != type) {
      current = current->next;
      continue;
    }
    printf("%s %s %.2f\n", good->name, good->description, good->price);
    current = current->next;
  }
}