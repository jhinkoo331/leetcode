#include "model\ListNode.h"
 
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		return _1(l1, l2);
	}
private:
	ListNode* _1(ListNode* l1, ListNode* l2){
		ListNode head;		//* head is initialized in stack
		ListNode* tail = &head;
		while(l1 != nullptr && l2 != nullptr)
			if(l1->val <= l2->val){
				tail->next = l1;
				l1 = l1->next;
				tail = tail->next;
			}else{
				tail->next = l2;
				l2 = l2->next;
				tail = tail->next;
			}
		if(l1 != nullptr)
			tail->next = l1;
		else
			tail->next = l2;
		return head.next;
	}
};
