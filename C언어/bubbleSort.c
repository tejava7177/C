//
//  bubbleSort.c
//  C언어
//
//  Created by 심주흔 on 2022/02/24.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode{
    element data;
    struct ListNode* link;
}ListNode;

void error(char * message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}

ListNode* insert_first(ListNode *head, element value){
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

ListNode* delete_first(ListNode* head){
    ListNode* removed;
    if(head == NULL){
        return NULL;
    }
    removed = head;
    head = removed->link;
    free(removed);
    return head;
}

void print_list(ListNode * head){
    ListNode *p = head;
    printf("%d" , p->data);
    p = p->link;
    
    for(p; p!=NULL; p=p->link){
        printf("->%d" , p->data);
    }
    printf("\n");
}


void bubble_sort(ListNode * head, int nCount){
    ListNode * p = head;
    int i, temp;
    
    for(i = 0; i<nCount; i++){
        for(p=head; p->link != NULL; p=p->link){
            if(p->data > p->link->data){
                temp = p->data;
                p->data = p->link->data;
                p->link->data = temp;
            }
        }
    }
}

int main(void){
    ListNode * head = NULL;
    int i, temp;
    int nCount = 0;
    
    srand((unsigned)time(NULL));
    
    printf("BubbleSort\n");
    for(i = 0; i <= 7; i++){
        temp = rand()%50 + 1;
        head = insert_first(head, temp);
        nCount++;
    }
    
    bubble_sort(head, nCount);
    print_list(head);
    
    for(i = 0; i < nCount; i++){
        head = delete_first(head);
    }
    return 0;
}
