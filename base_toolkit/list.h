//
// Created by wolala on 2023/3/21.
//

#ifndef A660_C_HOMEWORK_LIST_H
#define A660_C_HOMEWORK_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode{
    void* data;
    struct ListNode* next;
    struct ListNode* prev;
}ListNode;

ListNode* createListNode(void* data);
ListNode* initList();
void nodePushBack(ListNode* head, void* data);
void nodePushFront(ListNode* head, void* data);
void nodeInsert(ListNode* head, void* data, int index);
void nodeDelete(ListNode* head, int index);
void nodeClear(ListNode* head);
void nodeReverse(ListNode* head);
void nodeSort(ListNode* head, int (*compare)(void*, void*));
bool nodeFind(ListNode* head, void* data);
int nodeSize(ListNode* head);

#endif  // A660_C_HOMEWORK_LIST_H
