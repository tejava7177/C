//
//  bubbleSort.c
//  C언어
//
//  Created by 심주흔 on 2022/02/24.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//항목 정의
typedef int element;

//노드 타입 정의
typedef struct ListNode{
    element data;               //구조체 데이터 저장
    struct ListNode* link;      //링크 노드 생성
}ListNode;                      //리스트 노드

//오류 처리 함수
void error(char * message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}

//리스트 첫 부분에 노드를 추가하는 함수
//리스트와 저장할 값을 매개변수로 받음
ListNode* insert_first(ListNode *head, element value){
    //노드를 동적할당하여 생성
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;        //데이터를 리스트에 저장
    p->link = head;         //헤드 포인터 값을 복사
    head = p;               //헤드 포인터 변경
    return head;            //변경된 헤드 포인터 반환
}

//노드를 해제하는 함수
ListNode* delete_first(ListNode* head){
    ListNode* removed;
    if(head == NULL){
        return NULL;
    }
    removed = head;             //삭제 할 노드 지정
    head = removed->link;
    free(removed);              //삭제 할 노드의 동적 메모리 반납
    return head;                //변경 된 헤드 포인터 반환
}

//리스트 출력 함수
//기존 리스트를 매개 변수로 지정
void print_list(ListNode * head){
    ListNode *p = head;         //헤드 포인터 지정
    printf("%d" , p->data);     //조건에 맞기 위해 출력
    p = p->link;                //다음 노드를 가리키도록 함
    
    //p포인터가 NULL포인터를 가리킬 떄까지 반복
    for(p; p!=NULL; p=p->link){
        printf("->%d" , p->data);
    }
    printf("\n");
}

//버블 정렬 알고리즘
void bubble_sort(ListNode * head, int nCount){
    ListNode * p = head;
    int i, temp;
    
    for(i = 0; i<nCount; i++){                  //데이터 수만큼 반복
        for(p=head; p->link != NULL; p=p->link){//p가 NULL을 가리킬 떄까지 반복
            if(p->data > p->link->data){        //데이터를 비교했을 때 후 데이터가 작으면 실행
                temp = p->data;                 //임시 저장변수에 데이터 저장
                p->data = p->link->data;        //데이터를 앞으로 보냄
                p->link->data = temp;           //임시 저장된 변수를 다음 노드에 저장
            }
        }
    }
}

int main(void){
    ListNode * head = NULL;             //구조체 선언
    int i, temp;                        //반복과 임시 저장 변수를 위한 선언
    int nCount = 0;                     //데이터 갯수를 세기 위한 변수 선언
    
    srand((unsigned)time(NULL));        //난수 발생을 위한 설정
    
    printf("BubbleSort\n");
    for(i = 0; i <= 7; i++){
        temp = rand()%50 + 1;           //난수 발생
        head = insert_first(head, temp);//발생한 난수를 리스트에 저장
        nCount++;
    }
    
    bubble_sort(head, nCount);
    print_list(head);                   //리스트 출력
    
    for(i = 0; i < nCount; i++){
        head = delete_first(head);      //리스트를 해제 시키는 함수 호출
    }
    
    return 0;
}
