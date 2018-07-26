#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 10005;
int n;
int d[MAXN];
int ans;
int x;

int main()
{
    int id;
    scanf("%d",&d[0]);
    while(scanf("%d",&n)!=EOF)
    {
        ans = 0;
        for(int i=1; i<n; i++)
        {
            scanf("%d",&x);
            if(x>d[ans]) d[++ans] = x;
            else
            {
                id = lower_bound(d,d+ans,x)-d;
                if(d[id]!=x) d[id] = x;
            }
        }
        printf("%d\n",ans+1);
        //printf("%s\n",d);
    }
    return 0;
}
