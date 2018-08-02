/**	
	AVL树得名于它的发明者G. M. Adelson-Velsky和E. M. Landis
	AVL树是最先发明的自平衡二叉查找树。在AVL树中任何节点的两个子树的高度最大差别为1，所以它也被称为高度平衡树。
	查找、插入和删除在平均和最坏情况下的时间复杂度都是 O(logn)
	假设AVL树中每个节点的权值均不相同
**/
#include <cstdio>
#include <algorithm>

using namespace std;

struct node
{
	int data, height;
	node *left, *right;
};

node* newNode(int x){
	node* root = new node;
	root->data = x;
	root->height = 1;
	root->left= root->right = NULL;
	return root;
}

int getHeight(node* root){
	if(!root) return 0;
	return root->height;
}

//获取平衡因子
int getBalanceFactor(node* root){
	return getHeight(root->left) - getHeight(root->right);
}

void updateHeight(node* root){
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}

bool search(node* root, int value){
	if(!root) return false;
	if(root->data==value) return true;
	else return root->data>value ? search(root->left, value) : search(root->right, value);
}

void leftRotation(node* &root){
	node* temp = root->right;
	root->right = temp->left;
	temp->left = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

void rightRotation(node* &root){
	node* temp = root->left;
	root->left = temp->right;
	temp->right = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

void insert(node* &root, int x){
	if(!root){
		root = newNode(x);
		return;
	}
	if(x < root->data){
		insert(root->left, x);
		updateHeight(root);
		if(getBalanceFactor(root)==2){
			if(getBalanceFactor(root->left)==1)  //LL型
				rightRotation(root);
			else if(getBalanceFactor(root->left)==-1){  //LR型(插入节点在左子树的右子树上)
				leftRotation(root->left);
				rightRotation(root);
			}
		}
	}
	else{
		insert(root->right, x);
		updateHeight(root);
		if(getBalanceFactor(root)==-2){
			if(getBalanceFactor(root->right)==-1)  //RR型
				leftRotation(root);
			else if(getBalanceFactor(root->right)==1){  //RL型(插入节点在右子树的左子树上)
				rightRotation(root->right);
				leftRotation(root);
			}
		}
	}
}

void deleteAVL(node* &root, int x){
    if (!root) return;
    if (x < root->data){ // 待删除的节点在"tree的左子树"中
        deleteAVL(root->left, x);
    	updateHeight(root);
        if (getBalanceFactor(root) == -2){ // 删除节点后,若AVL树失去平衡,则进行相应的调节
            if(getBalanceFactor(root->right)==1) { //RL型(删除节点后右子树的左子树上多出一层)
				rightRotation(root->right);
				leftRotation(root);
			}
			else if(getBalanceFactor(root->right)==-1) //RR型
				leftRotation(root);
        }
    }
    else if (x > root->data){ // 待删除的节点在"tree的右子树"中
        deleteAVL(root->right, x);
        updateHeight(root);
		if(getBalanceFactor(root)==2){
			if(getBalanceFactor(root->right)==1)  //LL型
				rightRotation(root);
			else if(getBalanceFactor(root->right)==-1){  //LR型(删除节点后左子树的右子树上多出一层)
				leftRotation(root->left);
				rightRotation(root);
			}
		}
    }
    else { // root是对应要删除的节点
        if ((root->left) && (root->right)){ // root的左右孩子都非空
            if (getHeight(root->left) > getHeight(root->right)){
                // 如果tree的左子树比右子树高,用"root的左子树中最大节点"做"root"的替身；
                // 采用这种方式的好处是：删除"root的左子树中最大节点"之后，AVL树仍然是平衡的。
                node* maxNode = root->left;
                while(maxNode->right){
                	maxNode = maxNode->right;
                }
                int maxValue = maxNode->data;
                deleteAVL(root->left, maxValue);
            }
            else
            {
                // 如果root的左子树不比右子树高(即它们相等，或右子树比左子树高1),用"root的右子树中最小节点"做"root"的替身
                node* minNode = root->right;
                while(minNode->left){
                	minNode = minNode->left;
                }
                int minValue = minNode->data;
                deleteAVL(root->right, minValue);
            }
        }
        else { //root的左右孩子至少有一个为空
            node *temp = root;
            root = root->left ? root->left : root->right;
            free(temp);
        }
    }
}


node* createAVL(int data[], int n){
	node* root = NULL;
	for(int i=0; i<n; i++)
		insert(root, data[i]);
	return root;
}

void preOrder(node* root){
	if(root==NULL) return;
	printf("%d\n", root->data);
	preOrder(root->left);
	preOrder(root->right);
}

void destroyAVL(node* tree){
    if (tree==NULL)
        return ;
    if (tree->left != NULL)
        destroyAVL(tree->left);
    if (tree->right != NULL)
        destroyAVL(tree->right);
    free(tree);
}

int main(){
	int data[5] = {3,1,2,6,5};
	node* root = createAVL(data, 5);
	printf("%d\n", getBalanceFactor(root));
	preOrder(root);
	deleteAVL(root, 3);
	preOrder(root);
	return 0;
}