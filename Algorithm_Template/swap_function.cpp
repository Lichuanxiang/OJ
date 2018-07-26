//一、借助辅助变量temp的swap函数:
//1.引用类型形参
void swap(int &a, int &b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}
//2.指针类型形参
void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

//二、采用加减法的swap函数
void swap(int &a, int &b){
	int a = a + b;
	b = a - b;
	a = a - b;
}

//三、使用异或运算的swap函数
void swap(int &a, int &b){
	a = a ^ b; //^是按位异或运算符
	b = a ^ b;
	a = a ^ b;
}