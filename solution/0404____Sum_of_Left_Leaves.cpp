#include "model/TreeNode.h"

class Solution {
public:
	int sumOfLeftLeaves(TreeNode* root) {
		return _1(root, false);
	}
private:
	/**
	 * @brief: recursion
	 * @perf: [4ms, 57]
	 */
	int _1(TreeNode* root, bool is_left){
		if(root == nullptr)
			return 0;
		if(root->left == nullptr && root->right == nullptr)
			return is_left ? root->val : 0;
		return _1(root->left, true) + _1(root->right, false);
	}
};
