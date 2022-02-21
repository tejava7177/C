//
//  윤년판단.c
//  C언어
//
//  Created by 심주흔 on 2021/12/31.
//  쉽게 풀어쓴 C언어 Express p.192(윤년 판단)
//  조건 1 : 연도가 4로 나누어 떨어진다.
//  조건 2 : 100으로 나누어 떨어지는 연도는 제외
//  조건 3 : 400으로 나누어 떨어지는 연도는 윤년이다.

/*
#include <stdio.h>

int main(void){
    
    int year = 0;
    //int result = 0;
    
    printf("Type year : ");
    scanf("%d" , &year);
    
    //result = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
    //printf("result = %d\n", result);               //1이면 윤년 , 0이면 평년
    
    if((((year % 4 == 0) && (year % 100 != 0))) || (year % 400 == 0))
        printf("True.\n");
    else
        printf("False.\n");
     
    return 0;
}
*/

