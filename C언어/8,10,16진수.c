//
//  temp.c
//  C언어
//
//  Created by 심주흔 on 2021/12/24.
//  쉽게 풀어쓴 C언어 EXPRESS 4장 2번(page.168)
//  16진수를 입력 받아서 8진수, 10진수, 16진수로 변환하는 프로그램


#include <stdio.h>

int main(void){
    
    int data;
    printf("Type Hexadecimal :");
    scanf("%x" , &data);                //16진수를 입력 받음
    
    //8진수와 16진수를 출력할 떄는 #이 붙음.
    //#을 붙이지 않을 경우 0 / 0x값이 출력되지 않아 정확한 값이 아님.
    printf("8진수 : %#o\n", data);         //8진수 출력 oct
    printf("10진수 : %d\n", data);        //10진수 출력 decade
    printf("16진수 : %#x\n", data);        //16진수 출력 hex
    
    return 0;
}
