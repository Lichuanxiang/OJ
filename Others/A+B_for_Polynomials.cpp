#include <iostream>
#include <stdio.h>
using namespace std;

const int K = 20;

int main()
{
    int k1, k2, count=0;
    int i, j;
    int a_exp[K], b_exp[K], c_exp[K];
    double a_coef[K], b_coef[K], c_coef[K];

    cin>>k1;
    for(i=0; i<k1; i++)
        cin>>a_exp[i]>>a_coef[i];

    cin>>k2;

    for(j=0; j<k2; j++){
        cin>>b_exp[j]>>b_coef[j];
    }

    i=0, j=0;
    while(i<k1 && j<k2)
    {
        if(a_exp[i]>b_exp[j])
        {
            c_exp[count] = a_exp[i];
            c_coef[count++] = a_coef[i++];
        }
        else if(a_exp[i]==b_exp[j])
        {
            c_exp[count] = a_exp[i];
            c_coef[count] = a_coef[i++] + b_coef[j++];
            if(c_coef[count]!=0) count++;
        }
        else
        {
            c_exp[count] = b_exp[j];
            c_coef[count++] = b_coef[j++];
        }
    }

    if(i<k1)
        for(; i<k1; i++){
            c_exp[count] = a_exp[i];
            c_coef[count++] = a_coef[i];
        }
    if(j<k2)
        for(; j<k2; j++){
            c_exp[count] = b_exp[j];
            c_coef[count++] = b_coef[j];
        }

    cout<<count;
    if(count > 0)
    {
        for(i=0; i<count; i++)
        {
            printf(" %d %.1f", c_exp[i], c_coef[i]);
        }

        printf("\n");

    }

    return 0;
}
