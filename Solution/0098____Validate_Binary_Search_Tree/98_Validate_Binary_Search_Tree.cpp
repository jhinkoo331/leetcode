
// Definition for a binary tree node.
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
	bool isValidBST(TreeNode* root) {		//* return `true` when `root` is empty
		if(root == nullptr){
			return true;
		}
		is_first = true;
		valid_BST = true;
		this->inorder_traverse(root);
		return this->valid_BST;
	}
private:
	int last;
	int is_first;
	bool valid_BST;
	void inorder_traverse(TreeNode* root){
		if(root == nullptr){
			return;
		}
		//* left
		if(root->left != nullptr){
			inorder_traverse(root->left);
		}
		//* root
		if(is_first){
			is_first = false;
		}else if(root->val <= last){
			valid_BST = false;
			return; 
		}
		last = root->val;
		//* right
		if(root->right != nullptr){
			inorder_traverse(root->right);
		}
	}
};


int main(){
	Solution sln;
	bool ret;
	ret = sln.isValidBST(nullptr);
	TreeNode* root1 = new TreeNode(2);
	root1->left = new TreeNode(1);
	root1->right = new TreeNode(3);
	ret = sln.isValidBST(root1);
	TreeNode* root2 = new TreeNode(5);
	root2->left = new TreeNode(1);
	root2->right = new TreeNode(4);
	root2->right->left = new TreeNode(3);
	root2->right->right = new TreeNode(6);
	ret = sln.isValidBST(root2);
	return 0;
}