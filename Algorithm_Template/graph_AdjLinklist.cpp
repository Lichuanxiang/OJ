//图的构建：邻接链表实现(vector)
#include <cstdio>
#include <queue>

using namespace std;

const int maxn = 1000; //最大顶点数
const int INF = 1000000000;

//邻接链表版DFS
vector<int> Adj[maxn]; //数组中有最多maxn个vector
int n = 10;
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

//邻接链表版BFS
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

//Dijkstra单源最短路算法(O(n2))
struct node
{
	int v, dis; //v为边的目标顶点，dis为边权
};
vector<node> AdjDis[maxn];
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
		for(int j=0; j<AdjDis[u].size(); j++){
			int v = AdjDis[u][j].v;
			if(vis[v]==false && d[u]+AdjDis[u][j].dis<d[v])
				d[v] = d[u] + AdjDis[u][j].dis;
		}
	}
}

int main(){

	return 0;
}