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

//Kruskal最小生成树,n为顶点个数，m为边数
const int maxE = 10010;
struct edge
{
	int u, v;
	int cost; //边权
}E[maxE];
bool cmp(edge a, edge b){
	return a.cost < b.cost;
}
int Kruskal(int n, int m){
	int ans=0, edgeNum=0; //当前生成树的边数
	for(int i=0; i<n; i++) //假设顶点范围[0,n-1]
		father[i] = i;
	sort(E, E+maxE, cmp);
	for(int i=0; i<m; i++){
		int fU = findFather(E[i].u); //找到边两个端点所在集合的根节点
		int fV = findFather(E[i].v);
		if(fU!=fV){
			father[fU] = fV;
			ans += E[i].cost;
			edgeNum++;
			if(edgeNum==n-1) break;
		}
	}
	if(edgeNum!=n-1) return -1; //图无法连通
	else return ans;
}
