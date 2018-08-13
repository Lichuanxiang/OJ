/*
	题目描述：
	输入一颗二叉树的跟节点和一个整数，打印出二叉树中
	结点值的和为输入整数的所有路径。路径定义为从树的根结点
	开始往下一直到叶结点所经过的结点形成一条路径。
	(注意: 在返回值的list中，数组长度大的数组靠前)
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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        int currentSum = 0;
        vector<int> path;
        vector<vector<int>> allPath;
        if(root) findPath(root, expectNumber, path, currentSum, allPath);
        return allPath;
    }
    void findPath(TreeNode* root, int expectNumber, vector<int> &path, int currentSum, vector<vector<int>> &allPath)
    {
        currentSum += root->val;
        path.push_back(root->val);
        if(currentSum == expectNumber && !root->left && !root->right)
        {
            allPath.push_back(path);
        }
        if(root->left) findPath(root->left, expectNumber, path, currentSum, allPath);
        if(root->right) findPath(root->right, expectNumber, path, currentSum, allPath);
        path.pop_back();
    }
};