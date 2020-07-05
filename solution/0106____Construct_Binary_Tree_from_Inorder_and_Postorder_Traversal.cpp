#include "model\TreeNode.h"
#include <vector>
#include <unordered_map>
using std::unordered_map;
using std::vector;


class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return _1(inorder, postorder);
	}
private:
	unordered_map<int, int> um;
	/**
	 * @brief recursive
	 * @perf: 70, 39
	 * @param inorder 
	 * @param postorder 
	 * @return TreeNode* 
	 */
	TreeNode* _1(vector<int>& inorder, vector<int>& postorder){
		//* <val, index> for inorder seq
		um.clear();
		for(int i = 0; i < inorder.size(); ++i)
			um[inorder[i]] = i;
		return _1_helper(inorder, 0, postorder, 0, inorder.size());
	}
	/**
	 * 
	 * @param in index of the first element in inorder sequence
	 * @param post ... in postorder sequence
	 * @param len the length of the sub-sequence
	 * @return TreeNode* 
	 */
	TreeNode* _1_helper(vector<int>& inorder, int in, vector<int>& postorder, int post, int len){
		if(len == 0)
			return nullptr;
		TreeNode* root = new TreeNode(postorder[post + len - 1]);
		//* index is the index of root value in inorder sequence
		int index = um[postorder[post + len - 1]];
		//* left subtree's size: index - in
		//* right subtree's size: len - (index - in) - 1
		root->left = _1_helper(inorder, in, postorder, post, index - in);
		root->right = _1_helper(inorder, index + 1, postorder, post + index - in, len - (index - in) - 1);
		return root;
	}
};
