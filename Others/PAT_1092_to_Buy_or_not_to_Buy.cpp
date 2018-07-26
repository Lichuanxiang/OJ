#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main()
{
    string a, b;
    cin>>a>>b;
    int flag[b.length()];
    int count = 0;
    memset(flag, 0, sizeof(flag));
    for(int i=0; i<b.length(); i++)
    {
        for(int j=0; j<a.length(); j++)
        {
            if(a[j]==b[i])
            {
                flag[i] = 1;
                a[j] = '@';
                break;
            }
        }
        if(!flag[i]) count++;
    }

    if(!count)
    {
        cout<<"Yes "<<(a.length()-b.length())<<endl;
    }
    else
    {
        cout<<"No "<<count<<endl;
    }

    return 0;
}
