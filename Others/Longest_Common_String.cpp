/**
    最长公共子序列
**/

#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAXN 100

using namespace std;

int b[MAXN][MAXN];
int c[MAXN][MAXN];
int m,n;
char str1[MAXN],str2[MAXN];

void LCS()
{
    int i,j;
    for(i=0; i<=m; i++) c[i][0] = 0;
    for(j=0; j<=n; j++) c[0][j] = 0;

    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
            if(str1[i-1]==str2[j-1])
            {
                c[i][j] = c[i-1][j-1]+1;
                b[i][j] = 0;
            }
            else if(c[i-1][j]>c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                b[i][j] = 1;
            }
            else
            {
                c[i][j] = c[i][j-1];
                b[i][j] = -1;
            }
}

void PrintLCS(int i, int j)
{
    if(i==0 || j==0) return;
    if(b[i][j]==0)
    {
        PrintLCS(i-1,j-1);
        printf("%c ",str1[i-1]);
    }
    else if(b[i][j]==-1) PrintLCS(i, j-1);
    else PrintLCS(i-1,j);
}

int main()
{
    scanf("%s%s",str1,str2);
    m = strlen(str1);
    n = strlen(str2);
    LCS();
    printf("%d\n",c[m][n]);
    PrintLCS(m,n);

    return 0;
}
