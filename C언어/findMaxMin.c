//
//  findMaxMin.c
//  C언어
//
//  Created by 심주흔 on 2022/02/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    
    int num[10];
    int max, min;
   
    srand((unsigned)time(NULL));
    
    for(int i =0; i<10; i++){
        num[i] = rand()%100+1;
        printf("%d  ", num[i]);
    }
    printf("\n");
    
    max = num[0];
    min = num[0];
    
    for(int i = 0 ; i<9; i++){
        if(max < num[i+1]){
            max = num[i+1];
        }
    }
    
    for(int i = 0 ; i<9; i++){
        if(min > num[i+1]){
            min = num[i+1];
        }
    }
    
    printf("MAX = %d\n" , max);
    printf("MIN = %d\n" , min);
    
    return 0;
}
