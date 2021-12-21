//
//  main.c
//  C언어
//
//  Created by 심주흔 on 2021/12/22.
//  쉽게 풀어쓴 C언어 EXPRESS 2장 4번(page.88)


#include <stdio.h>


int main(void){
    
    int date = 1;
    
    printf("sun\tmon\ttue\twed\tthr\tfri\tsat\t\n");
    
    for(int i =0; i<=4; i++){
        for(int j = 0; j < 7; j++){
            //날짜가 31일까지 있다고 가정
            if (date <= 31) {
                printf("%d\t ", date);
                date++;
            }
            //date변수가 31을 초과하면 종료
            else{
                printf("\n");
                return 0;
            }
        }
        printf("\n");
    }
    return 0;
}
