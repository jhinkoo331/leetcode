#include "model\ListNode.h"

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		return _1(head, k);
	}
private:
	/**
	 * @brief rotate the list to the right by k places
	 * @perf: [71, 62]
	 */
	ListNode* _1(ListNode* head, int k){
		if(head == nullptr)
			return nullptr;
		//* tail is the last element in the list, len is the length of the list
		int len = 1;
		ListNode* tail = head;
		while(tail->next != nullptr){
			++len;
			tail = tail->next;
		}
		//* right shift k places equals with left shift len - k places
		k %= len;
		k = len - k;
		//* make the list a circle
		tail->next = head;
		while(k--)
			tail = tail->next;
		head = tail->next;
		//* break the circle
		tail->next = nullptr;
		return head;
	}
};
