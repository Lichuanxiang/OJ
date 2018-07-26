#include <iostream>
#include <string>
using namespace std;

bool findpath(string W, string s[], string a[], int count, int row, int col, int n, int m){
    int len = W.length();
    bool ok;
    if(row>=n||row<0||col>=m||col<0) return false;
    if(a[row][col]==1) return false;    //表示该节点已访问过
    if(s[row][col]==W[count]) {
        if(++count==len) return true;
        a[row][col] = 1;
        ok = findpath(W,s,a,count,row+1,col,n,m);
        if(!ok) ok = findpath(W,s,a,count,row-1,col,n,m);
        if(!ok) ok = findpath(W,s,a,count,row,col+1,n,m);
        if(!ok) ok = findpath(W,s,a,count,row,col-1,n,m);
        return ok;
    }
    else return false;
}

int main()
{
    int n, m, count=0;
    string W;
    cin>>n>>m;
    cin>>W;
    string a[21];
    string s[21];
    for(int j=0; j<n; j++)
        cin>>s[j];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            a[i][j] = 0;
    int i, j, tag=0;
    for(i=0; i<n; i++){
        for(j=0; j<m; j++)
            if(findpath(W, s, a, count, i, j, n, m)){
                cout<<"YES"<<endl;
                tag=1;
                break;
            }
        if(tag==1) break;
    }
    if(!tag) cout<<"NO"<<endl;
    return 0;
}
