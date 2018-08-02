//图的构建：邻接矩阵实现
#include <cstdio>
#include <queue>

using namespace std;

const int maxn = 1000; //最大顶点数
const int INF = 1000000000;

//邻接矩阵版DFS(深度优先遍历)
int n=10, G[maxn][maxn]; //n为实际顶点数
bool vis[maxn] = {false};

void DFS(int u, int &depth){
	vis[u] = true;
	for(int v=0; v<n; v++){
		if(vis[v]==false && G[u][v]!=INF)
			DFS(v, depth+1);
	}
}
void DFSTrave(){
	int depth = 1;
	for(int u=0; u<n; u++){
		if(vis[u]==false)
			DFS(u, depth);
	}
}


//邻接矩阵版BFS(宽度优先遍历)
bool inq[maxn] = {false};

void BFS(int u){
	queue<int> q;
	q.push(u);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v=0; v<n; v++){
			if(inq[v]==false && G[u][v]!=INF){
				q.push(v);
				inq[v] = true;
			}
		}
	}
}
void BFSTrave(){
	for(int u=0; u<n; u++){
		if(inq[u]==false){
			inq[u] = true;
			BFS(u);
		}
	}
}


//Dijkstra单源最短路算法(O(n2))
int d[maxn]; //起点到达各点的最短路径长度
//bool vis[maxn] = {false};

void Dijkstra(int s){ //s为起点
	fill(d, d+maxn, INF);
	d[s] = 0;
	for(int i=0; i<n; i++){
		int u = -1, MIN = INF;
		for(int j=0; j<n; j++)
			if(vis[j]==false && d[j]<MIN){
				u = j;
				MIN = d[j];
			}
		if(u==-1) return;
		vis[u] = true;
		for(int v=0; v<n; v++)
			if(vis[v]==false && G[u][v]!=INF && d[u]+G[u][v]<d[v])
				d[v] = d[u] + G[u][v];
	}
}

int main(){

	return 0;
}