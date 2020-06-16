#include <vector>
#include <queue>
using std::vector;
#include "model\TreeNode.h"

class Solution {
public:
	vector<double> averageOfLevels(TreeNode* root) {
		_1(root);
		return ans;
	}
private:
	vector<double> ans;
	/**
	 * @brief 
	 * @perf: [84, 50]
	 * @param root 
	 */
	void _1(TreeNode* root){
		ans.clear();
		std::queue<TreeNode*> q;
		if(root != nullptr)
			q.push(root);
		while(!q.empty()){
			int sz = q.size();
			double sum = 0;
			for(int i = 0; i < sz; ++i){
				if(q.front()->left != nullptr)
					q.push(q.front()->left);
				if(q.front()->right != nullptr)
					q.push(q.front()->right);
				sum += q.front()->val;
				q.pop();
			}
			ans.push_back(sum / sz);
		}
	}
};