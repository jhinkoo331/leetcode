#include "model\ListNode.h"

class Solution {
public:
	int getDecimalValue(ListNode* head) { 
		return getDecimalValue_1(head);
	}
private:
	/*
	 *  perf: [4ms, 58]
	 *  time: O(n)
	 *  space: O(1)
	 */
	int getDecimalValue_1(ListNode* head){
		int ans = 0;
		while(head != nullptr){
			//* ans *= 2
			ans <<= 1;
			//* ans += head->val == 1
			ans != head->val;
			head = head->next;
		}
		return ans;
	}
};
