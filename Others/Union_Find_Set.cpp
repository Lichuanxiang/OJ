//���鼯ʵ�ֵ�·��ͨ����ĺϲ�/����
/**
    HDU 1232/���2005�긴�Ի�����
**/
#include <iostream>
#include <string.h>
#define MAXN 1000+50
using namespace std;

int pre[MAXN];
int t[MAXN];

int find(int x){
    int r = x;
    while(pre[r]!=r)        //Ѱ�Ҹ��ڵ�
        r = pre[r];
    int i=x, j;
    while(pre[i]!=r){
        j = pre[i];
        pre[i] = r;
        i = j;
    }

    return r;
}

int join(int x, int y, int ans){
    int fx, fy;
    fx = find(x);
    fy = find(y);
    if(fx!=fy){
        pre[fy] = fx;
        ans--;
    }
    return ans;
}

int main()
{
    int n,m,a,b,i,j,ans;
    while(cin>>n && n!=0){
        ans=n-1;
        cin>>m;
        for(i=1; i<=n; i++)
            pre[i] = i;
        for(j=1; j<=m; j++){
            cin>>a>>b;
            ans = join(a,b,ans);
        }
        cout<<ans<<endl;
    }

    return 0;
}
