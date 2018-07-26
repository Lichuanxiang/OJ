#include <iostream>
#include <string>
#include <string.h>

#define MAXN 1000+1
using namespace std;

string usr[MAXN], psw[MAXN];
int flag[MAXN];

int main()
{
    int n, count=0;
    bool changed = false;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>usr[i]>>psw[i];
    memset(flag, 0, sizeof(flag));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<psw[i].length(); j++)
        {
            switch(psw[i][j]){
            case '1':
                psw[i][j] = '@';
                if(!flag[i]) flag[i] = 1;
                changed = true;
                break;
            case '0':
                psw[i][j] = '%';
                if(!flag[i]) flag[i] = 1;
                changed = true;
                break;
            case 'l':
                psw[i][j] = 'L';
                if(!flag[i]) flag[i] = 1;
                changed = true;
                break;
            case 'O':
                psw[i][j] = 'o';
                if(!flag[i]) flag[i] = 1;
                changed = true;
                break;
            }
        }
        if(changed) count++;
        changed = false;
    }
    if(!count&&n==1) cout<<"There is "<<n<<" account and no account is modified"<<endl;
    else if(!count&&n>1) cout<<"There are "<<n<<" accounts and no account is modified"<<endl;
    else
    {
        cout<<count<<endl;
        for(int i=0; i<n; i++)
        {
            if(flag[i]==1)
            {
                cout<<usr[i]<<" "<<psw[i]<<endl;
            }
        }
    }



    return 0;
}
