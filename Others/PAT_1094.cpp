#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    int root, k, node;
    vector<int> tree[n+1];
    for(int i=0; i<m; i++)
    {
        cin>>root>>k;
        for(int j=0; j<k; j++)
        {
            cin>>node;
            tree[root].push_back(node);
        }
    }
    queue<int> cur, next;
    cur.push(1);
    int level=0, lcount=0, maxlevel=0, maxcount=0;
    while(!cur.empty())
    {
        level++;
        lcount = cur.size();
        if(lcount>maxcount)
        {
            maxlevel = level;
            maxcount = lcount;
        }
        while(!cur.empty())
        {
            int temp = cur.front();
            cur.pop();
            for(vector<int>::iterator iter=tree[temp].begin(); iter!=tree[temp].end(); iter++)
                next.push(*iter);
        }
        swap(cur, next);
    }

    cout<<maxcount<<" "<<maxlevel<<endl;
    return 0;
}
