#include "model\TreeNode.h"
#include <vector>


class Solution {
public:
	int sumNumbers(TreeNode* root) {
		cur = 0;
		sum = 0;
		if(root != nullptr)
			_1(root);
		return sum;
	}
private:
	int cur;
	int sum;
	/**
	 * @brief recursive
	 * @perf: [7, 85]
	 * @param root 
	 */
	void _1(TreeNode* root){
		cur *= 10;
		cur += root->val;
		if(root->left == nullptr && root->right == nullptr)
			sum += cur;
		if(root->left != nullptr)
			_1(root->left);
		if(root->right != nullptr)
			_1(root->right);
		cur /= 10;
	}
};
