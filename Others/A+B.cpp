/**
    1. 数字转字符串：使用sprintf()函数
        char str[10];
        double a=123.321;
        sprintf(str,"%.3lf",a);
    2. 字符串转数字：使用sscanf()函数
        char str[]="1234321";
        int a;
        sscanf(str,"%d",&a);
    3. 使用stringstream类
        用ostringstream对象写一个字符串，类似于sprintf()
          ostringstream s1;
          int i = 22;
          s1 << "Hello " << i << endl;
          string s2 = s1.str();
          cout << s2;

        用istringstream对象读一个字符串，类似于sscanf()
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

    sprintf(s, "%d", sum);          //将数字转换为字符串数组，最高位放在s[0]

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
