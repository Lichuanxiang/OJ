/*
    Hanoi塔的递归与非递归实现
*/

//非递归实现
#include <stdio.h>

#define MAXN 100

typedef struct{
    int N;
    char x;
    char y;
    char z;
} elemtype;

elemtype ERROR;

typedef struct{
    elemtype data[MAXN];
    int top;
} Stack;

void push(Stack *s, elemtype item){
    if(s->top == MAXN-1) printf("Stack is full!");
    else s->data[++s->top] = item;
    return;
}

elemtype pop(Stack *s){
    if(s->top==-1){
        printf("Stack is empty!");
        return ERROR;
    }
    return s->data[s->top--];
}

void hanoi(int n){
    elemtype elem, topush;
    Stack s;
    elem.N = n; elem.x='a'; elem.y='b'; elem.z='c';
    s.top = -1;
    push(&s,elem);
    while(s.top!=-1)
    {
        elem = pop(&s);
        if(elem.N==1) printf("%c -> %c\n",elem.x, elem.z);
        else{
            topush.N=elem.N-1; topush.x = elem.y; topush.y = elem.x; topush.z = elem.z;
            push(&s, topush);
            topush.N=1; topush.x = elem.x; topush.y = elem.y; topush.z = elem.z;
            push(&s, topush);
            topush.N=elem.N-1; topush.x = elem.x; topush.y = elem.z; topush.z = elem.y;
            push(&s, topush);
        }
    }
}

int main()
{
    int n;
    ERROR.N = -1;
    scanf("%d",&n);
    hanoi(n);

    return 0;
}

//C++递归实现
/*#include <iostream>

using namespace std;

void move(char x, char z);
void hanoi(int n, char x, char y, char z);  //由柱x借柱y移到柱z

int main()
{
    int n;
    cin>>n;
    hanoi(n,'a','b','c');

    return 0;
}

void move(char x, char z){
    static int i;
    i++;
    cout<<i<<":"<<x<<"->"<<z<<endl;
}

void hanoi(int n, char x, char y, char z){
    if(n==1) move(x,z);
    else{
        hanoi(n-1, x, z, y);
        move(x,z);
        hanoi(n-1, y, x, z);
    }
}
*/


