//数学问题(math_problem)
#include <cstdio>

//最大公约数(greatest common divisor)
int gcd(int a, int b){
	if(b==0) return a;
	else return gcd(b, a%b);
}

//最小公倍数(least common multiple)
int lcm(int a, int b){
	int d = gcd(a, b);
	return a * b / d;
	//return a / d * b; //防止溢出
}

//素数判断(O(sqrt(n)))
bool isPrime(int n){
	if(n<=1) return false;
	for(int i=2; i*i<=n; i++)
		if(n % i == 0) return false;
	return true;
}

//获取素数表(筛法,O(nloglogn))
const int maxn = 101;
int prime[maxn], pNum=0; //素数表和素数个数
bool p[maxn] = {0}; //若i为素数，则p[i]为false，否则为true
void findPrime(){
	for(int i=2; i<maxn; i++)
		if(p[i]==false){ //不需要isPrime()函数判断
			prime[pNum++] = i;
			for(int j=i+i; j<maxn; j+=i)
				p[j] = true; //筛去所有i的倍数
		}
}

//扩展欧几里得算法：
//问题：给定两个非零整数a和b，求一组整数解(x,y)，使得ax+by=gcd(a,b)成立。
int exGCD(int a, int b, int &x, int &y){
	if(b==0){
		x = 1;
		y = 0;
		return a;
	}
	else{
		int g = exGCD(b, a%b, x, y);
		int temp = x;
		x = y;
		y = temp - a/b*y;
		return g;
	}
}

//快速幂(求a^b%m)
//递归
typedef long long LL;
LL binaryPow(LL a, LL b, LL m){
	if(b==0) return 1;
	if(b%2==1) return a * binaryPow(a, b-1, m) % m;
	else{
		LL mul = binaryPow(a, b/2, m);
		return mul * mul % m;
	}
}
//非递归(迭代)
LL binaryPowIter(LL a, LL b, LL m){
	LL ans = 1;
	while(b>0){
		if(b&1){ //判断b二进制末尾是否为1，等价于 b % 2
			ans = ans * a % m;
		}
		a = a * a % m;
		b >>= 1; //b的二进制右移一位，等价于b = b / 2
	}
	return ans;
}

//swap函数三种实现
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

//由Knuth,Morris,Pratt共同发现
//时间复杂度O(n+m),穷举为O(nm)
/*
	考察目标字符串ptr： 
	ababaca 
	这里要计算一个长度为m的转移函数next。

	next数组的含义就是一个固定字符串的最长前缀和最长后缀相同的长度。

	比如：abcjkdabc，那么这个数组的最长前缀和最长后缀相同必然是abc。 
	cbcbc，最长前缀和最长后缀相同是cbc。 
	abcbc，最长前缀和最长后缀相同是不存在的。

	**注意最长前缀：是说以第一个字符开始，但是不包含最后一个字符。 
	比如aaaa相同的最长前缀和最长后缀是aaa。** 
	对于目标字符串ptr，ababaca，长度是7，所以next[0]，...，next[6]分别计算的是:
	a，ab，aba，abab，ababa，ababac，ababaca的相同的最长前缀和最长后缀的长度。
	由于a，ab，aba，abab，ababa，ababac，ababaca的相同的最长前缀和最长后缀是
	“”，“”，“a”，“ab”，“aba”，“”，“a”,所以next数组的值是[-1,-1,0,1,2,-1,0]，
	这里-1表示不存在，0表示存在长度为1，2表示存在长度为3。这是为了和代码相对应。
*/
#include <cstdio>
#include <cstring>

const int maxn = 1000;

void getNext(char s[], int* next, int len){
	int j = -1;
	next[0] = -1;
	for(int i=1; i<len; i++){
		while(j!=-1 && s[i]!=s[j+1])
			j = next[j]; //回退
		if(s[i]==s[j+1])
			j++;
		next[i] = j;
	}
	for(int i=0; i<len; i++)
		printf("%d ", next[i]);
	printf("\n");
}

//返回模式串pattern匹配的次数
int KMP(char* text, char* pattern){
	int n = strlen(text), m = strlen(pattern);
	int next[m];
	getNext(pattern, next, m);
	int ans=0, j=-1;
	for(int i=0; i<n; i++){
		while(j!=-1 && text[i]!=pattern[j+1])
			j = next[j];
		if(text[i]==pattern[j+1])
			j++;
		if(j==m-1){
			ans++;
			j = next[j];
		}
	}
	return ans;
}

int main(){
	char *text = "ababaababaab", *pattern = "ababaab";
	printf("%d\n", KMP(text, pattern));
	return 0;
}

//堆栈数组实现
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

//队列数组实现
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

//C++递归实现
#include <iostream>

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

/**
	哈夫曼树：带权路径最小的树
	**树的带权路径长度要会计算**
	构建思想：反复选择两个最小的元素，合并，直到只剩下一个元素
	使用优先队列(小顶堆)实现
**/

#include <cstdio>
#include <queue>

using namespace std;

priority_queue<long long, vector<long long>, greater<long long> > q; //greater为小顶堆

int main(){
	int n;
	long long temp, x, y, ans=0;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%lld", &temp);
		q.push(temp);
	}
	//Huffman树思想
	while(q.size()>1){ //优先队列中至少有两个元素
		x = q.top();
		q.pop();
		y = q.top();
		q.pop();
		q.push(x+y);
		ans += x+y;
	}
	return 0;
}

//1.中缀表达式转后缀表达式
//2.计算后缀表达式

#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <map>

using namespace std;

struct node
{
	double num;
	char op;
	bool flag; //true为操作数，false为操作符
};

string str;
stack<node> s; //操作符栈
queue<node> q; //后缀表达式序列
map<char, int> op;

void change(){ //中缀转后缀
	node temp;
	for(int i=0; i<str.length();){
		if(str[i]>='0' && str[i]<='9'){
			temp.flag = true;
			temp.num = str[i++] - '0';
			while(i<str.length() && str[i]>='0' && str[i]<='9'){
				temp.num = temp.num*10 + (str[i] - '0');
				i++;
			}
			q.push(temp);
		}
		else{
			temp.flag = false;
			while(!s.empty() && op[str[i]]<=op[s.top().op]){
				q.push(s.top());
				s.pop();
			}
			temp.op = str[i];
			s.push(temp);
			i++;
		}
	}
	while(!s.empty()){
		q.push(s.top());
		s.pop();
	}
}
double calculate(){ //计算后缀表达式
	double num1, num2;
	node cur, temp;
	while(!q.empty()){
		cur = q.front();
		q.pop();
		if(cur.flag==true) s.push(cur);
		else{
			num2 = s.top().num;
			s.pop();
			num1 = s.top().num;
			s.pop();
			if(cur.op=='+') temp.num = num1+num2;
			else if(cur.op=='-') temp.num = num1-num2;
			else if(cur.op=='*') temp.num = num1*num2;
			else temp.num = num1/num2;
			s.push(temp);
		}
	}
	return s.top().num;
}

int main(){
	op['+'] = op['-'] = 1;
	op['*'] = op['/'] = 2;
	while(getline(cin, str), str!="0"){
		for(string::iterator it=str.end(); it!=str.begin(); it--)
			if(*it==' ') str.erase(it);
		while(!s.empty()) s.pop();
		change();
		printf("%.2f\n", calculate());
	}
}