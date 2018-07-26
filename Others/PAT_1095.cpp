#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

struct node{
    string plate;
    int time;
    bool flag;  //false表示in
};

bool cmp(const node &a, const node &b)
{
    if(a.plate<b.plate) return true;
    else if(a.plate==b.plate) return (a.time<b.time);
    return false;
}

int main()
{
    /*
        string str1[16] = {"JH007BD","ZD00001","DB8888A","ZA3Q625","ZA133CH","ZD00001","JH007BD","ZA3Q625","JH007BD","ZA3Q625",
                        "JH007BD","ZA3Q625","JH007BD","ZA133CH","JH007BD","DB8888A"};
    */

    int n, k;
    cin>>n>>k;
    vector<node> data(n);
    string stime;
    char a[9];
    int h, m, s;
    for(int i=0; i<n; i++){
        scanf("%s",a);  //输入车牌号
        data[i].plate = a;
        scanf("%d:%d:%d", &h,&m,&s);
        data[i].time = (h*60+m)*60+s;
        scanf("%s",a);
        if(a[0]=='i') data[i].flag = false;
        else data[i].flag = true;
    }

    //对车牌号排序，对车牌号相同的按时间排序
    sort(data.begin(), data.end(), cmp);

    vector<int> inCar(24*60*60, 0);
    vector<int> outCar(24*60*60, 0);
    string curPlate = data[0].plate;
    int curTime = 0;
    vector<string> maxPlate;
    int maxTime = 0;
    for(int i=1; i<n; i++){
        if(data[i].plate==data[i-1].plate){
            if(data[i].flag&&!data[i-1].flag)
            {
                curTime += data[i].time-data[i-1].time;     //可能in、out之后又in、out，统计总的时间
                if(curTime>maxTime){
                    maxTime = curTime;
                    maxPlate.clear();
                    maxPlate.push_back(curPlate);
                }else if(maxTime==curTime)
                    maxPlate.push_back(curPlate);
                inCar[data[i-1].time]++;
                outCar[data[i].time]++;
            }
        } else{
            curPlate = data[i].plate;
            curTime = 0;
        }
    }

    vector<int> result(24*60*60,0);
    int car = 0;
    for(int i=0; i<24*60*60; i++)
    {
        int car = car + inCar[i] - outCar[i];
        result[i] = car;
    }

    for(int i=0; i<k; i++)
    {
        scanf("%d:%d:%d",&h,&m,&s);
        cout<<result[(h*60+m)*60+s]<<endl;
    }

    for(vector<string>::iterator iter=maxPlate.begin(); iter!=maxPlate.end(); iter++)
        cout<<*iter<<" ";
    printf("%02d:%02d:%02d",maxTime/3600,maxTime%3600/60,maxTime%60);

    return 0;
}
