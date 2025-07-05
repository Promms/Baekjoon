#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    char item;
    struct _Node *left_child, *right_child;
}Node;

typedef struct _BinaryTree{
    Node* root;
}BinaryTree;

Node* findNode(Node* root, char item){
    if(root == NULL || root->item == item)
        return root;
    
    Node* foundNode = findNode(root->left_child, item);
    // 왼쪽에서 찾으면 반환하고 못 찾으면 오른쪽으로 넘어감
    if(foundNode != NULL)   return foundNode;

    return findNode(root->right_child, item);
}

Node* insert(char item){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->item = item;
    newNode->left_child = NULL;
    newNode->right_child = NULL;
    return newNode;
}

void insertNode(BinaryTree* tree, char mother, char left, char right){
    Node* motherNode;

    if(tree->root == NULL){
        // 입력되는 노드가 첫 번째 노드여서 root 일때
        tree->root = insert(mother);
        motherNode = tree->root;
    }else{
        // root가 아니면 이미 생성된 노드이므로 찾아서 가져옴
        motherNode = findNode(tree->root, mother);
    }
    
    if(motherNode != NULL){
        if(left != '.'){
            // '.'이 아닐 때 왼쪽 자식을 삽입
            motherNode->left_child = insert(left);
        }
        if(right != '.'){
            // '.'이 아닐 때 오른쪽 자식을 삽입
            motherNode->right_child = insert(right);
        }
    }
}

void removeNode(Node *node) {
  if (node == NULL) return;
  removeNode(node->left_child);
  removeNode(node->right_child);
  free(node);
}

void preOrder(Node* node){
    if (node == NULL)   return;
    printf("%c", node->item);
    preOrder(node->left_child);
    preOrder(node->right_child);
}

void inOrder(Node* node){
    if (node == NULL)   return;
    inOrder(node->left_child);
    printf("%c", node->item);
    inOrder(node->right_child);
}

void postOrder(Node* node){
    if (node == NULL)   return;
    postOrder(node->left_child);
    postOrder(node->right_child);
    printf("%c", node->item);
}

int main(){
    int num;
    char a, b, c;
    BinaryTree tree;
    tree.root = NULL;
    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        scanf(" %c %c %c", &a, &b, &c);
        insertNode(&tree, a, b, c);
    }

    preOrder(tree.root);
    printf("\n");
    inOrder(tree.root);
    printf("\n");
    postOrder(tree.root);

    removeNode(tree.root);
    return 0;
}