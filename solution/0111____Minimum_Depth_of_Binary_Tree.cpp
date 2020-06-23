#include "model\TreeNode.h"
#include <queue>


class Solution {
public:
	int minDepth(TreeNode* root) {
		return _1(root);
	}
private:
	/**
	 * @brief 
	 * @perf: [90, 75]
	 * @param root 
	 * @return int 
	 */
	int _1(TreeNode* root){
		std::queue<TreeNode*> q;
		int deepth = 0;
		if(root != nullptr)	
			q.push(root);
		while(!q.empty()){
			++deepth;
			int k = q.size();
			while(k--){
				if(q.front()->left == nullptr && q.front()->right == nullptr)
					return deepth;
				if(q.front()->left != nullptr)
					q.push(q.front()->left);
				if(q.front()->right != nullptr)
					q.push(q.front()->right);
				q.pop();
			}
		}
		return 0;		//* root is nullptr
	}
};
