#include <cstdio>
#include <cstdlib>

struct  node{
	int data;
	node* next;
};

//创建链表
node* create(int array[]){
	node *p, *pre, *head;
	head = new node;
	head->next = NULL;
	pre = head;
	for(int i=0; i<5; i++){
		p = new node;
		p->data = array[i];
		p->next = NULL;
		pre->next = p;
		pre = p;
	}
	return head;
}

//查找链表元素
int search(node* head, int x){
	int count=0;
	node* p = head->next; //从第一个结点开始
	for(; p!=NULL; p=p->next)
		if(p->data==x)
			count++;
	return count;
}

//插入元素
void insert(node* head, int pos, int x){
	node* p = head->next;
	for(int i=0; i<pos-1; i++)
		p = p->next;
	node* q = new node;
	q->data = x;
	q->next = p->next;
	p->next = q;
}

//删除元素
void del(node* head, int x){
	node* p = head->next;
	node* pre = head;
	while(p!=NULL){
		if(p->data==x){
			pre->next = p->next;
			delete(p);
		}
		else pre = p;
		p = pre->next;
	}
}

int main(){
	int array[5] = {5,3,6,1,2};
	node* L = create(array);
	del(L, 6);
	L = L->next;
	for(; L!=NULL; L=L->next){
		printf("%d\n", L->data);
	}
	return 0;
}