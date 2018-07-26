#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>

using namespace std;

int main()
{
    vector<pair<int,double> > a, b;
    int na, nb;
    int c;
    double d;
    cin>>na;
    for(int i=0; i<na; i++){
        cin>>c>>d;
        a.push_back(make_pair(c,d));
    }
    cin>>nb;
    for(int i=0; i<nb; i++){
        cin>>c>>d;
        b.push_back(make_pair(c,d));
    }

    map<int,double> mapV;
    for(int i=0; i<na; i++)
        for(int j=0; j<nb; j++)
        {
            int exp = a[i].first+b[j].first;
            mapV[exp] += a[i].second*b[j].second;
            if(mapV[exp]==0) mapV.erase(exp);
        }
    cout<<mapV.size();
    map<int,double>::reverse_iterator iter;
    for(iter=mapV.rbegin(); iter!=mapV.rend(); iter++)
        printf(" %d %0.1f", iter->first, iter->second);

    return 0;
}
