//
// Created by Adminstrator on 2023/3/21.
//
#include "list.h"

ListNode* createListNode(void* data) {
    ListNode* node = (ListNode*) malloc(sizeof(ListNode));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

ListNode* initList() {
    ListNode* head = createListNode(NULL);
    head->next = head;
    head->prev = head;
    return head;
}

void nodePushBack(ListNode* head, void* data) {
    ListNode* node = createListNode(data);
    node->next = head;
    node->prev = head->prev;
    head->prev->next = node;
    head->prev = node;
}

void nodePushFront(ListNode* head, void* data) {
    ListNode* node = createListNode(data);
    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;
}

void nodeInsert(ListNode* head, void* data, int index) {
    ListNode* node = createListNode(data);
    ListNode* p = head->next;
    int i = 0;
    while (p != head) {
        if (i == index) {
            node->next = p;
            node->prev = p->prev;
            p->prev->next = node;
            p->prev = node;
            return;
        }
        p = p->next;
        i++;
    }
}

void nodeDelete(ListNode* head, int index) {
    ListNode* p = head->next;
    int i = 0;
    while (p != head) {
        if (i == index) {
            p->prev->next = p->next;
            p->next->prev = p->prev;
            free(p);
            return;
        }
        p = p->next;
        i++;
    }
}

void nodeClear(ListNode* head) {
    ListNode* p = head->next;
    while (p != head) {
        ListNode* q = p->next;
        free(p);
        p = q;
    }
    head->next = head;
    head->prev = head;
}

void nodeReverse(ListNode* head) {
    ListNode* p = head->next;
    while (p != head) {
        ListNode* q = p->next;
        p->next = p->prev;
        p->prev = q;
        p = q;
    }
    ListNode* temp = head->next;
    head->next = head->prev;
    head->prev = temp;
}

void nodeSort(ListNode* head, int (*compare)(void*, void*)) {
    ListNode* p = head->next;
    while (p != head) {
        ListNode* q = p->next;
        while (q != head) {
            if (compare(p->data, q->data) > 0) {
                void* temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            q = q->next;
        }
        p = p->next;
    }
}

bool nodeFind(ListNode* head, void* data) {
    ListNode* p = head->next;
    while (p != head) {
        if (p->data == data) {
            return true;
        }
        p = p->next;
    }
    return false;
}

int nodeSize(ListNode* head) {
    ListNode* p = head->next;
    int size = 0;
    while (p != head) {
        size++;
        p = p->next;
    }
    return size;
}