#include "model\TreeNode.h"
#include <string>
#include <queue>
#include <sstream>
using std::string;
using std::queue;
using std::to_string;
using std::stringstream;
using std::stoi;

class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		return serialize_1(root);
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		return deserialize_1(data);
	}
private:
	/**
	 * * level traverse
	 * @return	root == nullptr: ""
	 * 		root != nullptr: "1 2 3 ", "1 - 2 3 4 "
	 */
	string serialize_1(TreeNode* root){
		string ret;
		queue<TreeNode*> q;
		q.push(root);
		bool flag = root != nullptr;
		while(flag){
			flag = false;
			int sz = q.size();
			while(sz--){
				if(q.front() == nullptr){
					ret += "null ";
				}else{
					ret += to_string(q.front()->val) + ' ';
					q.push(q.front()->left);
					q.push(q.front()->right);
					if(q.front()->left != nullptr || q.front()->right != nullptr)
						flag = true;
				}
				q.pop();
			}
		}
		return ret;
	}
	/**
	 * 
	 */
	TreeNode* deserialize_1(string data){
		if(data.empty())
			return nullptr;
		stringstream ss;
		ss << data;
		TreeNode* root = new TreeNode();
		ss >> root->val;
		queue<TreeNode*> q;
		q.push(root);
		string s;
		bool to_fill_left = true;
		while(ss >> s){
			if(s == "null"){
				if(!to_fill_left)
					q.pop();
				to_fill_left ^= 1;
			}else{
				if(to_fill_left){
					q.front()->left = new TreeNode();
					q.front()->left->val = stoi(s);
					q.push(q.front()->left);
				}else{
					q.front()->right = new TreeNode();
					q.front()->right->val = stoi(s);
					q.push(q.front()->right);
					q.pop();
				}
				to_fill_left ^= 1;
			}
		}
		return root;
	}
};

int main(){
	Codec sln;
	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);
	sln.deserialize(sln.serialize(root));
	return 0;
}