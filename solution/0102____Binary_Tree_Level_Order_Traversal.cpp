#include <vector>
#include <queue>
#include "model\TreeNode.h"
using namespace std;


class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		return levelOrder_3(root);
	}
private:
	//* use two vectors
	//* [92, 100]
	vector<vector<int>> levelOrder_1(TreeNode* root){
		vector<vector<int>> v;
		if(root == nullptr)
			return v;
		vector<TreeNode*> v1, v2;
		v1.push_back(root);
		while(true){
			if(v1.empty())
				break;
			v.push_back(vector<int>());
			v2.clear();
			for(const auto& elem: v1){
				v.back().push_back(elem->val);
				if(elem->left != nullptr)
					v2.push_back(elem->left);
				if(elem->right != nullptr)
					v2.push_back(elem->right);
			}
			
			if(v2.empty())
				break;
			v.push_back(vector<int>());
			v1.clear();
			for(const auto& elem: v2){
				v.back().push_back(elem->val);
				if(elem->left != nullptr)
					v1.push_back(elem->left);
				if(elem->right != nullptr)
					v1.push_back(elem->right);
			}
		}
		return v;
	}
	//* insert a `nullptr` before a new line
	//* [92, 100]
	vector<vector<int>> levelOrder_2(TreeNode* root){
		vector<vector<int>> v;
		if(root == nullptr)		//! if `root` is empty and `q` is filled with two nullptr initially, `while(!q.empty())` will be an infinite loop.
			return v;
		queue<TreeNode*> q;
		q.push(nullptr);
		q.push(root);
		while(!q.empty()){
			TreeNode* temp;
			temp = q.front();
			q.pop();
			if(temp == nullptr && !q.empty()){
				v.push_back(vector<int>());
				q.push(nullptr);
			}else if(temp != nullptr){
				v.back().push_back(temp->val);
				if(temp->left != nullptr)
					q.push(temp->left);
				if(temp->right != nullptr)
					q.push(temp->right);
			}	
		}
		return v;
	}
	//* use a `level_count` to group different level's nodes
	//* [92, 100]
	vector<vector<int>> levelOrder_3(TreeNode* root){
		vector<vector<int>> v;
		if(root == nullptr)
			return v;
		queue<TreeNode*> q;
		q.push(root);
		while(!q.empty()){		//* visit all nodes in a level in every single loop
			v.push_back(vector<int>());
			int nodes_in_this_level = q.size();
			for(int i = 0; i < nodes_in_this_level; ++i){
				v.back().push_back(q.front()->val);
				if(q.front()->left != nullptr)
					q.push(q.front()->left);
				if(q.front()->right != nullptr)
					q.push(q.front()->right);
				q.pop();
			}
		}
		return v;
	}
	//todo: with a dfs way
};
