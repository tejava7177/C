
//  트리의 노드가 구조체의 형식을 가질 때
#include <stdio.h>
#include <stdlib.h>         //동적 할당을 하기 위한 헤더파일
#include <time.h>           //난수 발생을 위한 헤더파일

typedef struct data{
    int number;
}data;

typedef struct TreeNode{
    data num;
    struct TreeNode *left, *right;
}TreeNode;

TreeNode* new_node(data item){
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));  //동적할당
    temp->num = item;
    temp->left = temp->right = NULL;
    return temp;
}


TreeNode* insert_node(TreeNode* node, data num){
    if(node == NULL) return new_node(num);
    
    if(num.number < node->num.number){
        node->left = insert_node(node->left, num);
    }
    else if(num.number > node->num.number){
        node->right = insert_node(node->right, num);
    }
    
    return node;
}


void pre_order(TreeNode* root){
    if(root != NULL){
        printf("%d->" , root->num.number);
        pre_order(root->left);
        pre_order(root->right);
    }
}

void in_order(TreeNode * root){
    if(root != NULL){
        in_order(root->left);
        printf("%d->", root->num.number);
        in_order(root->right);
    }
}

void post_order(TreeNode *root){
    if(root != NULL){
        post_order(root->left);
        post_order(root->right);
        printf("%d->", root->num.number);
    }
}

int main(void){
    TreeNode *root = NULL;
    data d[10];
    int i;
    
    srand((unsigned)time(NULL));
    
    
    for(i = 0; i<10; i++){
        d[i].number = rand()%100;
        root = insert_node(root, d[i]);
    }
    
    pre_order(root);
    printf("\n\n");
    in_order(root);
    printf("\n\n");
    post_order(root);
    printf("\n\n");
    
    
    return 0;
}
