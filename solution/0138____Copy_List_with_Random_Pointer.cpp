#define NULL nullptr

class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
	val = _val;
	next = NULL;
	random = NULL;
	}
};

class Solution {
public:
	Node* copyRandomList(Node* head) {
		return _1(head);
	}
private:
	//* perf: [90, 63]
	//TODO discuss
	Node* _1(Node* head){
		Node* pre = head;
		while(pre != nullptr){
			Node* _new = new Node(pre->val);
			_new->next = pre->next;
			pre->next = _new;
			pre = pre->next->next;
		}
		pre = head;
		while(pre != nullptr){
			if(pre->random != nullptr)
				pre->next->random = pre->random->next;
			pre = pre->next->next;
		}
		Node dummy(0);
		Node* tail = &dummy;
		pre = head;
		while(pre != nullptr){
			tail->next = pre->next;
			tail = tail->next;
			pre->next = pre->next->next;
			pre = pre->next;
		}
		// pre->next = nullptr;
		tail->next = nullptr;
		return dummy.next;
	}
};

