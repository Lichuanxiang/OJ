#include <cstdio>

int TOP=-1;

int stack[100];

void clear(){
	TOP = -1;
}

int size(){
	return TOP+1;
}

bool empty(){
	if(TOP==-1) return true;
	else return false;
}

void push(int x){
	stack[++TOP] = x;
}

void pop(){
	TOP--;
}

int top(){
	return stack[TOP];
}

int main(){
	clear();
	for(int i=0; i<5; i++){
		push(i);
	}
	pop();
	pop();
	while(!empty()){
		printf("%d\n", top());
		pop();
	}
	return 0;
}