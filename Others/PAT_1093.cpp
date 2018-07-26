/**
    Count PATs
    >> 一维动态规划
    计算有多少对PAT，只要一遍扫描即可，O(N)。
    用一个变量记录当前位置之前有多少对PA，这样遇到T的时候前面的PA数目就是新增的PAT数目。
    由于遇到A的时候PA的数目可能会增加，还需要用一个变量记录当前位置之前有多少个P，
    遇到A的时候前面P的数目就是新增的PA数目。
    用long long记录总数避免溢出。
**/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int PA=0, P=0;
    long long count = 0;
    for(int i=0; i<s.length(); i++)
    {
        switch(s[i])
        {
        case 'T':
            count+=PA;
            break;
        case 'A':
            PA+=P;
            break;
        case 'P':
            P++;
            break;
        }
    }
    cout<<count%1000000007<<endl;
    return 0;
}
