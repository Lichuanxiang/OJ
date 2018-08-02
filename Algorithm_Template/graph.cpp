//图的构建：邻接矩阵实现和邻接链表实现(vector)
#include <cstdio>
#include <queue>

using namespace std;

const int maxn = 1000; //最大顶点数
const int INF = 1000000000;

//1. 邻接矩阵版DFS(深度优先遍历)
int n, G[maxn][maxn]; //n为实际顶点数
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

//1. 邻接矩阵版BFS(宽度优先遍历)
int n, G[maxn][maxn]; //n为实际顶点数
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

//2. 邻接链表版DFS
vector<int> Adj[maxn]; //数组中有最多maxn个vector
int n;
bool vis[maxn] = {false};

void DFSAdj(int u, int &depth){
	vis[u] = true;
	for(int i=0; i<Adj[u].size(); i++){
		int v = Adj[u][i];
		if(vis[v]==false)
			DFSAdj(v, depth+1);
	}
}
void DFSTraveAdj(){
	int depth = 1;
	for(int u=0; u<n; u++){
		if(vis[u]==false)
			DFSAdj(u, depth);
	}
}

//2. 邻接链表版BFS
vector<int> Adj[maxn];
int n;
bool inq[maxn] = {false};

void BFSAdj(int u){
	queue<int> q;
	q.push(u);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i=0; i<Adj[u].size(); i++){
			int v = Adj[u][i];
			if(inq[v]==false){
				q.push(v);
				inq[v] = true;
			}
		}
	}
}
void BFSTraveAdj(){
	for(int u=0; u<n; u++){
		if(inq[u]==false){
			inq[u] = true;
			BFSAdj(u);
		}
	}
}

int main(){

	return 0;
}