#include <iostream>

#define MAXN 500
#define MAXINT 65535

using namespace std;

int main(){
    int N,M,C1,C2;
    int teams[MAXN];
    int road[MAXN][MAXN];
    bool S[MAXN];
    int dist[MAXN],allnum[MAXN],allteams[MAXN];
    int x,y,len,mindist,u,i,j;

    for(i=0; i<MAXN; i++){
        teams[i]=0; S[i]=false; dist[i]=0; allnum[i]=0; allteams[i]=0;
    }
    for(i=0; i<MAXN; i++){
        for(j=0; j<MAXN; j++)
            road[i][j] = MAXINT;
    }
    cin>>N>>M>>C1>>C2;
    for(i=0; i<N; i++) cin>>teams[i];
    for(i=0; i<M; i++){
        cin>>x>>y>>len;
        road[x][y]=len; road[y][x]=len;
    }

    S[C1]=true; road[C1][C1]=0;
    for(i=0; i<N; i++){
        dist[i] = road[C1][i];
        if(road[C1][i]<MAXINT){
            allnum[i]=1; allteams[i]=teams[C1]+teams[i];
        }
    }
    allnum[C1]=1; allteams[C1]=teams[C1];

    //dijkstra algorithm

    for(i=0; i<N; i++){
        mindist = MAXINT;
        u = C1;
        for(j=0; j<N; j++){             //找路径最小值
            if(!S[j] && dist[j]<mindist){
                u = j;
                mindist = dist[j];
            }
        }
        S[u] = true;
        for(j=0; j<N; j++)
            if(!S[j])
                if(dist[u]+road[u][j]<dist[j]){
                    dist[j] = dist[u]+road[u][j];
                    allnum[j] = allnum[u];
                    allteams[j] = allteams[u]+teams[j];
                }
                else if(dist[u]+road[u][j]==dist[j]){
                    allnum[j] = allnum[u]+allnum[j];
                    if(allteams[u]+teams[j]>allteams[j])
                        allteams[j] = allteams[u]+teams[j];
                }
    }
    cout<<allnum[C2]<<" "<<allteams[C2]<<endl;
    return 0;
}
