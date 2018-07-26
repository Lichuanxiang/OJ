//二叉树(此处以二叉查找树的建立为例)

#include <cstdio>
#include <queue>

using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

void search_modify(node* root, int x, int newdata){
	if(root==NULL) return;
	if(root->data==x) root->data = newdata;
	search_modify(root->left, x, newdata);
	search_modify(root->right, x, newdata);
}

void insert(node* &root, int x){
	if(root==NULL){
		root = new node;
		root->data = x;
		root->left = root->right = NULL;
		return;
	}
	//二叉查找树(BST)的插入
	if(root->data==x) return;
	else if(root->data > x)
		insert(root->left, x);
	else insert(root->right, x);
}

node* createTree(int data[], int n){
	node* root = NULL;
	for(int i=0; i<n; i++)
		insert(root, data[i]);
	return root;
}

//二叉查找树的删除


//二叉树的遍历
//1.先序遍历
void preOrder(node* root){
	if(root==NULL) return;
	printf("%d\n", root->data);
	preOrder(root->left);
	preOrder(root->right);
}

//2.中序遍历
void inOrder(node* root){
	if(root==NULL) return;
	inOrder(root->left);
	printf("%d\n", root->data);
	inOrder(root->right);
}

//3.后序遍历
void postOrder(node* root){
	if(root==NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	printf("%d\n", root->data);
}

//4.层次遍历
void levelOrder(node* root){
	queue<node* > q;
	q.push(root);
	while(!q.empty()){
		node* top = q.front();
		q.pop();
		printf("%d\n", top->data);
		if(top->left) q.push(top->left);
		if(top->right) q.push(top->right);
	}
}

//结论：中序序列可以和先序、后序、层序遍历序列中任意一个结合来构造唯一二叉树，而后三者无法组合构建唯一二叉树。

//给定二叉树前序和中序遍历序列，重建该二叉树
node* createByPreInOrder(int* pre, int* in, int len){
	if(!len) return NULL;
	node* root = new node;
	//node* root = (node*)malloc(sizeof(struct node));
	root->data = pre[0];
	int i;
	for(i=0; i<len; i++)
		if(in[i]==pre[0]) break;
	root->left = createByPreInOrder(pre+1, in, i);
	root->right = createByPreInOrder(pre+i+1, in+i+1, len-i-1);
	return root;
}

//求二叉树的高度
int height(node* root){
	int rootH, leftH, rightH;
	//if(!root)
	if(root==NULL)
		return 0;
	leftH = height(root->left);
	rightH = height(root->right);
	return leftH>rightH ? leftH+1 : rightH+1;
}

int main(){
	int arr[5] = {2,1,4,3,5};
	int in[5] = {1,2,3,4,5};
	//node* binaryTree = createTree(arr, 5);
	node* binaryTree = createByPreInOrder(arr, in, 5);
	//postOrder(binaryTree);
	printf("%d\n", height(binaryTree));
	return 0;
}