#include "model\ListNode.h"

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		return insertionSortList_1(head);
	}
private:
	//* perf: [40, 71]
	ListNode* insertionSortList_1(ListNode* head){
		ListNode dummy(-1);
		while(head != nullptr){
			ListNode* cur = head;
			head = head->next;
			ListNode* temp = &dummy;
			while(temp->next != nullptr && temp->next->val < cur->val)
				temp = temp->next;
			cur->next = temp->next;
			temp->next = cur;
		}
		return dummy.next;
	}
};
