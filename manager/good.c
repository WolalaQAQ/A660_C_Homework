//
// Created by Adminstrator on 2023/3/21.
//
#include "good.h"

// 打开商品信息文件，并返回文件指针
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

 // 打开商品信息文件，并在文件末尾写入商品信息
void writeGoodFile(struct Good* good) {
  FILE* file = fopen("./data/good.txt", "a+");
  if (file == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }
  fprintf(file, "%d %s %s %f", good->type, good->name, good->description, good->price);
}

// 以覆盖和读取方式打开信息
void overWriteGoodFile(Node* head) {
  FILE* file = fopen("./data/good.txt", "w");
  if (file == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }

  // 将所有信息写入文件
  Node* current = head;
  while (current != NULL) {
    struct Good* good = (struct good*) current->data;
    fprintf(file, file, "%d %s %s %f", good->type, good->name, good->description, good->price);
    current = current->next;
  }
  fclose(file);
}


// 从文件中读取商品信息，并将商品信息存储在链表中
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
// 遍历链表，并打印商品信息
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

//在链表中查找特定物品节点
int findGoodNode(Node* head, struct Good* good) {
  Node* current = head;
  int index = 0;
  while (current != NULL) {
        struct Good* current_good = (struct Good*)current->data;
        if (strcmp(current_good->name, good->name) == 0) {
          return index;
        }
        current = current->next;
        index++;
  }
  return -1;
}

//读取物品信息
FILE* readGoodTimesFile() {
  FILE* file = fopen("./data/good_times.txt", "r");
  if (file == NULL) {
        printf("File does not exist. Creating new file...\n");
        file = fopen("./data/good_times.txt", "w");
        if (file == NULL) {
      printf("Failed to create file.\n");
      exit(1);
        }
  }
  return file;
}

//进行信息比较
float compareGoodNode(struct Good* good1, struct Good* good2, enum GoodSortType sort_type) {
  switch(sort_type) {
        case GOOD_SORT_BY_name:
          return good1->name - good2->name;
          break;
        case Good_SORT_BY_price_ASC:
          return good1->price - good2->price;
          break;
        case Good_SORT_BY_price_DESC:
          return good2->price - good1->price;
          break;
        default:
          return 0;
  }
}

//进行排序
void sortGoodList(Node** head, enum GoodSortType sort_type) {
  Node* current = *head;
  Node* index = NULL;
  struct Good* temp;
  if (*head == NULL) {
        return;
  } else {
        while (current != NULL) {
          index = current->next;
          while (index != NULL) {
            if (compareGoodNode((struct Good*)current->data,
                                 (struct Good*)index->data, sort_type) > 0) {
              temp = (struct Good*)current->data;
              current->data = index->data;
              index->data = temp;
            }
            index = index->next;
          }
          current = current->next;
        }
  }
}

//删除物品信息
#include <stdio.h>

int deleteGoodFile(int id) {
  // Open the file for reading and writing
  FILE* fp = fopen("./data/good.txt", "r+");
  if (fp == NULL) {
    printf("Error: cannot open file\n");
    return -1;
  }

  // Read each line from the file and delete the line that matches the ID
  char line[100];
  int found = 0;
  while (fgets(line, sizeof(line), fp) != NULL) {
    int cur_id;
    sscanf(line, "%d", &cur_id);
    if (cur_id == id) {
      found = 1;
      continue; // skip the line with the matching ID
    }
    fprintf(fp, "%s", line);
  }

  // Close the file
  fclose(fp);

  if (found) {
    printf("Product with ID %d deleted successfully.\n", id);
    return 0;
  } else {
    printf("Error: product with ID %d not found.\n", id);
    return -1;
  }
}
