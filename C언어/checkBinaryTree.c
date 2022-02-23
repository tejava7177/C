//
//  checkBinaryTree.c
//  C언어
//
//  Created by 심주흔 on 2022/02/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
//#include <malloc.h>


typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
}TreeNode;

TreeNode* new_node(int item){
    TreeNode *temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode* insert_node(TreeNode* node, int data){
    if(node == NULL)
        return new_node(data);
    if(data < node->data){
        node->left = insert_node(node->left, data);
    }
    else if(data > node->data){
        node->right = insert_node(node->right, data);
    }
    return node;
}

int get_node_count(TreeNode *node){
    int count = 0;
    if(node != NULL){
        count = 1 + get_node_count(node->left) + get_node_count(node->right);
    }
    return count;
}

bool checkTree(TreeNode* root, int index, int nCount){
    if (root == NULL){
        return (true);
    }
    if(index > nCount){
        return (false);
    }
    return (checkTree(root->left, 2*index + 1, nCount)&&checkTree(root->right, index + 2, nCount));
}

int main(void){
    TreeNode * root = NULL;
    TreeNode n;
    int index = 0;
        
    srand((unsigned)time(NULL));
    
    for(int i = 0; i<6; i++){
        n.data = rand()%50;
        root = insert_node(root, n.data);
        printf("%d /" , n.data);
    }
    printf("\n");
    
    if(checkTree(root, index, get_node_count(root)))
        printf("True about Binary Tree\n");
    else
        printf("False about Binary Tree\n");
    
    
    return 0;
}
