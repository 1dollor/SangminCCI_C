//
//  Header.h
//  SinglyDummyLinkedList
//
//  Created by 한상민 on 2017. 5. 17..
//  Copyright © 2017년 한상민. All rights reserved.
//

#ifndef DLinkedList_h
#define DLinkedList_h

#define FALSE               0
#define TRUE                1

typedef int LData;
typedef struct _node{
    LData data;
    struct _node *next;
} Node;

typedef struct _linkedList {
    Node *head;
    Node *cur;
    Node *p1;
    Node *p2;
    Node *before;
    int numOfData; //저장된 데이터의 수를 기록
    int (*comp)(LData d1, LData d2); //정렬의 기준을 등록
} LinkedList;

typedef LinkedList List;

void ListInit(List *plist);
void LInsert(List *plist, LData data);
void FInsert(List *plist, LData data); 
void SInsert(List *plist, LData data);

int LFirst(List *plist, LData *data);
int LNext(List *plist, LData *data);
void LSortList(List *plist);

LData LRemove(List *plist);
int LCount(List *plist);

void SetSortRule(List *plist, int (*comp)(LData d1, LData d2));

#endif /* DLinkedList_h */
