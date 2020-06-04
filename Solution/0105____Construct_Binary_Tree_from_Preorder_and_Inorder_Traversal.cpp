#include "model\TreeNode.h"
#include <vector>
using namespace std;

class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		//! check whether preorder is empty before calling solution 1
		if(preorder.empty())
			return nullptr;
		else
			return buildTree_1(preorder, 0, preorder.size(), inorder, 0, inorder.size());
	}
private:
	/**
	 * * [81, 10]
	 * ! we need make sure that l < r and ll < rr before calling this function.
	 * ! we already that two traversal sequences could build a binary tree.
	 * @param preorder_inorder two traversal sequence
	 * @param l_r_ll_rr left and right index of the sequence, note that valid range are [l, r) and [ll, rr)
	 */
	TreeNode* buildTree_1(vector<int>& preorder, int l, int r, vector<int>& inorder, int ll, int rr){
		//* position is the index of the root node in `inorder` sequence
		int pos = ll;
		while(inorder[pos] != preorder[l])
			pos++;
		//* left sub-tree's size: position - ll
		//* right sub-tree's size: rr - position - 1
		TreeNode* root = new TreeNode(preorder[l]);
		if(pos - ll != 0)
			root->left = buildTree_1(preorder, l + 1, l + pos - ll + 1, inorder, ll, pos);
		if(rr - pos - 1 != 0)
			root->right = buildTree_1(preorder, l + pos - ll + 1, r, inorder, pos + 1, rr);
		return root;
	}
	//TODO: iterative https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/34555/The-iterative-solution-is-easier-than-you-think!
};

int main(){
	vector<int> pre = {1, 2, 3};
	vector<int> in = {2, 3, 1};
	Solution sln;
	TreeNode* root = sln.buildTree(pre, in);
	return 0;
}

