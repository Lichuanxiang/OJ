/**
   POJ 1258  π”√Prim-MSTΩ‚
**/

#include <iostream>
#include <vector>
#include <string.h>

#define INF 0x3f3f3f3f
#define N 110

using namespace std;

int w[N][N],vis[N],pre[N],dis[N];

void init()
{
    memset(pre,0,sizeof(pre));
    memset(dis,INF,sizeof(dis));
    memset(vis,0,sizeof(vis));
}

int n;

int prim()
{
    init();
    vector<int> node;
    int s=1,ans=0,k,min;
    dis[s]=0;
    pre[s]=s;

    node.push_back(s);
    while(1)
    {
        min = INF;
        for(int i=0; i<node.size(); i++)
        {
            int v = node[i];
            if(!vis[v]&&dis[v]<min)
            {
                min = dis[v];
                k = v;
            }
        }
        if(min==INF)
            break;
        ans+=min;
        vis[k]=1;

        for(int i=0; i<n; i++)
        {
            if(!vis[i]&&w[k][i]<dis[i])
            {
                dis[i] = w[k][i];
                pre[i] = k;
                node.push_back(i);
            }
        }
    }
    return ans;
}

int main()
{
    while(cin>>n){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
            {
                cin>>w[i][j];
            }
        }
        cout<<prim()<<endl;
    }

    return 0;
}
