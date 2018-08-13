/*
    题目描述
    输入一个字符串,按字典序打印出该字符串中字符的所有排列。
    例如输入字符串abc,则打印出由字符a,b,c所能排列出来的
    所有字符串abc,acb,bac,bca,cab和cba。
    输入描述:
    输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
*/

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