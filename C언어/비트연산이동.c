//
//  비트연산이동.c
//  C언어
//
//  Created by 심주흔 on 2021/12/31.
//  쉽게 풀어쓴 C언어 EXPRESS 5장 12번(page.222)
//  비트 이동 연산을 이용하여 문자 4개를 받아서 하나의 unsigned int 변수 안에 저장하는 프로그램
//  OR연산 : 두 개의 피연산자의 해당 비트 중 하나만 참이라도 참

/*
#include <stdio.h>

int main(void){
    
    char ch;
    unsigned int num = 0x00000000;
    
    //0부터 7 비트에 저장 (a = 61)
    printf("1st word : ");
    scanf("%c" , &ch);
    num = num | ch;
    getchar();
    
    //8부터 15 비트에 저장 (b = 62)
    printf("2nd word : ");
    scanf("%c" , &ch);
    num = num << 8;
    num = num | ch;
    getchar();
    
    //16부터 23 비트에 저장 (c = 63)
    printf("3rd word : ");
    scanf("%c" , &ch);
    num = num << 8;
    num = num | ch;
    getchar();
    
    //24부터 31 비트에 저장 (d = 64)
    printf("4th word : ");
    scanf("%c" , &ch);
    num = num << 8;
    num = num | ch;
    getchar();
    
    printf("result : %08x\n" , num);            //16진수로 출력
    return 0;
}
*/
