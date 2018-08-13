/*
	题目描述：
	输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
    假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入
    前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，
    则重建二叉树并返回。
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.empty()||vin.empty()) return NULL;
        TreeNode* root = new TreeNode(pre[0]);
        int index;
        for(index=0; index<vin.size(); index++){
            if(vin[index]==pre[0]) break;
        }
        vector<int> left_pre, right_pre, left_in, right_in;
        for(int i=0; i<index; i++) left_in.push_back(vin[i]);
        for(int i=index+1; i<vin.size(); i++) right_in.push_back(vin[i]);
        for(int i=1; i<=left_in.size(); i++) left_pre.push_back(pre[i]);
        for(int i=left_in.size()+1; i<pre.size(); i++) right_pre.push_back(pre[i]);
        root->left = reConstructBinaryTree(left_pre,left_in);
        root->right = reConstructBinaryTree(right_pre,right_in);
        return root;
    }
};