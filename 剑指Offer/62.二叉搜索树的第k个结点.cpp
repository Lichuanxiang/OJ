/*
	题目描述：
	给定一棵二叉搜索树，请找出其中的第k小的结点。例如,（5，3，7，2，4，6，8）中，按结点数值大小顺序第三小结点的值为4。
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
    int count = 0;
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot){
            TreeNode* node = KthNode(pRoot->left, k);
            if(node) return node;
            if(++count==k) return pRoot;
            node = KthNode(pRoot->right, k);
            if(node) return node;
        }
        return NULL;
    }
};