//
//  timeComplexity.c
//  C언어
//
//  Created by 심주흔 on 2022/03/02.
//

#include <stdio.h>
#include <time.h>               //clock()함수를 담고 있는 라이브러리


void wayA(int a){
    int sum = 0;
    sum = a * a;                //a * a 값을 sum 변수에 저장
}

void wayB(int b){
    int sum = 0;
    int i;
    for(i = 0; i<b; i++)
        sum += b;               //b값을 b번 더한 값을 sum변수에 저장
}

void wayC(int c){
    int sum = 0;
    int i, j;
    for(i = 0; i<c; i++){
        for(j = 0; j < c; j++){         //c값까지 1씩 증가하는 것을 c만큼 반복하여 sum 변수에 저장
            sum += 1;
        }
    }
}


int main(void){
    clock_t start, end;
    double duration;
    int algorithm;
    int a;
    printf("알고리즘을 선택하십시오: (1,2,3): ");
    scanf("%d" , &algorithm);
    
    printf("숫자를 입력하세요: ");
    scanf("%d" , &a);
    
    if(algorithm == 1){
        start = clock();
        wayA(a);
        end = clock();
    }
    
    else if(algorithm == 2){
        start = clock();
        wayB(a);
        end = clock();
    }
    
    else if(algorithm == 3){
        start = clock();
        wayC(a);
        end = clock();
    }
    
    else
        printf("Error \n");
    
    duration = (double)(end - start) / CLOCKS_PER_SEC;
    
    
    printf("Time Complexity %f\n" , duration);
    return 0;
}
