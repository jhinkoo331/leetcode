#include "model\TreeNode.h"
#include "util\Serial.h"


class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		cur_sum = 0;
		target = sum;
		if(root == nullptr)
			return false;
		else
			return _1(root);
	}
private:
	int cur_sum;
	int target;
	/**
	 * @brief 
	 * @perf: [59, 9]
	 * @param root not nullptr
	 * @return true 
	 * @return false 
	 */
	bool _1(TreeNode* root){
		cur_sum += root->val;
		bool flag = false;
		if(root->left == nullptr && root->right == nullptr)
			flag = cur_sum == target;
		else if(root->left != nullptr && _1(root->left))
			flag = true;
		else if(root->right != nullptr && _1(root->right))
			flag = true;
		
		if(flag)
			return true;
		else{
			cur_sum -= root->val;
			return false;
		}
	}
};

int main(){
	TreeNode* root;
	Serial::de_serialize(root, "[5,4,8,11,null,13,4,7,2,null,null,null,1]");
	Solution sln;
	sln.hasPathSum(root, 22);
	return 0;
}
