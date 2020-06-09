#include <vector>
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
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		return this->pathSum_1(root, sum);
	}
private:
	vector<TreeNode*> path;
	vector<vector<int>> paths;
	int sum;
	int target;
	vector<vector<int>> pathSum_1(TreeNode* root, int _sum){
		path.clear();
		paths.clear();
		sum = 0;
		target = _sum;
		if(root != nullptr){
			deep_first_search(root);
		}
		return paths;
	}
	void deep_first_search(TreeNode* root){
		path.push_back(root);
		sum += root->val;
		if(root->left == nullptr && root->right == nullptr && sum == target){	//* this is a solution
			paths.push_back(vector<int>());
			for(const auto& elem: path){
				paths.back().push_back(elem->val);
			}
		}
		if(root->left != nullptr){
			deep_first_search(root->left);
		}
		if(root->right != nullptr){
			deep_first_search(root->right);
		}
		sum -= path.back()->val;
		path.pop_back();
	}
};


