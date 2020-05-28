#include <vector>
#include <string>
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
	vector<string> binaryTreePaths(TreeNode* root){
		return this->sln_1(root);
	}
private:
	vector<TreeNode*> path;
	vector<string> ret;

	vector<string> sln_1(TreeNode* root){
		path.clear();
		ret.clear();
		if(root != nullptr)
			deep_first_traverse(root);
		return ret;
	}

	void deep_first_traverse(TreeNode* root){
		path.push_back(root);
		if(root->left == nullptr & root->right == nullptr){	//* this is a leaf node
			string temp;
			for(int i = 0; i < path.size() - 1; ++i){
				temp += to_string(path[i]->val);
				temp += "->";
			}
			temp += to_string(path.back()->val);
			ret.push_back(temp);
		}
		if(root->left != nullptr){
			deep_first_traverse(root->left);
		}
		if(root->right != nullptr){
			deep_first_traverse(root->right);
		}
		path.pop_back();
	}
};

