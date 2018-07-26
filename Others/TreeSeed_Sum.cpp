/**二叉搜索树的使用:
    将树种Name插入二叉搜索树T，或累计已存在树种
**/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 30+1
using namespace std;

struct Node{
    char data[MAXN];
    int count;
    Node* left;
    Node* right;
};

Node* Insert(Node *T, char *Name){
    int cmp;
    if(!T) {
        T = (Node *)malloc(sizeof(struct Node));
        strcpy(T->data, Name);
        T->count = 1;
        T->left = T->right = NULL;
    }
    else{
        cmp = strcmp(Name,T->data);
        if(cmp<0) T->left = Insert(T->left, Name);
        else if(cmp>0) T->right = Insert(T->right, Name);
        else T->count++;
    }
    return T;
}

void Output(Node* T, int N){
    if(!T) return;//递归终止条件
    Output(T->left, N);
    printf("%s %.4f%c\n", T->data, (double)T->count/(double)N*100, '%');
    Output(T->right, N);
}

int main()
{
    int n,i;
    char name[MAXN];
    Node* T = NULL;
    scanf("%d\n",&n);
    for(i=0; i<n; i++){
        gets(name);
        T = Insert(T, name);
    }
    Output(T, n);

    return 0;
}
