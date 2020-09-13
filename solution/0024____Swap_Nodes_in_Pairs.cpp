#include "model\ListNode.h"
 
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		return _1(head);
	}
private:
	/**
	 * @perf: 4ms, 5 
	 */
	ListNode* _1(ListNode* head){
		ListNode temp;
		ListNode* cur = &temp;
		temp.next = head;
		while(true)
			if(cur->next != nullptr && cur->next->next != nullptr){		//* cur is guaranteed not null
				//* continue swapping
				ListNode* t = cur->next->next;
				cur->next->next = cur->next->next->next;
				t->next = cur->next;
				cur->next = t;
				cur = cur->next->next;
			}else
				return temp.next;
	}
};
