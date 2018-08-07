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

//Dijkstra单源最短路算法(O(n2)，无负权图)
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
		for(int j=0; j < AdjDis[u].size(); j++){
			int v = AdjDis[u][j].v;
			if(vis[v]==false && d[u]+AdjDis[u][j].dis<d[v])
				d[v] = d[u] + AdjDis[u][j].dis;
		}
	}
}

//Bellman-Ford单源最短路算法(BF,有负权图)
//若在邻接矩阵中使用BF算法，则会达到O(n3)的时间复杂度
bool Bellman(int s){
	fill(d, d+maxn, INF);
	d[s] = 0;
	for(int i=0; i<n-1; i++){ //执行n-1轮操作
		for(int u=0; u<n; u++){ //每轮遍历所有边
			for(int j=0; j<AdjDis[u].size(); j++){
				int v = AdjDis[u][j].v;
				int dis = AdjDis[u][j].dis;
				if(d[u] + dis < d[v])
					d[v] = d[u] + dis; //松弛操作
			}
		}
	}
	//判断图中是否有负环
	for(int u=0; u<n; u++){
		for(int j=0; j<AdjDis[u].size(); j++){
			int v = AdjDis[u][j].v;
			int dis = AdjDis[u][j].dis;
			if(d[u] + dis < d[v])
				return false;
		}
	}
	return true;
}

//SPFA(Shortest Path Faster Algorithm,O(kE),k为常数，一般不超过2)
//BF算法的改进，BF算法每轮遍历所有边，然而只有当顶点u的d[u]改变时，邻接点v的d[v]才可能会改变
int num[maxn]; //记录顶点入队次数，以判断是否有负环
bool inq[maxn]; //顶点是否在队列中

bool SPFA(int s){
	memset(inq, false, sizeof(inq));
	memset(num, 0, sizeof(num));
	fill(d, d+maxn, INF);
	queue<int> q;
	q.push(s);
	inq[s] = true;
	num[s]++;
	d[s] = 0;
	while(!q.empty()){
		u = q.front();
		q.pop();
		inq[u] = false;
		for(int j=0; j<AdjDis[u].size(); j++){
			int v = AdjDis[u][j].v;
			int dis = AdjDis[u][j].dis;
			if(d[u]+dis<d[v]){ //d[v]发生改变时才将顶点入队
				d[v] = d[u] + dis;
				if(!inq[v]){
					q.push(v);
					inq[v] = true;
					num[v]++;
					if(num[v]>=n) return false; //入队次数大于n-1,则存在可达负环
				}
			}
		}
	}
	return true;
}

//Floyd-Warshall算法(三层循环实现)

//Prim最小生成树(O(V2),与Dijkstra使用的思想几乎相同，
//区别在于Prim数组d[]代表顶点V与集合S的最短距离,Dijkstra代表起点s到达顶点V的最短距离)
//int d[maxn]; //顶点与集合S的距离
//通过堆优化可使Dijkstra和Prim算法达到O(VlogV+E)
int Prim(){
	fill(d, d+maxn, INF);
	d[s] = 0;
	int ans = 0;
	for(int i=0; i<n; i++){
		int u=-1, MIN = INF;
		for(int j=0; j<n; j++){
			if(vis[j]==false && d[j]<MIN){
				u = j;
				MIN = d[j];
			}
		}
		if(u==-1) return -1;
		vis[u] = true;
		ans += d[u];
		for(int j=0; j<AdjDis[u].size(); j++){
			int v = AdjDis[u][j].v;
			int dis = AdjDis[u][j].dis;
			if(vis[v]==false && dis<d[v])
				d[v] = dis;
		}
	}
	return ans; //返回最小生成树的边权之和
}

//拓扑排序(Topological Sort,入度为0的入队列)
int n, m, inDegree[maxn];

bool topologicalSort(){
	int num = 0; //记录加入拓扑序列的顶点数
	queue<int> q;
	for(int i=0; i<n; i++)
		if(inDegree[i]==0)
			q.push(i);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i=0; i<Adj[u].size(); i++){
			int v = Adj[u][i];
			inDegree[v]--;
			if(inDegree[v]==0)
				q.push(v);
		}
		Adj[u].clear(); //清空顶点u的所有出边(可不写)
		num++;
	}
	return num==n ? true : false;
}


int main(){

	return 0;
}