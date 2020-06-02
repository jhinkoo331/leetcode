#include "model\ListNode.h"
using namespace std;


class Solution {
public:
	ListNode* sortList(ListNode* head) {
		return sortList_1(head);
	}
private:
	//* binary partition
	//* perf: [8, 15]
	ListNode* sortList_1(ListNode* head){
		ListNode* new_head = new ListNode();
		new_head->next = head;
		partition_1(new_head, nullptr);
		ListNode* temp = new_head->next;
		delete new_head;
		return temp;
	}
	//* `left` and `right` are not to be sorted
	//* make sure that left is not nullptr and left->next != right
	void partition_1(ListNode* left, ListNode* right){
		if(left == nullptr || left->next == right){
			return;
		}
		ListNode* pivot = left->next;
		ListNode* cur = pivot->next;
		ListNode* left_tail = left;
		ListNode* right_tail = pivot;
		while(cur != right){
			ListNode* next = cur->next;
			if(cur->val <= pivot->val){
				left_tail->next = cur;
				left_tail = cur;
			}else{
				right_tail->next = cur;
				right_tail = cur;
			}
			cur = next;
		}
		left_tail->next = pivot;
		right_tail->next = right;
		if(left->next != pivot){
			partition_1(left, pivot);
		}
		if(pivot->next != right){
			partition_1(pivot, right);
		}
	}
};

