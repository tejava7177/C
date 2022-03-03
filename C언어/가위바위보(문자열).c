//
//  가위바위보.c
//  C언어
//
//  Created by 심주흔 on 2021/12/31.
//  쉽게 풀어쓴 C언어 Express 6장 4번(p.258)
//  swicth-case문에서 문자열은 사용할 수 없다.
//  난수 발생  srand((unsigned)time(NULL))

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main(void){
    
    char user[10];                                  //사용자가 낼 것
    int com;                                        //컴퓨터가 낼 것
    int userChoice;                                 //문자열을 정수형으로 변환 후 담을 변수
    
    printf("Type (Scissors / Rock / Paper) : ");
    scanf("%s" , user);                             //사용자로부터 문자열을 입력받음.
    
    //사용자가 Scissors라고 입력하면 정수형 변수에 1을 저장한다.
    if(strcmp(user , "Scissors") == 0){
        printf("User Choice Scissors\n");
        userChoice = 1;
    }
    
    //사용자가 Rock이라고 입력하면 정수형 변수에 2를 저장한다.
    else if(strcmp(user , "Rock") == 0){
        printf("User Choice Rock\n");
        userChoice = 2;
    }
    //사용자가 Paper이라고 입력하면 정수형 변수에 3을 저장한다.
    else if(strcmp(user , "Paper") == 0){
        printf("User Choice Paper\n");
        userChoice = 3;
    }
    //잘못입력하면 프로그램을 종료한다.
    else{
        printf("Wrong Choice\n");
        return 0;
    }
    //컴퓨터가 낼 것을 난수를 발생시켜 저장한다.
    srand((unsigned)time(NULL));
    com = rand()%3+1;               //난수 발생
    
    //컴퓨터가 결정한 것을 출력
    if(com == 1){
        printf("Computer's Choice : Scissors\n");
    }
    else if(com == 2){
        printf("Computer's Choice : Rock\n");
    }
    else{
        printf("Computer's Choice : Paper\n");
    }
    
    //가위바위보 비교하는 과정
    //비김
    if(userChoice == com){
        printf("Draw\n");
    }
    //가위 vs 주먹
    else if(userChoice == 1 && com == 2){
        printf("Computer Win!\n");
        printf("You Lose!\n");
    }
    //가위 vs 보
    else if(userChoice == 1 && com == 3){
        printf("You Win!\n");
        printf("Computer Lose!\n");
    }
    //주먹 vs 가위
    else if(userChoice == 2 && com == 1){
        printf("You Win!\n");
        printf("Computer Lose!\n");
    }
    //주먹 vs 보
    else if(userChoice == 2 && com == 3){
        printf("Computer Win!\n");
        printf("You Lose!\n");
    }
    //보 vs 주먹
    else if(userChoice == 3 && com == 2){
        printf("You Win!\n");
        printf("Computer Lose!\n");
    }
    //보 vs 가위
    else if(userChoice == 3&& com == 1){
        printf("Computer Win!\n");
        printf("You Lose!\n");
    }
    return 0;
}


