#include "model\ListNode.h"


class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		return partition_1(head, x);
	}
private:
	//* perf: [92, 8]
	ListNode* partition_1(ListNode* head, int x){
		ListNode dummy_left, dummy_right;
		ListNode* dummy_l = &dummy_left, * dummy_r = &dummy_right;
		while(head != nullptr){
			if(head->val < x){
				dummy_l->next = head;
				dummy_l = head;
			}else{
				dummy_r->next = head;
				dummy_r = head;
			}
			head = head->next;
		}
		dummy_l->next = dummy_right.next;
		dummy_r->next = nullptr;
		return dummy_left.next;
	}
};
