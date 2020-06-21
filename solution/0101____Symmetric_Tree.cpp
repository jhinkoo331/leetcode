#include "model\TreeNode.h"
#include <queue>

//TODO

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		_1(root);
	}
private:
	/**
	 * @perf: [57, 5]
	 * @space: 
	 * @time: O(n): n is count of nodes
	 * @param root 
	 * @return true 
	 * @return false 
	 */
	bool _1(TreeNode* root){
		if(root == nullptr)
			return true;
		std::queue<TreeNode*> ll, rr;		//* left first and right first stacks, to traverse nodes in the tree
		ll.push(root);
		rr.push(root);
		while(!ll.empty()){
			if(ll.front()->val != rr.front()->val)
				return false;
			if(ll.front()->left != nullptr ^ rr.front()->right != nullptr)
				return false;
			if(ll.front()->right != nullptr ^ rr.front()->left != nullptr)
				return false;
			if(ll.front()->left != nullptr)
				ll.push(ll.front()->left);
			if(ll.front()->right != nullptr)
				ll.push(ll.front()->right);
			ll.pop();
			if(rr.front()->right != nullptr)
				rr.push(rr.front()->right);
			if(rr.front()->left != nullptr)
				rr.push(rr.front()->left);
			rr.pop();
		}
		return true;
	}
};