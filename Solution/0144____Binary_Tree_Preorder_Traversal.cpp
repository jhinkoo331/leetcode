#include <vector>
#include <stack>
#include "model\TreeNode.h"
using namespace std;

enum state {s_root, s_left, s_right, s_finished};

class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		return preorderTraversal_3(root);
	}
private:
	//* recursive
	//* [100, 100]
	vector<int> preorderTraversal_1(TreeNode* root){
		vector<int> v;
		if(root != nullptr){
			recursive(root, v);
		}
		return v;
	}
	void recursive(TreeNode* root, vector<int>& v){
		v.push_back(root->val);
		if(root->left != nullptr){
			recursive(root->left, v);
		}
		if(root->right != nullptr){
			recursive(root->right, v);
		}
	}

	//* non-recursive
	//* [100, 100]
	vector<int> preorderTraversal_2(TreeNode* root){
		vector<int> v;
		if(root == nullptr){
			return v;
		}
		stack<pair<TreeNode*, state>> s;
		s.push({root, s_root});
		while(!s.empty()){
			switch (s.top().second)
			{
			case s_root:
				v.push_back(s.top().first->val);
				s.top().second = s_left;
				break;
			case s_left:
				s.top().second = s_right;
				if(s.top().first->left != nullptr){
					s.push({s.top().first->left, s_root});
				}
				break;
			case s_right:
				s.top().second = s_finished;
				if(s.top().first->right != nullptr){
					s.push({s.top().first->right, s_root});
				}
				break;
			case s_finished:
				s.pop();
				break;
			default:
				break;
			}
		}
		return v;
	}
	//* non-recursive
	//* [100, 100]
	vector<int> preorderTraversal_3(TreeNode* root){
		vector<int> v;
		stack<TreeNode*> to_visit;
		if(root != nullptr){
			to_visit.push(root);
		}
		while(!to_visit.empty()){
			auto temp = to_visit.top();
			to_visit.pop();
			v.push_back(temp->val);
			if(temp->right != nullptr)
				to_visit.push(temp->right);
			if(temp->left != nullptr)
				to_visit.push(temp->left);	
		}
		return v;
	}
};
