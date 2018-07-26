#include <cstdio>

int queue[100];
int front=-1, rear=-1;

void clear(){
	front = rear = -1;
}

int size(){
	return rear-front;
}

bool empty(){
	if(front==rear) return true;
	else return false;
}

void push(int x){
	queue[++rear] = x;
}

void pop(){
	front++;
}

int get_front(){
	return queue[front+1];
}

int get_rear(){
	return queue[rear];
}

int main(){
	for(int i=0; i<5; i++){
		push(i);
	}
	while(!empty()){
		printf("%d\n", get_front());
		pop();
	}
	return 0;
}