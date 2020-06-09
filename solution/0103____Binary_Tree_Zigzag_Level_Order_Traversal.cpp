#include <vector>
#include <queue>
#include "model\TreeNode.h"
using namespace std;


class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		return zigzagLevelOrder_1(root);
	}
private:
	//* base on BFS.
	//* [100, 100]
	vector<vector<int>> zigzagLevelOrder_1(TreeNode* root){
		vector<vector<int>> v;
		queue<TreeNode*> q;
		if(root != nullptr)
			q.push(root);
		bool left_to_right = false;
		while(!q.empty()){
			left_to_right = !left_to_right;		//* change direction
			int level_count = q.size();		//* nodes in this level
			v.push_back(vector<int>(level_count));
			for(int i = 0; i < level_count; ++i){
				TreeNode* temp = q.front();
				q.pop();
				if(left_to_right)
					v.back()[i] = temp->val;
				else
					v.back()[level_count - 1 - i] = temp->val;
				if(temp->left != nullptr)
					q.push(temp->left);
				if(temp->right != nullptr)
					q.push(temp->right);
			}
		}
		return v;
	}
	//todo: DFS based method, link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/discuss/33815/My-accepted-JAVA-solution
};
