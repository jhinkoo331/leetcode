#include "model\ListNode.h"

//TODO discuss


class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		return _1(head, val);
	}
private:
	/**
	 * @brief 
	 * @perf: [62, 7]
	 * @param head 
	 * @param val 
	 * @return ListNode* 
	 */
	ListNode* _1(ListNode* head, int val){
		ListNode dummy;
		ListNode* dmy = &dummy;
		dmy->next = head;
		ListNode* pre = dmy;
		while(pre->next != nullptr){
			if(pre->next->val == val){
				ListNode* temp = pre->next;
				pre->next = pre->next->next;
				delete temp;
			}else
				pre = pre->next;
		}
		return dmy->next;
	}
};
