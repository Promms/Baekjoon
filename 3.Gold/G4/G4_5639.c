#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Node{
    int item;
    struct _Node *left, *right;
}Node;

Node* insert(Node* root, int target){
    if(root == NULL){
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->item = target;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if(root->item > target)
        root->left = insert(root->left, target);
    else if(root->item < target)
        root->right = insert(root->right, target);

    return root;
}

void deleteNode(Node* root){
    if(root == NULL)    return;
    deleteNode(root->left);
    deleteNode(root->right);
    free(root);
}

void postOrder(Node* node){
    if (node == NULL)   return;
    postOrder(node->left);
    postOrder(node->right);
    printf("%d\n", node->item);
}

int main(){
    int num;
    Node* root = NULL;

    while(scanf(" %d", &num) != EOF){
        root = insert(root, num);
    }

    postOrder(root);
    deleteNode(root);

    return 0;
}