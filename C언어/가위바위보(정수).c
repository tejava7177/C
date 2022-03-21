//
//  가위바위보.c
//  C언어
//
//  Created by 심주흔 on 2021/12/31.
//  쉽게 풀어쓴 C언어 Express 6장 4번(p.258)


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Scissors 1
#define Rock 2
#define Paper 3

int main(void){
    
    int user;
    int com;
    
    printf("Choose (1 : Scissors 2 : Rock 3 : Paper) : ");
    scanf("%d" , &user);
    
    srand((unsigned)time(NULL));
    com = rand()%3+1;
    printf("Computer's Choice : %d\n" , com);
    
    
    if(user == com){
        printf("Draw\n");
    }
    else if(user == 1 && com == 2){
        printf("Computer Win!\n");
        printf("You Lose!\n");
    }
    else if(user == 1 && com == 3){
        printf("You Win!\n");
        printf("Computer Lose!\n");
    }
    else if(user == 2 && com == 1){
        printf("You Win!\n");
        printf("Computer Lose!\n");
    }
    else if(user == 2 && com == 3){
        printf("Computer Win!\n");
        printf("You Lose!\n");
    }
    else if(user == 3 && com == 2){
        printf("You Win!\n");
        printf("Computer Lose!\n");
    }
    else if(user == 3&& com == 1){
        printf("Computer Win!\n");
        printf("You Lose!\n");
    }
    
    return 0;
}
