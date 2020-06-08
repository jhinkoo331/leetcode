#include "model\ListNode.h"

class Solution {
public:
	ListNode* middleNode(ListNode* head) {
		return middleNode_1(head);
	}
private:
	/*
	 * perf: [100, 57]
	 * time: O(n)
	 * space: O(1)
	 */
	ListNode* middleNode_1(ListNode* head){
		if(head == nullptr)
			return nullptr;
		ListNode* fast = head;
		while(fast->next != nullptr && fast->next->next != nullptr){
			fast = fast->next->next;
			head = head->next;
		}
		if(fast->next != nullptr)
			head = head->next;
		return head;
	}
	/*
	 * ! a more delicate way provided by LeetCode
	 * ! in this way, fast can reach one more step: shift into a nullptr node, which made the totally length of the list "grows by 1"
	 */
	ListNode* middleNode_2(ListNode* head){
		ListNode* fast = head;
		while(fast != nullptr && fast->next != nullptr){
			fast = fast->next->next;
			head = head->next;
		}
		return head;
	}
};
