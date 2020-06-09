#include <queue>
using namespace std;

class Node {
public:
	int val;
	Node* prev;
	Node* next;
	Node* child;
};

class Solution {
public:
	Node* flatten(Node* head) {
		return flatten_1(head);
	}
private:
	Node* flatten_1(Node* head){
		if(head == nullptr)
			return nullptr;
		Node dummy;
		Node* tail = &dummy;
		queue<Node*> q;
		q.push(head);
		if(q.front()->child != nullptr){
			q.push(q.front()->child);
			q.front()->child = nullptr;
		}
		while(!q.empty()){
			tail->next = q.front();
			q.front()->prev = tail;
			q.pop();
			while(tail->next != nullptr){
				tail = tail->next;
				if(tail->child != nullptr){
					q.push(tail->child);
					tail->child = nullptr;
				}
			}
		}
		// tail->next = nullptr;
		return dummy.next;
	}
};
