#include "model\TreeNode.h"

class Solution {
public:
	int deepestLeavesSum(TreeNode* root) {
		max_level = 0;
		sum = 0;
		if(root != nullptr)
			_1(root, 1);
		return sum;
	}
private:
	int max_level;
	int sum;
	/**
	 * @brief deep-first traverse
	 * @perf: [62, 91]
	 */
	void _1(TreeNode* root, int level){
		if(root->left == nullptr && root->right == nullptr)
			if(level == max_level)
				sum += root->val;
			else if(level > max_level){
				sum = root->val;
				max_level = level;
			}
		if(root->left != nullptr)
			_1(root->left, level + 1);
		if(root->right != nullptr)
			_1(root->right, level + 1);
	}
};
