#include <vector>
#include <algorithm>
#include <queue>
#include "model\TreeNode.h"
using std::vector;


class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> v;
		if(root != nullptr)
			_2(root, 0 , v);
		std::reverse(v.begin(), v.end());
		return v;
	}
private:
	/**
	 * @perf: [4ms, 78]
	 * 
	 * @param root 
	 * @param v 
	 */
	void _1(TreeNode* root, vector<vector<int>>& v){
		// v.clear();
		std::queue<TreeNode*> q;
		if(root != nullptr)
			q.push(root);
		while(!q.empty()){
			int sz = q.size();
			v.push_back(vector<int>());
			while(sz--){
				v.back().push_back(q.front()->val);
				if(q.front()->left != nullptr)
					q.push(q.front()->left);
				if(q.front()->right != nullptr)
					q.push(q.front()->right);
				q.pop();
			}
		}
		std::reverse(v.begin(), v.end());
	}
	/**
	 * @brief you need reverse v after this procedure finished.
	 * 
	 * @param root make sure that root is not nullptr
	 * @param level `root`'s level in the original tree, counts from 0
	 * @param v 
	 */
	void _2(TreeNode* root, int level, vector<vector<int>>& v){
		//* v.size() is more than level by 1 at most
		if(v.size() == level)
			v.push_back(vector<int>());
		v[level].push_back(root->val);
		if(root->left != nullptr)
			_2(root->left, level + 1, v);
		if(root->right != nullptr)
			_2(root->right, level + 1, v);
	}
};
