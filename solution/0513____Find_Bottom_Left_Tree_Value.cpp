#include "model\TreeNode.h"
#include <vector>
#include <queue>
using std::queue;
using std::vector;


class Solution {
public:
	int findBottomLeftValue(TreeNode* root) {
		return _2(root);
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
	/**
	 * @brief level traverse
	 * @perf: [90, 48]
	 * @param root 
	 * @return int 
	 */
	int _2(TreeNode* root){
		queue<TreeNode*> q;
		q.push(root);
		int ans;
		while(q.size()){
			int count = q.size();
			ans = q.front()->val;
			while(count--){
				if(q.front()->left != nullptr)
					q.push(q.front()->left);
				if(q.front()->right != nullptr)
					q.push(q.front()->right);
				q.pop();
			}
		}
		return ans;
	}
};