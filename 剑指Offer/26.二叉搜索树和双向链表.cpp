/*
    题目描述：
    输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
    要求不能创建任何新的结点，只能调整树中结点指针的指向。    
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