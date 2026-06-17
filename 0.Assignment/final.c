#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
// 4개는 필수로 사용

#define MAXN 100000

int cmp_int(const void *a, const void *b){
    int x = *(int*)a;
    int y = *(int*)b;
    return (x > y) - (x < y);

}
// qsort(arr, n, sizeof(int), cmp_int) 이렇게 qsort에서 사용할 수 있음

int binary_search(int* arr, int n, int t){
    int l = 0, r = n - 1;
    while(l <= r){
        int m = l + (r - l) / 2;
        if(arr[m] == t)
            return m;
        else if(arr[m] < t)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int binary_search_first(int* arr, int n, int t){
    int l = 0, r = n - 1;
    int ans = -1;
    while(l <= r){
        int m = l + (r - l) / 2;
        if (arr[m] == t){
            ans = m;
            r = m - 1; // first: 가장 먼저 등장하는 위치. 중복이 있을 수 있으니까 앞쪽만 추가 탐색
        }else if(arr[m] < t){
            l = m + 1;
        }else{
            r = m - 1;
        }
    }
    return ans;
}

int binary_search_greater(int *arr, int n, int t){
    int l = 0, r = n - 1;
    int ans = -1;
    while(l <= r){
        int m = l + (r - l) / 2;
        if(arr[m] > t){ // greater: t보다 커지는 그 시점을 찾아야 하기 때문에 t보다 큰 뒤쪽은 버리고 앞쪽으로 탐색
            ans = m;
            r = m - 1;
        }else{
            l = m + 1;
        }
    }
    return ans;
}

int heap[MAXN], hn;

void push(int v){
    int i = ++hn; // 힙을 한 칸 확장
    while(i > 1 && v < heap[i / 2]){ // 부모 노드보다 작으면
        heap[i] = heap[i / 2]; // 부모를 하나 내림
        i /= 2;
    }
    heap[i] = v; // 제자리를 찾았으면 삽입
}

int pop(){
    int ret = heap[1], last = heap[hn--];
    int p = 1, c = 2;
    while(c <= hn){
        if(c < hn && heap[c + 1] < heap[c])
            c++;
        if(last < heap[c])
            break;
        heap[p] = heap[c];
        p = c;
        c *= 2;
    }
    heap[p] = last;
    return ret;
}

#define MAXG 10
int stack[MAXG * 2], top;
int visited[MAXG + 1];
int g[MAXG + 1][MAXG + 1] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}
};
int dist[MAXG + 1];

void s_push(int v){
    stack[top++] = v;
}

int s_pop(){
    return stack[--top];
}

int s_empth(){
    return top == 0;
}

void dfs_stack(int start, int n){
    top = 0;
    s_push(start); // 시작 노드를 일단 스택에 push
    while(top){
        int v = s_pop(); // 현재 노드 위치 확인
        if(visited[v]) // 이미 pop한 노드면 건너 뜀
            continue;
        visited[v] = 1; // 방문 안 했던 노드면 방문표시
        /// 문제에서 요구하는 행동을 이 위치에서 진행하면 된다
        printf("%d ", v);
        for(int i = n; i >= 1; i--){ // 큰 번호부터 현재 노드와 이웃인지 확인
            if(!visited[i] && g[v][i]) // 이웃인데 방문 안 했으면
                s_push(i); // 스택에 push
        } // 번호 역순으로 진행되서 스택 맨 위에는 가장 작은 숫자인 이웃이 위치한다.
    }
}

int q[MAXG + 1], front, rear;

void enq(int v){
    q[rear++] = v;
}

int deq(){
    return q[front++];
}

int q_empty(){
    return front == rear;
}

void bfs(int start, int n){
    front = rear = 0;

    for (int i = 1; i <= n; i++)
        dist[i] = -1;

    enq(start);
    visited[start] = 1;
    dist[start] = 0;
    while(!q_empty()){
        int v = deq();
        // 문제에서 요구하는 사항은 이 곳에서 수행
        printf("%d(%d) ", v, dist[v]);
        for(int i = 1; i <= n; i++){
            if(!visited[i] && g[v][i]){
                visited[i] = 1;
                dist[i] = dist[v] + 1;
                enq(i);
            }
        }
    }
}


int main(){
    int arr[10] = {0, 2, 3, 1, 5, 9, 8, 4, 6, 7};
    int arr2[20] = {
        -5, -2, -2, 0, 1,
        3,  3,  3, 5, 7,
        7,  9, 12, 12, 12,
        15, 18, 18, 21, 30
    };

    for(int i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    qsort(arr, 10, sizeof(int), cmp_int);

    for(int i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("11 is index %d\n", binary_search(arr, 10, 11));
    printf("2 is index %d\n", binary_search(arr, 10, 2));

    printf("first 3 is index %d\n", binary_search_first(arr2, 20, 3));
    printf("first greater than 15 is index %d\n", binary_search_greater(arr2, 20, 15));

    push(1); push(10); push(50); push(3); push(40); push(5); push(2); push(6); push(10); push(0);
    printf("Heap Sort: ");
    for(int i = 0; i < 10; i++){
        printf("%d ", pop());
    }
    printf("\n");

    printf("DFS: ");
    dfs_stack(1, 10);
    printf("\n");

    for(int i = 0; i < MAXG + 1; i++)
        visited[i] = 0;

    printf("BFS: ");
    bfs(1, 10);
    printf("\n");

    return 0;
}