#include <iostream>
#include <algorithm>

using namespace std;

int a[5];//原始数组
int b[2];//挑选的结果
static int num = 0;
const int need=2;//需要选择的个数

//求组合数
void combine(int start,int end,int x)
{
    if(x==need)
    {
        num++;
        //（1）打印组合的内容
        /*
        for(int i=0;i<need;i++)
        {
            cout<<b[i]<<" ";
        }
        cout<<endl;
        */
        //（2）对每一种组合进行排列
        //permute(b,0,2);//见下
        return;
    }
    if((end-start)<(need-x))//如果剩下的元素个数＜需要的数
    {
        return;
    }
    b[x]=a[start];//先选择一个
    combine(start+1,end,x+1);//再从剩下的集合中选择m-1个
    combine(start+1,end,x);//然后再从剩下的集合（即缩小的集合中选择m个）
}

//全排列
void permute(int c[],int start,int end)
{
    if(start==end) //挑选完毕
    {
        /*打印数组*/
        for(int i=0;i<end;i++)
        {
            cout<<c[i]<<" ";
        }
        cout<<endl;
     }
    else
    {
        for(int i=start;i<end;i++)
        {
            swap(c[i],c[start]);//一次挑选n个字母中的一个
            permute(c,start+1,end);//再对其余的n-1个字母一次挑选
            swap(c[i],c[start]);//恢复原字符串

        }
    }
}

int main(){
    for(int i=0; i<7; i++)
        a[i] = i+1;
    combine(0, 4, 0);
    cout<<num<<endl;
    return 0;
}