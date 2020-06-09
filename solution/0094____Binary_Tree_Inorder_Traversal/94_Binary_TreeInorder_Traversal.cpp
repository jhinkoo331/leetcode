#include <vector>
#include <stack>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

enum state {LEFT, SELF, RIGHT, FINISHED};
 
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		stack<pair<TreeNode*, state>> s;
		vector<int> ret;
		if(root == nullptr){
			return ret;
		}
		s.push(make_pair(root, LEFT));
		while(!s.empty()){
			if(s.top().second == FINISHED){
				s.pop();
			}else if(s.top().second == LEFT){
				s.top().second = SELF;
				if(s.top().first->left != nullptr){
					s.push(make_pair(s.top().first->left, LEFT));
				}
			}else if(s.top().second == SELF){
				s.top().second = RIGHT;
				ret.push_back(s.top().first->val);
			}else{		//* s.top().second == RIGHT
				s.top().second = FINISHED;
				if(s.top().first->right != nullptr){
					s.push(make_pair(s.top().first->right, LEFT));
				}
			}
		}
		return ret;
	}
};


int main(){
	TreeNode* root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);
	Solution sln;
	sln.inorderTraversal(root);
	sln.inorderTraversal(nullptr);
	return 0;
}