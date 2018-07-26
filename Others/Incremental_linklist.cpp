#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

void createlist(Node* rear, int n){
    int num,count=0;
    Node* p;
    while(count<n){
        scanf("%d",&num);
        p = (Node*)malloc(sizeof(Node));
        p->data = num;
        p->next = NULL;
        rear->next = p;
        rear = p;
        count++;
    }
}

int main()
{
    Node *head, *rear, *p, *q;
    int n, m;
    head = rear = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    scanf("%d %d", &n, &m);
    createlist(rear, n);
    for(p=head; p->next && p->next->data<m; p=p->next);
    if(p)
    {
        q = (Node*)malloc(sizeof(Node));
        q->data = m;
        q->next = p->next;
        p->next = q;
    }

    for(p=head->next; p->next; p=p->next)
    {
        printf("%d ", p->data);
    }
    printf("%d\n",p->data);

    return 0;
}
