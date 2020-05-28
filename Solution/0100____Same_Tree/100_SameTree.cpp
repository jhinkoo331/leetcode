struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		return isSameTree_1(p, q);
	}
private:
	// todo: in a non-recursive way
	bool isSameTree_1(TreeNode* p, TreeNode* q){
		if(p == nullptr & q == nullptr){
			return true;
		}
		if(p == nullptr ^ q == nullptr){
			return false;
		}
		if(p->val == q->val && isSameTree_1(p->left, q->left) && isSameTree_1(p->right, q->right)){
			return true;
		}else{
			return false;
		}
	}
};
