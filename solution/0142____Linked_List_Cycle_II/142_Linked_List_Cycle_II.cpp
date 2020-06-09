#define NULL 0
// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if(head == NULL)
			return NULL;
		ListNode* slow = head;
		ListNode* fast = head;
		bool has_cycle = 0;
		while(true){
			fast = fast->next;
			if(fast == NULL)
				break;
			if(fast == slow){
				has_cycle = 1;
				break;
			}
			fast = fast->next;
			if(fast == NULL)
				break;
			if(fast == slow){
				has_cycle = 1;
				break;
			}
			slow = slow->next;
		}
		if(!has_cycle)
			return NULL;
		int count = 0;
		while(true){
			fast = fast->next;
			count++;
			if(fast == slow)
				break;
		}
		slow = head;
		fast = head;
		while(count--)
			fast = fast->next;
		while(slow != fast){
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}
};