#include "model\TreeNode.h"

class Solution {
public:
	bool isSubStructure(TreeNode* A, TreeNode* B) {

	}
private:
	/**
	 * @brief B should be a subset of A
	 * 
	 * @param A 
	 * @param B 
	 * @return true B is a subset of A, and they share same root node
	 * @return false 
	 */
	bool _1(TreeNode* A, TreeNode* B){
		if(B == nullptr)
			return true;
		if(A == nullptr)
			return false;
		if(A->val == B->val && _1)
	}
};