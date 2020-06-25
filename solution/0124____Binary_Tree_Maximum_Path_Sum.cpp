#include "model\TreeNode.h"
#include <algorithm>
using std::max;

class Solution {
public:
	int maxPathSum(TreeNode* root) {
		cur_max = 0x80000000;
		_1(root);
		return cur_max;
	}
private:
	int cur_max;
	/**
	 * @brief 
	 * @perf: [56, 87]
	 * @param root current node
	 * @return int non-negative
	 */
	int _1(TreeNode* root){
		if(root == nullptr)
			return 0;
		int left = _1(root->left);
		int right = _1(root->right);
		//* update cur_max
		cur_max = max(cur_max, root->val + left + right);
		//* return
		int temp = root->val + max(left, right);
		return temp > 0 ? temp : 0;
	}
};
