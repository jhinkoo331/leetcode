#include "model\TreeNode.h"
#include <algorithm>
using std::max;


class Solution {
public:
	int diameterOfBinaryTree(TreeNode* root) {
		diameter = 0;
		_1(root);
		return diameter;
	}
private:
	int diameter;
	/**
	 * @brief 
	 * @perf: [24, 66]
	 * @param root 
	 * @return int 
	 */
	int _1(TreeNode* root){
		if(root == nullptr)
			return 0;
		int left = _1(root->left);
		int right = _1(root->right);
		diameter = max(diameter, 1 + left + right);
		return 1 + max(left, right);
	}
};

int main(){
	Solution sln;
	sln.diameterOfBinaryTree(nullptr);
	return 0;
}
