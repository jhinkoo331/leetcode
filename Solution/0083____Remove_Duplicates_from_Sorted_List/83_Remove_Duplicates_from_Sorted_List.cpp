#include "model\ListNode.h"


class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		return deleteDuplicates_1(head);
	}
private:
	//* perf: [83, 5]
	ListNode* deleteDuplicates_1(ListNode* head){
		if(head == nullptr){
			return nullptr;
		}
		ListNode* tail = head;
		while(tail->next != nullptr){
			if(tail->val == tail->next->val){
				ListNode* temp = tail->next;
				tail->next = temp->next;
				delete temp;
			}else{
				tail = tail->next;
			}
		}
		return head;
	}
};


