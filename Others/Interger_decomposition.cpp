#include <stdio.h>
#include <string.h>

#define MAXN 100

int count;
void search(int remainder, int start, char *str);

int main()
{
    char str[MAXN];
    int n;
    count = 0;
    scanf("%d",&n);
    sprintf(str, "%d=", n);     //n=

    search(n, 1, str);

    if(count%4!=0)
        printf("\n");

    return 0;
}

void search(int remainder, int start, char *str)
{
    int i;
    char temp[MAXN];
    strcpy(temp, str);
    for(i=start; i<=remainder; i++)
        if(remainder-i>=i)
        {
            sprintf(temp+strlen(str),"%d+", i);
            search(remainder-i, i, temp);
        }
        else if(remainder-i==0)
        {
            sprintf(temp+strlen(str), "%d", i);
            count++;
            if(count%4!=1) printf(";");
            printf("%s", temp);
            if(count%4==0) printf("\n");
        }

}
