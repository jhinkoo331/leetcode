#include <queue>
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
	int maxDepth(TreeNode* root) {
		return maxDepth_1(root);
	}
private:
	//* level traverse
	int maxDepth_1(TreeNode* root){
		int depth = 0;
		queue<TreeNode*> q;
		q.push(nullptr);
		q.push(root);
		bool is_first = false;
		while(!q.empty()){
			TreeNode* temp = q.front();
			q.pop();
			if(temp == nullptr){
				is_first = true;
				continue;
			}else{
				if(is_first){
					q.push(nullptr);
					depth++;
				}
				if(temp->left != nullptr){
					q.push(temp->left);
				}
				if(temp->right != nullptr){
					q.push(temp->right);
				}
				is_first = false;
			}
		}
		return depth;
	}
};