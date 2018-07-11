/***
	注意点：字典序排列(sort)；特殊用例："aa"只输出一个"aa"；"ab"则输出"ab"和"ba"
***/

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> perms;
        if(str.size()==0) return perms;
        perm(perms, str, 0);
        sort(perms.begin(), perms.end());
        return perms;
    }
    void perm(vector<string> &perms, string str, int begin){
        if(begin==str.length()-1){
            perms.push_back(str);
        }
        else{
            for(int i=begin; i<=str.length()-1; i++){
                if(i!=begin && str[i]==str[begin])
                    continue;
                swap(str[i], str[begin]);
                perm(perms, str, begin+1);
                swap(str[i], str[begin]);
            }
        }
    }
};