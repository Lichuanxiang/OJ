#include <iostream>
#define MAXN 30000+1
using namespace std;

int pre[MAXN];

int find(int x){
    //if(pre[x]<=0)   return x;
    //else pre[x] = find(pre[x]);
    int r = x;
    while(pre[r]>0)
        r = pre[r];
    int i=x, j;
    while(pre[i]>0){
        j = pre[i];
        pre[i] = r;
        i = j;
    }
    return r;
}

void join(int x, int y){
    int fx, fy;
    fx = find(x);
    fy = find(y);
    if(fx!=fy){
        if(pre[fx]<pre[fy]){        /* 如果集合fx比较大 */
            pre[fx]+=pre[fy];
            pre[fy] = fx;           /* 集合fy并入集合fx  */
        }
        else{
            pre[fy]+=pre[fx];
            pre[fx] = fy;
        }
    }
}

int main()
{
    int n,m,i,j,stu_num,stu1,other,max=1;
    cin>>n>>m;
    for(i=1; i<=n; i++)
        pre[i] = -1;
    for(i=0; i<m; i++){
        cin>>stu_num>>stu1;
        for(j=1; j<stu_num; j++){
            cin>>other;
            join(stu1, other);
        }
    }
    for(i=1; i<=n; i++)
        if((pre[i]<0) && (max < -pre[i]))
            max = -pre[i];
    cout<<max<<endl;

    return 0;
}
