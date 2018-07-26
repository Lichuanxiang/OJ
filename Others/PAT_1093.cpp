/**
    Count PATs
    >> һά��̬�滮
    �����ж��ٶ�PAT��ֻҪһ��ɨ�輴�ɣ�O(N)��
    ��һ��������¼��ǰλ��֮ǰ�ж��ٶ�PA����������T��ʱ��ǰ���PA��Ŀ����������PAT��Ŀ��
    ��������A��ʱ��PA����Ŀ���ܻ����ӣ�����Ҫ��һ��������¼��ǰλ��֮ǰ�ж��ٸ�P��
    ����A��ʱ��ǰ��P����Ŀ����������PA��Ŀ��
    ��long long��¼�������������
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
