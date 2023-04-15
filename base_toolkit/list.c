#include "list.h"



// 在链表头插入一个新节点
void insertAtHead(Node** headRef, void* data) {
  // 创建一个新节点
  Node* newNode = (Node*) malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = *headRef;

  // 将新节点作为链表头
  *headRef = newNode;
}

// 在链表尾插入一个新节点
void insertAtTail(Node** headRef, void* data) {
  // 创建一个新节点
  Node* newNode = (Node*) malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  // 如果链表为空，则将新节点作为链表头
  if (*headRef == NULL) {
    *headRef = newNode;
    return;
  }

  // 找到链表的最后一个节点
  Node* lastNode = *headRef;
  while (lastNode->next != NULL) {
    lastNode = lastNode->next;
  }

  // 将新节点插入到链表尾部
  lastNode->next = newNode;
}

// 在指定位置插入一个新节点
void insertAtIndex(Node** headRef, int index, void* data) {
  // 创建一个新节点
  Node* newNode = (Node*) malloc(sizeof(Node));
  newNode->data = data;

  // 如果插入位置为0，则将新节点作为链表头
  if (index == 0) {
    newNode->next = *headRef;
    *headRef = newNode;
    return;
  }

  // 找到要插入位置的前一个节点
  Node* prevNode = *headRef;
  for (int i = 0; i < index - 1; i++) {
    prevNode = prevNode->next;
    if (prevNode == NULL) {
      printf("Error: Index out of range\n");
      return;
    }
  }

  // 将新节点插入到指定位置
  newNode->next = prevNode->next;
  prevNode->next = newNode;
}

// 删除链表中第一个出现的指定节点
void deleteNode(Node** headRef, void* data) {
  // 如果链表为空，则无法删除
  if (*headRef == NULL) {
    return;
  }

  // 如果要删除的节点是链表头，则将链表头指向下一个节点
  if ((*headRef)->data == data) {
    *headRef = (*headRef)->next;
    return;
  }

  // 找到要删除节点的前一个节点
  Node* prevNode = *headRef;
  while (prevNode->next != NULL && prevNode->next->data != data) {
    prevNode = prevNode->next;
  }

  // 如果找到了要删除的节点，则将其从链表中删除
  if (prevNode->next != NULL) {
    Node* deletedNode = prevNode->next;
    prevNode->next = deletedNode->next;
    free(deletedNode);
  }
}

// 删除链表中指定位置的节点
void deleteNodeByIndex(Node** headRef, int index) {
  // 如果链表为空，则无法删除
  if (*headRef == NULL) {
    return;
  }

  // 如果要删除的节点是链表头，则将链表头指向下一个节点
  if (index == 0) {
    *headRef = (*headRef)->next;
    return;
  }

  // 找到要删除节点的前一个节点
  Node* prevNode = *headRef;
  for (int i = 0; i < index - 1; i++) {
    prevNode = prevNode->next;
    if (prevNode == NULL) {
      printf("Error: Index out of range\n");
      return;
    }
  }

  // 如果找到了要删除的节点，则将其从链表中删除
  if (prevNode->next != NULL) {
    Node* deletedNode = prevNode->next;
    prevNode->next = deletedNode->next;
    free(deletedNode);
  }
}

// 获取链表的长度
int getListLength(Node* head) {
  int len = 0;
  Node* currNode = head;
  while (currNode != NULL) {
    len++;
    currNode = currNode->next;
  }
  return len;
}

// 释放链表中所有节点的内存
void freeList(Node* head) {
  Node* currNode = head;
  while (currNode != NULL) {
    Node* nextNode = currNode->next;
    free(currNode);
    currNode = nextNode;
  }
}