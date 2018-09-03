/*
	题目描述：
	从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
*/
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > ret;
        queue<TreeNode*> q;
        if(pRoot) q.push(pRoot);
        while(!q.empty()){
            vector<int> tmp;
            int n = q.size();
            while(n--){
                TreeNode* node = q.front();
                tmp.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                q.pop();
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};