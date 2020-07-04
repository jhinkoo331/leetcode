#include "model\TreeNode.h"
#include "util\Serial.h"
#include <queue>

class Solution {
public:
	int countNodes(TreeNode* root) {
		// return _1(root);
		return _2(root);
	}
private:
	/**
	 * @brief level traversal
	 * @perf: [86, 7]
	 * @time: O(n)
	 * @space: O(n)
	 */
	int _1(TreeNode* root){
		std::queue<TreeNode*> q;
		if(root != nullptr)
			q.push(root);
		int count = 0;
		while(!q.empty()){
			++count;
			if(q.front()->left != nullptr)
				q.push(q.front()->left);
			if(q.front()->right != nullptr)
				q.push(q.front()->right);
			q.pop();
		}
		return count;
	}
};

int main(){
	TreeNode* root;
	Serial::de_serialize(root, "1 2 3 4");
	Solution sln;
	sln.countNodes(root);
	return 0;
}