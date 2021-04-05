#include <stack>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
	int goodNodes(TreeNode* root) {
		return goodNodes_1(root);
	}

private:
	//* perf: [64, 100]
	int goodNodes_1(TreeNode* root){
		if(root == nullptr){
			return 0;
		}
		stack<int> max_in_path;
		max_in_path.push(0x80000000);	//* push int32_min into the stack
		int good_nodes_count = 0;
		deep_first_traverse(root, max_in_path, good_nodes_count);
		return good_nodes_count;
	}
	void deep_first_traverse(TreeNode* root, stack<int>& max_in_path, int& good_nodes_count){
		//* argument 1: `root` is guranteed not null
		if(root->val >= max_in_path.top()){
			max_in_path.push(root->val);
			good_nodes_count++;
		}else{
			max_in_path.push(max_in_path.top());
		}
		if(root->left != nullptr){
			deep_first_traverse(root->left, max_in_path, good_nodes_count);
		}
		if(root->right != nullptr){
			deep_first_traverse(root->right, max_in_path, good_nodes_count);
		}
		max_in_path.pop();
	}
};

int main(){
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(1);
	root->left->left = new TreeNode(3);
	root->right = new TreeNode(4);
	root->right->left = new TreeNode(1);
	root->right->right = new TreeNode(5);
	Solution sln;
	sln.goodNodes(root);
	return 0;
}

