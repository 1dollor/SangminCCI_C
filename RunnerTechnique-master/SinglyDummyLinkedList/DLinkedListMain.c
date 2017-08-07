//
//  DLinkedListMain.c
//  SinglyDummyLinkedList
//
//  Created by 한상민 on 2017. 5. 24..
//  Copyright © 2017년 한상민. All rights reserved.
//

#include "DLinkedListMain.h"
#include "DLinkedList.h"
int main(int argc, char* argv[]){
    List list;
    int data;
    
    ListInit(&list);
    LInsert(&list, 11);
    LInsert(&list, 12);
    LInsert(&list, 13);
    LInsert(&list, 14);
    LInsert(&list, 21);
    LInsert(&list, 22);
    LInsert(&list, 23);
    LInsert(&list, 24);
    printf("현재 데이터의 수 : %d \n", LCount(&list));
    
    if (LFirst(&list, &data)) {
        printf("unsorted list : ");
        printf("%d ", data);
        
        while (LNext(&list, &data))
            printf("%d ", data);
    }
        printf("\n\n");
    
    if (LFirst(&list, &data)) {
        LSortList(&list);
        printf("sorted list : ");
        printf("%d ", data);
        
        while (LNext(&list, &data))
            printf("%d ", data);
    }
        printf("\n\n");
    return 0;
}
