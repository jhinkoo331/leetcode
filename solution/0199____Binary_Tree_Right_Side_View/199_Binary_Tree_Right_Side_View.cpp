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
	vector<int> rightSideView(TreeNode* root) {
		return this->sln_1(root);
	}
private:
	vector<int> sln_1(TreeNode* root){
		vector<int> v;
		if(root == nullptr){
			return v;
		}
		queue<TreeNode*> q;
		q.push(nullptr);
		q.push(root);
		bool flag = false;
		while(!q.empty()){
			if(q.front() == nullptr){
				flag = true;
				q.pop();
			}else{
				TreeNode* temp = q.front();
				q.pop();
				if(flag == true){
					q.push(nullptr);
					v.push_back(temp->val);
				}
				if(temp->right != nullptr){
					q.push(temp->right);
				}
				if(temp->left != nullptr){
					q.push(temp->left);
				}
				flag = false;
			}
		}
		return v;
	}
};
