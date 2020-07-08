#include <queue>
#include "model\TreeNode.h"

class Solution {
public:
	int maxDepth(TreeNode* root) {
		return _1(root);
	}
private:
	/**
	 * @brief level traversal
	 * @perf: [82, 100]
	 */
	int _1(TreeNode* root){
		std::queue<TreeNode*> q;
		if(root != nullptr)
			q.push(root);
		int level = 0;
		while(!q.empty()){
			++level;
			int k = q.size();
			while(k--){
				if(q.front()->left != nullptr)
					q.push(q.front()->left);
				if(q.front()->right != nullptr)
					q.push(q.front()->right);
				q.pop();
			}
		}
		return level;
	}
};