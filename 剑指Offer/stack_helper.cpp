#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size() == 0) return false;
        for(int i=0, j=0; i<pushV.size(); i++){
            help.push(pushV[i]);
            while(j<popV.size()&&help.top()==popV[j]) {
                help.pop();
                j++;
            }
        }
        return help.empty();
    }
private:
    stack<int> help;
};

int main()
{
    int a[5] = {1,2,3,4,5}, b[5] = {4,5,3,2,1};
    vector<int> pushV(a,a+5);
    vector<int> popV(b,b+5);
    Solution sol;
    cout<<sol.IsPopOrder(pushV,popV)<<endl;
    return 0;
}
