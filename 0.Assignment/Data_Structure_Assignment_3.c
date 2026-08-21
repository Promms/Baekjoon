#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NUM 100

typedef struct _Node {
  bool isTerminal;
  struct _Node * children[26];
  int wordCount; // 현재 노드 위치 이후에 완성되는 단어의 갯수를 저장
} Node;

int N;

Node* createLeaf(bool _isTerminal);
Node* Insert(Node* root, char* word);
Node* Delete(Node* root, char* word);
int Find(Node* root, char* word);
void Print(Node* root, char* word, int count);

int main() {
    Node *root = createLeaf(false);
    char op[10];   // 입력을 위한 string
    char word[MAX_NUM]; // 출력을 위한 string

    scanf("%d", &N);
    while(N--){
        scanf("%s", op);
        if(strcmp(op, "insert") == 0){
            // insert
            scanf("%s", op);
            // 중복 단어가 들어오면 insert가 작동하지 않도록 함
            if(Find(root, op) == -1){
                root = Insert(root, op);
            }
        } else if(strcmp(op, "delete") == 0){
            // delete
            scanf("%s", op);
            // 존재하지 않는 단어가 들어오면 delete가 작동하지 않도록 함
            if(Find(root, op) != -1)
                Delete(root, op);
        } else if(strcmp(op, "find") == 0){
            // find
            scanf("%s", op);
            printf("%d\n", Find(root, op));
        } else if(strcmp(op, "print") == 0){
            // print
            Print(root, word, 0);
            printf("\n");
        }
    }
    return 0;
}

Node* createLeaf(bool _isTerminal){
    Node* leafNode = (Node*)malloc(sizeof(Node));
    leafNode->isTerminal = _isTerminal;
    leafNode->wordCount = 0;
    for(int i = 0; i < 26; i++) {
        leafNode->children[i] = NULL;
    }
    return leafNode;
}

Node* Insert(Node* root, char* word){
    // 단어가 완성되었을 때
    if(*word == '\0'){
        // 이 노드에서 단어가 완성 되었다는 것을 표시
        root->isTerminal = true;
        root->wordCount++;
        return root;
    }

    int index = *word - 'a';
    // 다음 단어를 저장할 노드가 NULL이라면
    if(root->children[index] == NULL){
        // 노드를 미리 생성
        root->children[index] = createLeaf(false);
    }

    root->wordCount++;
    // 다음 노드로 재귀적으로 진행
    root->children[index] = Insert(root->children[index], word+1);
    return root;
}

Node* Delete(Node* root, char* word) {
    // Tree에 단어가 존재하지 않으면 Delete에 진입할 수 없도록 했기 때문에
    // 단어는 무조건 삭제된다.
    // 따라서 트리를 타고 내려가면서 wordCount를 1씩 줄이면서 내려감
    root->wordCount--;
    if(*word == '\0') {
        // 단어의 마지막에 도달했을 때
        if(root->wordCount >= 1) {
            // 현재 단어가 삭제하려는 단어 외의 다른 단어의 ancestor라면
            root->isTerminal = false; // 단어 완성 여부를 false로 변경
            return root;
        }else{
            // 현재 단어가 삭제하려는 단어 외의 다른 단어의 ancestor가 아니라면
            free(root); // 메모리 해제
            return NULL; // NULL을 반환해 그래프의 연결을 삭제
        }
    }

    // 다음 노드로 재귀적으로 진행
    root->children[*word - 'a'] = Delete(root->children[*word - 'a'], word + 1);
    return root; // 노드를 업데이트
}

int Find(Node* root, char* word){
    // 노드가 존재하지 않으면 -1 반환
    if(root == NULL)    return -1;

    // 단어 끝에 도달한 경우
    if(*word == '\0') {
        // 정확히 이 위치에서 단어가 끝나면 존재하는 단어
        if(root->isTerminal == true) return 0;
        // 단어 경로는 맞지만 완성된 단어가 아님
        return -1;
    }

    int count = 0;
    int index = *word - 'a';

    // 사전순 인덱스를 위해 현재 문자 이전의 wordCount 합산
    for(int i = 0; i < index; i++){
        if(root->children[i] != NULL)
            count += root->children[i]->wordCount;
    }

    // 다음 문자로 재귀적으로 진행
    int result = Find(root->children[index], word+1);

    // 단어가 존재하지 않으면 -1 반환
    // 존재하면 누적된 count와 함께 반환
    return (result == -1) ? -1 : count + result;
}

void Print(Node* root, char* word, int count){
    if(root == NULL)    return;
    // 현재 노드가 단어의 끝이면 문자열을 종료하고 출력
    if(root->isTerminal == true){
        word[count] = '\0';
        printf("%s ", word);
    }

    // 자식 노드로 내려가면서 단어를 이어 붙여 재귀 호출
    for(int i = 0; i < 26; i++){
        if(root->children[i] != NULL){
            word[count] = i + 'a';
            Print(root->children[i], word, count + 1);
        }
    }
}