
/*
   작성일 2021.09.17
   작성자 : 심주흔
   프로그램명 : 파일 속 인물 데이터 삽입, 삭제, 출력하는 프로그램
*/

#include <stdio.h>            //기본 구현을 위한 헤더파일
#include <stdlib.h>
//#include <malloc.h>

typedef struct student {      //구조체 생성
   int num;               //학번을 저장할 변수
   char name[100];            //이름을 저장할 변수
   int w;                  //몸무게를 저장할 변수
   float t;               //키를 저장할 실수형 변수
}student;                  //구조체 정의

typedef struct ListNode {      //리스트 생성
   student data;            //구조체 노드 생성
   struct ListNode *link;      //다음을 가리킬 링크 생성
}ListNode;                  //리스트 정의


//오류를 출력할 함수
void error(char *message) {
   fprintf(stderr, "%s\n", message);
}

//리스트를 출력하는 함수
void print_list(ListNode *head) {
   ListNode* p = head;
   int i = 1;                                             //항목의 개수를 출력하기 위한 변수 생성
   printf("\n===================학생 리스트 출력==============\n");
   for (p; p != NULL; p = p->link) {                           //헤드 포인터가 리스트의 끝을 가리킬 때까지 반복
      printf("%d  ", i);                                    //항목 구별을 위한 숫자 출력
      printf("%d      %15s  %6d  %6.1f\n", p->data.num, p->data.name, p->data.w, p->data.t);   //리스트 구조체 노드 하나에 해당하는 데이터 출력
      i++;                                             //항목 수 증가
   }
   printf("==================================================\n\n");   //개행문자 삽입
}

//리스트 삭제 함수

ListNode* delete(ListNode *head, int value){            //기존 리스트와 삭제할 값을 매개변수로 받는다.
   ListNode *pre = head;                           //리스트 제거를 위한 선행노드 생성
   ListNode *p = head;                              //헤드 포인터 생성
               
   if (value == p->data.num) {                        //삭제할 노드가 가장 앞에 있으면 실행
      head = p->link;                              //링크포인터를 헤드포인터로 지정
      printf(">> %s(%d)학생의모든 정보가  삭제되었습니다.\n", p->data.name, p->data.num);   //노드에 저장되어 있는 값이 삭제되었다는 문구 출력
      free(p);                                 //메모리 반납
      //return head;                              //헤드 포인터 반환
   }
   
   else {                                       //이외의 경우 실행
      for (pre; pre != NULL; pre = pre->link) {         //선행 노드가 끝을 가리킬 때까지 반복
         if (pre->link->data.num == value) {            //리스트를 돌면서 삭제할 학번과 데이터의 값이 같은 경우
            p = pre->link;                        //리스트 포인터를 선행노드로 이동시킴
            pre->link = p->link;                  //선행 노드의 링크를 포인터 이동
            printf(">> %s(%d)학생의모든 정보가  삭제되었습니다.\n", p->data.name, p->data.num);//삭제 확인 문구 출력
            free(p);                           //메모리반납
            //return head;                        //헤드 포인터 반환
         }
      }
   }
    return p;
}



//리스트 데이터 삽임 함수
ListNode* insert_first(ListNode *head, student value) {               //기존 리스트와 추가할 값을 매개변수를 받아온다.

   ListNode *p = (ListNode *)malloc(sizeof(ListNode));               //데이터를 담을 노드를 생성한다.
   p->data = value;                                       //값을 노드에 저장한다.
   p->link = head;                                          //리스트를 노드 뒤에 위치시킨다.
   head = p;                                             //포인터가 헤드를 가리키도록 한다.
   return head;                                          //헤드 포인터를 반환한다.

}

int main() {

   FILE *fp = NULL;                     //파일을 불러오기 위한 포인터 변수 선언
   student data;                        //구조체 선언
   ListNode *head = NULL;                  //리스트의 헤드 포인터 초기화

   char c;                              //파일에서부터 문자를 입력받기 위한 문자 변수 생성
   int temp =0 ;                        //임시 저장 변수 생성 및 초기화

   fp = fopen("student.txt", "r");            //"student.txt"파일을 읽기 모드로 연다.

   if (fp == NULL) {                     //파일이 존재하지 않는다면
      printf("error");                  //해당 문구 출력
      return 0;                        //종료
   }

   while (!feof(fp)) {                     //파일의 끝을 가리킬 때까지 반복

      fscanf(fp, "%c", &c);               //파일에서 문자 하나를 읽어와서 문자 변수에 저장
      
      switch (c)                        //c의 데이터에 따라 다른 조건문 실행
      {

      case 'i': {                        //"i"라면 실행
         fscanf(fp, "%d %s %d %f", &data.num, data.name, &data.w, &data.t);      //학번, 이름, 몸무게, 키를 파일로부터 받아옴
         head = insert_first(head, data);   //데이터를 리스트의 처음에 삽입하는 함수 호출
         printf(">> %s(%d)학생의모든 정보가  삽입되었습니다.\n", data.name, data.num);   //함수 동작 이후 해당 문구 출력
         break;                        //조건문 통과
      }

      case 'p': {                        //"p"라면 실행
         print_list(head);               //해당 리스트를 출력하는 함수 호출
         break;                        //조건문 통과
      }

      case 'd': {                        //"d"라면 실행
         fscanf(fp, "%d", &temp);         //파일에서 학번으로 추정되는 데이터를 임수 변수에 저장
         head = delete(head, temp);         //받아온 데이터를 바탕으로 리스트를 삭제하는 함수 호출
         break;                        //조건문 통과
      }

      default:
         break;

      }
   }

   fclose(fp);                           //파일 닫기
   return 0;

}
