//
//  operatorTimeComplexity.c
//  C언어
//
//  Created by 심주흔 on 2022/03/02.
//



#include <stdio.h>
#include <time.h>


int main(void){
    clock_t start, end;
    int repeat, i;
    int num = 1;
    double duration;
    char operator;
    
    printf("연산을 선택하시오(+, -, *, /): ");
    scanf("%c" , &operator);
    
    printf("반복 횟수를 입력하시오: ");
    scanf("%d" , &repeat);
    
    switch(operator){
        case '+':
            start = clock();
            for(i=1; i<=repeat; i++)
                num += i;
            end = clock();
            break;
            
        case '-':
            start = clock();
            for(i = 1; i<=repeat; i++){
                num -= i;
            }
            end = clock();
            break;
            
        case '*':
            start = clock();
            for(i = 1; i<=repeat; i++)
                num=num*i;
            end = clock();
            break;
            
        case '/':
            start = clock();
            for(i = 1; i<=repeat; i++){
                num = num/i;
            }
            end = clock();
            break;
            
        default:
            printf("지원되지 않는 연산지 입니다.\n");
            break;
    }
    duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("걸린시간 %f초 입니다.\n" , duration);
    
    return 0;
}

