#ifndef SERIAL_H
#define SERIAL_H 

#include <string>
#include <sstream>
#include <queue>
#include "model\ListNode.h"
#include "model\TreeNode.h"

using std::string;
using std::queue;


class Serial{
public:
	static int k;
	static void de_serialize(ListNode*& head, std::string s);
	static void de_serialize(TreeNode*& root, std::string s);
};



void Serial::de_serialize(ListNode*& head, std::string s){
	for(int i = 0; i < s.size(); ++i){
		if(!isdigit(s[i]) & s[i] != '-' & s[i] != '+'){
			s[i] = ' ';
		}
	}
	std::stringstream ss;
	ss << s;
	int val;
	head = new ListNode();
	ListNode* tail = head;
	while(ss >> val){
		tail->next = new ListNode(val);
		tail = tail->next;
	}
	ListNode* temp = head->next;
	delete head;
	head = temp;
}


void Serial::de_serialize(TreeNode*& root, std::string s){
	for(auto& e: s)
		if(e == '[' || e == ']' || e == ',')
			e = ' ';
	if(s.empty())
		return;
	std::stringstream ss;
	ss << s;
	root = new TreeNode();
	ss >> root->val;
	queue<TreeNode*> q;
	q.push(root);
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
}

#endif
