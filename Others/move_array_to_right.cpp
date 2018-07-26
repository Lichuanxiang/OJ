#include <stdio.h>

int main()
{
    int str[200];
    int N, M;
    int i, temp;
    scanf("%d", &N);
    scanf("%d", &M);

    if(M>=N) M %= N;

    for(i=0; i<N; i++){
        scanf("%d", str+i);
    }

    for(i=0; i<N/2; i++){
        temp = str[N-i-1];
        str[N-i-1] = str[i];
        str[i] = temp;
    }

    for(i=0; i<M/2; i++){
        temp = str[M-i-1];
        str[M-i-1] = str[i];
        str[i] = temp;
    }

    for(i=M; i<(N+M)/2; i++){
        temp = str[N+M-i-1];
        str[N+M-i-1] = str[i];
        str[i] = temp;
    }

    for(i=0; i<N-1; i++){
        printf("%d ", str[i]);
    }
    printf("%d", str[N-1]);
    return 0;
}
