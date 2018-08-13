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

//翻转链表(非递归)
node* reverse(node* head) {
    node *pre=NULL, *next=NULL;
    while(head!=NULL){
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}

node* reverseRecursive(node* head){
	//递归边界，head为空直接返回，head-next为空则为最后一个元素，返回作为头结点
	if(head==NULL || head->next==NULL)
		return head;
	else{
		node* newHead = reverseRecursive(head->next);
		head->next->next = head; //head->next代表当前节点的下一个节点，本行代码将下一个节点指向当前节点
		head->next = NULL; //翻转后的下一个节点跟当前节点会形成一个环，故需断掉连接
		return newHead;
	}
}

int main(){
	int array[5] = {5,3,6,1,2};
	node* L = create(array);
	del(L, 6);
	L = L->next;
	for(node* L1=L; L1!=NULL; L1=L1->next){
		printf("%d\n", L1->data);
	}
	printf("\n");
	/*
	node* L2 = reverse(L);
	for(; L2!=NULL; L2=L2->next){
		printf("%d\n", L2->data);
	}
	*/
	L= reverseRecursive(L);
	for(; L!=NULL; L=L->next){
		printf("%d\n", L->data);
	}
	return 0;
}