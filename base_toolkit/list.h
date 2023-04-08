//
// Created by wolala on 2023/3/21.
//

#ifndef A660_C_HOMEWORK_LIST_H
#define A660_C_HOMEWORK_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 定义单向链表节点的结构体
typedef struct Node {
  void* data;           // 节点的值的指针
  struct Node* next;  // 指向下一个节点的指针
}Node;

void insertAtHead(struct Node** headRef, void* data);
void insertAtTail(struct Node** headRef, void* data);
void insertAtIndex(struct Node** headRef, int index, void* data);
void deleteNode(struct Node** headRef, void* data);
int length(struct Node* head);
void freeList(struct Node* head);

#endif  // A660_C_HOMEWORK_LIST_H
