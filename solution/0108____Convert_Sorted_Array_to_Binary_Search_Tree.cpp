#include "model\TreeNode.h"
#include <vector>
using std::vector;

//TODO


class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return _1(nums, 0, nums.size() - 1);
	}
private:
	/**
	 * @brief in a recursive way
	 * @perf: [81, 45]
	 * @time: 
	 * @space: O(log_n), the deepth of the tree
	 * @return TreeNode* 
	 */
	TreeNode* _1(vector<int>& nums, int ll, int rr){
		if(ll > rr)
			return nullptr;
		int mm = (rr - ll) / 2 + ll;
		TreeNode* root = new TreeNode(nums[mm]);
		root->left = _1(nums, ll, mm - 1);
		root->right = _1(nums, mm + 1, rr);
		return root;
	}
};

int main(){
	vector<int> v = {-10, -3, 0, 5, 9};
	Solution sln;
	TreeNode* root = sln.sortedArrayToBST(v);
	return 0;
}
