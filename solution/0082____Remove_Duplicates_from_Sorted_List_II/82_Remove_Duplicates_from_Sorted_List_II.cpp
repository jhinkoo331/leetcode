#include "model\ListNode.h"
#include "util\Serial.h"

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		return deleteDuplicates_1(head);
	}

private:
	//* perf: [45, 7]
	ListNode* deleteDuplicates_1(ListNode* head){
		ListNode* new_head = new ListNode();
		new_head->next = head;
		head = new_head;		//* `head` is now used to indicate `current node`'s previous node
		while(head->next != nullptr && head->next->next != nullptr){
			if(head->next->val == head->next->next->val){	//* removing consecutive duplicated nodes
				int val = head->next->val;
				while(head->next != nullptr && head->next->val == val){		//* [1, 1, 1], what if don't check head->next is not nullptr?
					ListNode* temp = head->next;
					head->next = temp->next;
					delete temp;
				}
			}else{		//* shift rightward
				head = head->next;
			}
		}
		head = new_head->next;
		delete new_head;
		return head;
	}
};
