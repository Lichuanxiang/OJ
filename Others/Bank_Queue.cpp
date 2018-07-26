//银行排队队列模拟

#include <iostream>
#include <stdio.h>
#include <queue>
#define MAXN 1000
#define ERROR -1;

using namespace std;

//使用STL队列
int main()
{
    queue<int> A,B;
    int n,i,cur,flag=0;
    scanf("%d",&n);
    for(i=0; i<n; i++){
        scanf("%d",&cur);
        if(cur%2) A.push(cur);
        else B.push(cur);
    }

    while(!A.empty() && !B.empty()){
        if(!flag) {
            printf("%d",A.front());
            A.pop();
            flag=1;
        }
        else {
            printf(" %d",A.front());
            A.pop();
        }
        if(!A.empty()) {
            printf(" %d", A.front());
            A.pop();
        }
        printf(" %d", B.front());
        B.pop();
    }
    while (!A.empty())
        if(!flag) {
            printf("%d",A.front());
            A.pop();
            flag=1;
        }
        else {
            printf(" %d",A.front());
            A.pop();
        }
    while (!B.empty())
          if (!flag) {
              printf("%d", B.front());
              B.pop();
              flag = 1;
          }
          else{
              printf(" %d", B.front());
              B.pop();
          }
    printf("\n");

    return 0;
}
//自己编写队列
typedef struct{
    int customer[MAXN];
    int front;
    int rear;
} Queue;

void InitQ(Queue *q){
    q->front=q->rear=0;
}

int IsEmpty(Queue *q){
    return q->front==q->rear;
}

void addQ(Queue *q, int item){
    if((q->rear+1)%MAXN==q->front){
        printf("Queue is full!");
        return;
    }
    q->rear = (q->rear+1)%MAXN;
    q->customer[q->rear] = item;
}

int deleteQ(Queue *q){
    if(IsEmpty(q)){
        printf("Queue is empty!");
        return ERROR;
    }
    q->front = (q->front+1)%MAXN;
    return q->customer[q->front];
}

/*
int main()
{
    int n,i,cur,flag=0;
    Queue A,B;
    InitQ(&A);
    InitQ(&B);
    scanf("%d",&n);
    for(i=0; i<n; i++){
        scanf("%d",&cur);
        if(cur%2) addQ(&A,cur);
        else addQ(&B,cur);
    }

    while(!IsEmpty(&A) && !IsEmpty(&B)){
        if(!flag) {
            printf("%d",deleteQ(&A));
            flag=1;
        }
        else printf(" %d",deleteQ(&A));
        if(!IsEmpty(&A)) printf(" %d", deleteQ(&A));
        printf(" %d", deleteQ(&B));
    }
    while (!IsEmpty(&A))
          if (!flag) {
              printf("%d", deleteQ(&A));
              flag = 1;
          }
          else  printf(" %d", deleteQ(&A));
    while (!IsEmpty(&B))
          if (!flag) {
              printf("%d", deleteQ(&B));
              flag = 1;
          }
          else  printf(" %d", deleteQ(&B));
    printf("\n");

    return 0;
}*/

