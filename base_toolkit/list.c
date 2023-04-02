//
// Created by wolala on 2023/3/21.
//

/**
 * @brief 双向链表,实现了链表的基本操作
 * @author wolala
 * @date 2023/3/21
 * @version 1.0
 */

#include "list.h"

/**
 * 创建一个节点
 * @param data 节点数据
 * @return 节点
 */

ListNode* createListNode(void* data) {
    ListNode* node = (ListNode*) malloc(sizeof(ListNode));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

/**
 * 初始化一个链表
 * @return 链表头节点
 */

ListNode* initList() {
    ListNode* head = createListNode(NULL);
    head->next = head;
    head->prev = head;
    return head;
}

/**
 * 将节点插入到链表尾部
 * @param head 链表头节点
 * @param data 节点数据
 */

void nodePushBack(ListNode* head, void* data) {
    ListNode* node = createListNode(data);
    node->next = head;
    node->prev = head->prev;
    head->prev->next = node;
    head->prev = node;
}

/**
 * 将节点插入到链表头部
 * @param head 链表头节点
 * @param data 节点数据
 */

void nodePushFront(ListNode* head, void* data) {
    ListNode* node = createListNode(data);
    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;
}

/**
 * 将节点插入到链表中间
 * @param head 链表头节点
 * @param data 节点数据
 * @param index 节点位置
 */

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

/**
 * 删除链表中的节点
 * @param head 链表头节点
 * @param index 节点位置
 */

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

/**
 * 链表清空
 * @param head 链表头节点
 */

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

/**
 * 链表反转
 * @param head 链表头节点
 */

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

/**
 * 链表排序
 * @param head 链表头节点
 * @param compare 比较函数
 */

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

/**
 * 查找链表中是否存在某个节点
 * @param head 链表头节点
 * @param data 节点数据
 * @return 是否存在
 */

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

/**
 * 查找存储对应数据的链表节点
 * @param head
 * @param data
 * @return
 */

ListNode* nodeFindNode(ListNode* head, void* data) {
    ListNode* p = head->next;
    while (p != head) {
        if (p->data == data) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

/**
 * 获取链表中节点的个数
 * @param head 链表头节点
 * @return 节点个数
 */

int nodeSize(ListNode* head) {
    ListNode* p = head->next;
    int size = 0;
    while (p != head) {
        size++;
        p = p->next;
    }
    return size;
}