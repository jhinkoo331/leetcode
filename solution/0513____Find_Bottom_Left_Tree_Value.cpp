#include "model\TreeNode.h"
#include <vector>
using std::vector;


class Solution {
public:
	int findBottomLeftValue(TreeNode* root) {
		return _1(root);
	}
	/**
	 * @brief level traverse
	 * @perf: [90, 10]
	 */
	int _1(TreeNode* root){
		vector<TreeNode*> row;
		if(root != nullptr)
			row.push_back(root);
		int ans;
		while(row.size()){
			ans = row.front()->val;
			vector<TreeNode*> new_row;
			for(auto e: row){
				if(e->left != nullptr)
					new_row.push_back(e->left);
				if(e->right != nullptr)
					new_row.push_back(e->right);
			}
			row.swap(new_row);
		}
		return ans;
	}
};