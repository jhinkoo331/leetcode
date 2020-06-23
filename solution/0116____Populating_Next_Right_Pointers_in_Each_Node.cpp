#ifndef NULL
#define NULL nullptr
#endif


class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() : val(0), left(NULL), right(NULL), next(NULL) {}

	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

	Node(int _val, Node* _left, Node* _right, Node* _next)
	: val(_val), left(_left), right(_right), next(_next) {}
};

#include <queue>
using std::queue;

class Solution {
public:
	Node* connect(Node* root) {
		return _1(root);
	}
private:
	/**
	 * @brief level traverse
	 * @perf: [92, 26]
	 * @time: O(n)
	 * @space: O(n)
	 */
	Node* _1(Node* root){
		queue<Node*> q;
		if(root != nullptr)
			q.push(root);
		while(!q.empty()){
			int k = q.size();
			for(int i = 1; i < k; ++i){
				Node* temp = q.front();
				q.pop();
				temp->next = q.front();
				if(temp->left != nullptr)
					q.push(temp->left);
				if(temp->right != nullptr)
					q.push(temp->right);
			}
			if(q.front()->left != nullptr)
				q.push(q.front()->left);
			if(q.front()->right != nullptr)
				q.push(q.front()->right);
			q.pop();
		}
		return root;
	}
	/**
	 * @brief 
	 * TODO: constant extra space
	 * @param root 
	 * @return Node* 
	 */
	Node* _2(Node* root){

	}
};