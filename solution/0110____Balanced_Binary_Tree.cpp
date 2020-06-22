#include "model\TreeNode.h"
#include <cmath>
#include <algorithm>

class Solution {
public:
	bool isBalanced(TreeNode* root) {
		return _1(root) != -1;
	}
private:
	/**
	 * @brief 
	 * @perf: [55, 51]
	 * @time: 
	 * @space: O(deepth of the tree)
	 * @param root 
	 * @return return -1 when the tree is not balanced, return the tree's height if the tree is balanced.
	 */
	int _1(TreeNode* root){
		if(root == nullptr)		//* a empty tree is balanced with height of 0
			return 0;
		int ll = _1(root->left);
		if(ll == -1)
			return -1;
		int rr = _1(root->right);
		if(rr == -1)
			return -1;
		if(abs(ll - rr) <= 1)
			return 1 + std::max(ll, rr);
		else
			return -1;
	}
};