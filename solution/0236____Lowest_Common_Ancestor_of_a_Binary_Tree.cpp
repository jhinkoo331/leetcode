#include "model\TreeNode.h"
#include <vector>
#include <queue>
using std::vector;
using std::queue;


class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		return _1(root, p, q);
	}
private:
	/*
	 * perf: [54, 9]
	 */
	TreeNode* _1(TreeNode* root, TreeNode* p, TreeNode* q){
		//* make sure that the whole tree is not empty
		if(root == nullptr)
			return nullptr;
		vector<TreeNode*> p_path;
		vector<TreeNode*> q_path;
		helper(root, p, p_path);
		helper(root, q, q_path);
		int min = p_path.size() < q_path.size() ? p_path.size() : q_path.size();
		int i = 0;
		while(i + 1 < min && p_path[i + 1] == q_path[i + 1])
			++i;
		return p_path[i];
	}
	/**
	 * @param root not nullptr
	 * @param target p or q, the TreeNode we need to find in the tree
	 * @param path to store the path from root to current node
	 */
	bool helper(TreeNode* root, TreeNode* target, vector<TreeNode*>& path){
		path.push_back(root);
		bool flag = root == target;
		if(flag)
			return true;
		if(root->left != nullptr)
			flag = helper(root->left, target, path);
		if(flag)
			return flag;
		if(root->right != nullptr)
			flag = helper(root->right, target, path);
		if(flag)
			return flag;
		path.pop_back();
		return false;
	}
};

TreeNode* search_by_value(TreeNode* root, int val){
	queue<TreeNode*> q;
	if(root != nullptr)
		q.push(root);
	while(!q.empty()){
		if(q.front()->val == val)
			return q.front();
		if(q.front()->left != nullptr)
			q.push(q.front()->left);
		if(q.front()->right != nullptr)
			q.push(q.front()->right);
		q.pop();
	}
	return nullptr;
}

#include "util\Serial.h"

int main(int argc, char const *argv[]) {
	TreeNode* root;
	Serial::de_serialize(root, "[3,5,1,6,2,0,8,null,null,7,4]");
	Solution sln;
	sln.lowestCommonAncestor(root, search_by_value(root, 5), search_by_value(root, 1));
	sln.lowestCommonAncestor(root, search_by_value(root, 5), search_by_value(root, 4));
	return 0;
}
