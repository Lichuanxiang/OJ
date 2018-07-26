/**
    1. ����ת�ַ�����ʹ��sprintf()����
        char str[10];
        double a=123.321;
        sprintf(str,"%.3lf",a);
    2. �ַ���ת���֣�ʹ��sscanf()����
        char str[]="1234321";
        int a;
        sscanf(str,"%d",&a);
    3. ʹ��stringstream��
        ��ostringstream����дһ���ַ�����������sprintf()
          ostringstream s1;
          int i = 22;
          s1 << "Hello " << i << endl;
          string s2 = s1.str();
          cout << s2;

        ��istringstream�����һ���ַ�����������sscanf()
          istringstream stream1;
          string string1 = "25";
          stream1.str(string1);
          int i;
          stream1 >> i;
          cout << i << endl;  // displays 25
**/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXINT 1000000
#define MININT -1000000

using namespace std;

int main()
{
    char s[10], t[15];
    int a, b, sum, len, count=0;
    memset(s, 0, sizeof(s));
    memset(t, 0, sizeof(t));
    cin>>a>>b;
    sum = a+b;

    sprintf(s, "%d", sum);          //������ת��Ϊ�ַ������飬���λ����s[0]

    len = strlen(s);
    if(s[0]!='-' && len<=3) cout<<sum<<endl;
    else if(s[0]=='-' && len<=4) cout<<sum<<endl;
    else
    {
        for(int i=len-1; i>=0 && s[i]!=0; i--)
        {
            t[count++] = s[i];
            if(i && (count+1)%4==0 && s[i-1]!='-'){
                t[count++] = ',';
            }
        }
        for(int i=strlen(t)-1; i>=0; i--)
            cout<<t[i];
        cout<<endl;
    }

    return 0;
}
