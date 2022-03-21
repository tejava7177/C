//
//  binaryTreeTraersal.c
//  C언어
//
//  Created by 심주흔 on 2022/02/07.
//
//  이진트리의 전위 , 중위 , 후위 순회 알고리즘


#include <stdio.h>
#include <stdlib.h>         //동적 할당을 하기 위한 헤더파일
#include <time.h>           //난수 발생을 위한 헤더파일


//트리 구조체 생성
typedef struct TreeNode{
    int num;
    struct TreeNode *left, *right;
}TreeNode;

//트리가 비어 있을 새로운 노드 생성
TreeNode* new_node(int item){
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));  //동적할당
    temp->num = item;
    temp->left = temp->right = NULL;
    return temp;
}

//트리 삽입
TreeNode* insert_node(TreeNode* node,int num){
    if(node == NULL) return new_node(num);
    
    if(num < node->num){
        node->left = insert_node(node->left, num);
    }
    else if(num > node->num){
        node->right = insert_node(node->right, num);
    }
    
    return node;
}

//전위 순회
void pre_order(TreeNode* root){
    if(root != NULL){
        printf("%d->" , root->num);
        pre_order(root->left);
        pre_order(root->right);
    }
}
//중위 순회
void in_order(TreeNode * root){
    if(root != NULL){
        in_order(root->left);
        printf("%d->", root->num);
        in_order(root->right);
    }
}
//후위 순회
void post_order(TreeNode *root){
    if(root != NULL){
        post_order(root->left);
        post_order(root->right);
        printf("%d->", root->num);
    }
}

int main(void){
    TreeNode *root = NULL;              //트리 노드 생성
    int d[10];                          //데이터 담을 배열(구조체) 생성
    
    srand((unsigned)time(NULL));        //시간에 따른 난수 발생 함수
    
    
    for(int i = 0; i<10; i++){
        d[i] = rand()%100;              //난수 발생
        printf("%d " , d[i]);            //생성된 난수를 출력한다
        root = insert_node(root, d[i]);  //트리 삽입
    }
    
    printf("전위 순회 : ");
    pre_order(root);
    printf("\n\n");
    printf("중위 순회 : ");
    in_order(root);
    printf("\n\n");
    printf("후위 순회 : ");
    post_order(root);
    printf("\n\n");
    
    
    return 0;
}
