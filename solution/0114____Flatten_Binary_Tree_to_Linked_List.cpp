/*
    1
   / \
  2   5
 / \   \
3   4   6

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
 */
#include "model\TreeNode.h"
//TODO discuss
class Solution {
public:
	void flatten(TreeNode* root) {
		if(root != nullptr)
			_1(root);
	}
private:
	/**
	 * @brief to make the tree of root a linked list and return the deepest node.
	 * *perf: [100, 61]
	 * @param root not nullptr, you should ensure that root is non-null before calling this function
	 * @return
	 */
	TreeNode* _1(TreeNode* root){
		//* process left child, make it a list
		if(root->left != nullptr){
			TreeNode* tail_from_left_child = _1(root->left);
			tail_from_left_child->right = root->right;
			root->right = root->left;
			root->left = nullptr;
		}
		if(root->right == nullptr)
			return root;
		else
			return _1(root->right);
	}
};
