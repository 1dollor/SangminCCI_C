//
//  main.c
//  SinglyDummyLinkedList
//
//  Created by 한상민 on 2017. 5. 17..
//  Copyright © 2017년 한상민. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List *list) {
    list->head = (Node*)malloc(sizeof(Node));
    list->p1 = (Node*)malloc(sizeof(Node));
    list->p2 = (Node*)malloc(sizeof(Node));
    list->numOfData = 0;
    list->comp = NULL;
    list->before = NULL;
}

void LInsert(List *plist, LData data) {
    if (plist->comp != NULL) {
        FInsert(plist, data);
    } else {
        SInsert(plist, data);
    }
}

void FInsert(List *plist, LData data) {
    Node * newNode = (Node*)malloc((sizeof(Node)));
    newNode->data = data;
    newNode->next = plist->head->next; //새 노드가 다른 노드를 더미노드를
    plist->head->next = newNode; //더미노드가 새 노드를 가리킴
    (plist->numOfData++);
}

void SInsert(List *plist, LData data) {
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    if (plist->head->next == NULL) {
        plist->head->next = newNode;
        plist->cur = plist->head->next;
        (plist->numOfData++);
        return;
    }
    
    plist->cur->next = newNode;
    plist->cur = plist->cur->next;
    (plist->numOfData++);
}

int LFirst(List *plist, LData *pdata) {
    if (plist->head->next == NULL) {
        return FALSE;
    }
    
    plist->before = plist->head;
    plist->cur = plist->head->next;
    plist->p1 = plist->cur->next->next;
    plist->p2 = plist->cur;
    *pdata = plist->cur->data;
    return TRUE;
}
/* 
 Dummy 노드를 가리키고 있는 Before 포인터를 그 다음 노드로 옮겨서 가리킨다.
 */
int LNext(List *plist, LData *pdata) {
    if (plist->cur->next == NULL) {
        return FALSE;
    }
    
    plist->before = plist->cur;
    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;
    return TRUE;
}

/* Runner Technique*/
void LSortList(List *plist) {
    while (plist->p2->next->next != NULL) {
        if (plist->p1->next == NULL || plist->p1->next->next == NULL) {
            plist->p1 = plist->head->next;
        } else {
            Node tempP1NextNode = *plist->p1->next;
            plist->p1->next = plist->p2;
            plist->p2->next = &tempP1NextNode;
            
//        LData temp = 0;
//        temp = plist->p2->data;
//        plist->p2->data = plist->p1->next->data;
//        plist->p1->next->data = temp;
//        plist->p1 = plist->p1->next->next;
//        plist->p2 = plist->p2->next;
    }
  }
}

LData LRemove (List *plist ){
    Node *rpos = plist->cur;
    LData rdata = rpos->data;
    
    plist->before->next = plist->cur->next;
    plist->cur = plist->before;
    
    free(rpos);
    (plist->numOfData)--;
    return rdata;
}

int LCount(List *plist) {
    return plist->numOfData;
}

//void setSortRule(List *plist, int (*comp)(LData d1, LData d2)) {
//
//}
