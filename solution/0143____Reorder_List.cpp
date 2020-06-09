#include "model\ListNode.h"
#include <stack>
using std::stack;


class Solution {
public:
	void reorderList(ListNode* head) {
		return reorderList_1(head);
	}
private:
	/*
	 * perf: [49, 28]
	 * Time: O(n + n/2 + n/2 + n/2) => O(n)
	 * Space: O(n/2) => O(n)
	 */
	void reorderList_1(ListNode* head){
		if(head == nullptr)
			return;
		//* get the mid node in the list.
		ListNode* slow = head;
		ListNode* fast = head;
		while(fast->next != nullptr && fast->next->next != nullptr){
			fast = fast->next->next;
			slow = slow->next;
		}
		//* let `fast` point to the first node of the right part
		fast = slow->next;
		//* break two parts of the list
		slow->next = nullptr;
		//* push all nodes in right part and reset their `next`
		stack<ListNode*> s;
		while(fast != nullptr){
			s.push(fast);
			fast = fast->next;
			s.top()->next = nullptr;
		}
		//* let fast point to the head of left part
		fast = head;
		//* insert all nodes from stack to it's location
		while(!s.empty()){
			s.top()->next = fast->next;
			fast->next = s.top();
			fast = s.top()->next;
			s.pop();
		}
	}
	//TODO: reverse the right part rather than using a stack, then merge two lists.
};

