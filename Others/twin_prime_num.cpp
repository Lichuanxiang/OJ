#include<stdio.h>
#include<math.h>
#include<assert.h>

int is_prime(int x){
    int i,m;
    assert(x>=0);//x<0时程序会异常终止并给出提示信息
    if(x==1) return 0;
    //for(i=2; i*i<=x; i++)--i*i可能会发生溢出
    m = floor(sqrt(x)+0.5);//加上0.5是为了减小浮点型误差的影响
    for(i=2; i<=m; i++)
        if(x%i==0) return 0;
    return 1;
}

int main(){
    int i, m;
    scanf("%d", &m);
    for(i=m-2; i>=3; i--){
        if(is_prime(i)&&is_prime(i+2)){
            printf("%d %d\n", i, i+2);
            break;
        }
    }
    return 0;
}
