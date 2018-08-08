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