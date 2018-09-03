/*
	题目描述：
	输入一棵二叉树，判断该二叉树是否是平衡二叉树。
*/
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        return getDepth(pRoot)!=-1;
    }
    int getDepth(TreeNode* root) {
        if(!root) return 0;
        int left = getDepth(root->left);
        if(left == -1) return -1;
        int right = getDepth(root->right);
        if(right == -1) return -1;
        return abs(left - right) > 1 ? -1 : 1 + max(left, right);
    }
};