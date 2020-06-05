#include "model\ListNode.h"

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		// return addTwoNumbers_1(l1, l2);
		return addTwoNumbers_2(l1, l2);
	}
private:
	//* [94, 37]
	ListNode* addTwoNumbers_1(ListNode* l, ListNode* ll){
		ListNode ln;
		ListNode* tail = &ln;
		int carry = 0;
		while(l != nullptr | ll != nullptr){
			if(l != nullptr){
				carry += l->val;
				l = l->next;
			}
			if(ll != nullptr){
				carry += ll->val;
				ll = ll->next;
			}
			ListNode* temp = new ListNode(carry % 10);
			carry /= 10;
			tail->next = temp;
			tail = temp;
		}
		if(carry){
			ListNode* temp = new ListNode(carry);
			tail->next = temp;
			tail = temp;
		}
		return ln.next;
	}
	//* [99, 60]
	ListNode* addTwoNumbers_2(ListNode* l, ListNode* ll){
		ListNode ln;
		ListNode* tail = &ln;
		int carry = 0;
		while(l != nullptr | ll != nullptr){
			if(carry == 0){				//* in some cases, we may append the remaining part after current list and return.
				if(l == nullptr){
					tail->next = ll;
					return ln.next;
				}
				if(ll == nullptr){
					tail->next = l;
					return ln.next;
				}
			}
			ListNode* temp;
			if(l != nullptr){
				temp = l;
				carry += l->val;
				l = l->next;
			}
			if(ll != nullptr){
				temp = ll;
				carry += ll->val;
				ll = ll->next;
			}
			temp->val = carry % 10;
			carry /= 10;
			tail->next = temp;
			tail = temp;
		}
		if(carry){
			ListNode* temp = new ListNode(carry);
			tail->next = temp;
			tail = temp;
		}
		return ln.next;
	}
};
