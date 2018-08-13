/*
	题目描述：
	输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
	如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
*/
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size()==0) return false;
        int root = sequence[sequence.size()-1];
        vector<int> left, right;
        for(int i=0; i<sequence.size()-1; i++){
            if(sequence[i]>root) break;
            left.push_back(sequence[i]);
        }
        for(int i=left.size(); i<sequence.size()-1; i++){
            if(sequence[i]<=root) return false;
            right.push_back(sequence[i]);
        }
        bool l=true, r=true;
        if(!left.empty()) l = VerifySquenceOfBST(left);
        if(!right.empty()) r = VerifySquenceOfBST(right);
        return l&&r;
    }
    /*解法2-非递归
    bool VerifySquenceOfBST(vector<int> sequence){
        int size = sequence.size();
        if(0 == size) return false;
        int i = 0;
        while(--size){
            while(sequence[i++] < sequence[size]);
            while(sequence[i++] > sequence[size]);
            if(i < size) return false;
            i = 0;
        }
        return true;
    }*/
};