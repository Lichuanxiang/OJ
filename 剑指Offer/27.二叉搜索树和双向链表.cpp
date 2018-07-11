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
    TreeNode* Convert(TreeNode* root)
    {
        if(!root) return NULL;
        if(!root->left&&!root->right) return root;
        TreeNode* left = Convert(root->left);
        TreeNode* p = left;
        while(p && p->right){
            p = p->right;
        }
        if(left){
            p->right = root;
            root->left = p;
        }
        TreeNode* right = Convert(root->right);
        if(right){
            right->left = root;
            root->right = right;
        }
        return left!=NULL ? left : root;
    }
};


/*非递归
class Solution {
public:
    TreeNode* Convert(TreeNode* root)
    {
        if(!root) return NULL;
        stack<TreeNode*> stack;
        TreeNode *p = root, *pre;
        bool isFirst = true;
        while(p || !stack.empty()){
            while(p){
                stack.push(p);
                p = p->left;
            }
            p = stack.top();
            stack.pop();
            if(isFirst){
                root = p;
                pre = root;
                isFirst = false;
            }
            else{
                pre->right = p;
                p->left = pre;
                pre = p;
            }
            p = p->right;
        }
        return root;
    }
};*/