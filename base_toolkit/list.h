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
} Node;

void insertAtHead(Node** headRef, void* data);
void insertAtTail(Node** headRef, void* data);
void insertAtIndex(Node** headRef, int index, void* data);
void deleteNode(Node** headRef, void* data);
void deleteNodeByIndex(Node** headRef, int index);
int getListLength(Node* head);
void freeList(Node* head);

#endif  // A660_C_HOMEWORK_LIST_H
