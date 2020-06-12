/**
 * @file 0235____Lowest_Common_Ancestor_of_a_Binary_Search_Tree.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-06-12
 * 
 * @copyright Copyright (c) 2020
 * @todo closed
 */
#include "model\TreeNode.h"


class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		return _1(root, p, q);
	}
private:
	/**
	 * @brief 
	 * * perf: [72, 82]
	 * * time: O(log(n)), the deepth of the result
	 * * space: constant
	 * @param root 
	 * @param p 
	 * @param q 
	 * @return TreeNode* 
	 */
	TreeNode* _1(TreeNode* root, TreeNode* p, TreeNode* q){
		while(true){
			if(root->val > p->val && root->val > q->val)
				root = root->left;
			else if(root->val < p->val && root->val < q->val)
				root = root->right;
			else
				return root;
		}
	}
};
