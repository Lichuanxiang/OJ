//**掌握14-22行的思想
//**例如计算1000！，用数组f保存结果，f[1]是十位，f[2]是百位......

#include <stdio.h>
#include <string.h>

#define MAXN 3000
int f[MAXN];

int main()
{
    int i,j,n;
    scanf("%d",&n);
    memset(f,0,sizeof(f));
    f[0] = 1;
    for(i=2; i<=n; i++){
        int c = 0;
        for(j=0; j<MAXN; j++){
            int s = f[j]*i+c;
            f[j] = s%10;
            c = s/10;
        }
    }

    for(j=MAXN-1; j>=0; j--)
        if(f[j]) break; //将前面的0都去掉
    for(i=j; i>=0; i--) printf("%d", f[i]);

    printf("\n");

    return 0;
}
