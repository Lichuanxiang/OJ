/*
	题目描述：
	从上往下打印出二叉树的每个节点，同层节点从左至右打印。
*/
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> v;
        v.clear();
        if(root==NULL) return v;
        q.push(root);
        while(!q.empty()){
            root = q.front();
            v.push_back(root->val);
            q.pop();
            if(root->left) q.push(root->left);
            if(root->right) q.push(root->right);
        }
        return v;
    }
};