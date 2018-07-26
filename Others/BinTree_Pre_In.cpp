//根据前序、中序遍历构造二叉树，输出树的高度以及后序遍历

#include <stdio.h>
#include <stdlib.h>

#define MAXN 50+1

using namespace std;

struct Node{
    char data;
    Node *left;
    Node *right;
};

Node* createBinTree(char* Pre, char* In, int len){
    Node *T;
    int i;
    if(!len) return NULL;
    T = (Node *)malloc(sizeof(struct Node));
    T->data = Pre[0];
    for(i=0; i<len; i++)
        if(In[i]==Pre[0]) break;
    T->left = createBinTree(Pre+1, In, i);
    T->right = createBinTree(Pre+i+1, In+i+1, len-i-1);

    return T;
}

int Height(Node* T){
    int THeight, LHeight, RHeight;
    if(!T) return 0;
    else{
        LHeight = Height(T->left);
        RHeight = Height(T->right);
        THeight = (LHeight>RHeight) ? LHeight : RHeight;
        THeight++;
    }

    return THeight;
}

//后序遍历
void PostOrder(Node* T){
    if(T){
        PostOrder(T->left);
        PostOrder(T->right);
        printf("%c", T->data);
    }
}

int main()
{
    int n;
    Node* T = NULL;
    scanf("%d",&n);
    char Pre[MAXN], In[MAXN];
    scanf("%s\n%s", Pre, In);
    T = createBinTree(Pre, In, n);
    printf("%d\n", Height(T));
    PostOrder(T);
    return 0;
}
