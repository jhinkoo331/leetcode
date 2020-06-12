#include "model\TreeNode.h"
#include <queue>
using std::queue;


class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		return _1(root);
	}
private:
	//! perf: [100, 5]
	TreeNode* _1(TreeNode* root){
		queue<TreeNode*> q;
		if(root != nullptr)
			q.push(root);
		while (q.size()) {
			TreeNode* temp = q.front()->left;
			q.front()->left = q.front()->right;
			q.front()->right = temp;
			if(q.front()->left != nullptr)
				q.push(q.front()->left);
			if(q.front()->right != nullptr)
				q.push(q.front()->right);
			q.pop();
		}
		return root;	
	}
};