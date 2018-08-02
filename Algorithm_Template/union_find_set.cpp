//并查集

#include <cstdio>

int N=100;
int father[N];

//find函数非递归实现
int findFather(int x){
	while(x!=father[x]){
		x = father[x];
	}
	return x;
}
//find函数递归实现
int findFatherRecursive(int x){
	if(x==father[x]) return x;
	else return findFather[father[x]];
}

//Union函数实现
void Union(int a, int b){
	int fA = findFather[a];
	int fB = findFather[b];
	if(fA!=fB){
		father[fA] = fB;
	}
}

//路径压缩(所有节点均直接指向根节点)
//非递归实现
int compressPath(int x){
	int a = x;
	while(x!=father[x])
		x = father[x];
	while(a!=father[a]){
		int temp = a;
		a = father[a];
		father[temp] = x;
	}
	return x;
}
//递归实现
int compressPathRecursive(int x){
	if(x==father[x]) return x;
	else{
		int F = compressPathRecursive(father[x]);
		father[x] = F;
		return F;
	}
}
