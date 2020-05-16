#define NULL 0
//   Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	//* slow and fast pointers.
	bool hasCycle(ListNode *head) {
		if(head == NULL)
			return false;
		ListNode* slow = head;
		ListNode* fast = head;
		while(true){
			fast = fast->next;
			if(fast == NULL)
				return false;
			if(fast == slow)
				return true;
			fast = fast->next;
			if(fast == NULL)
				return false;
			if(fast == slow)
				return true;
			slow = slow->next;
		}
		return false;			//* this line is never reached, add to make it compilable
	}
};


int main(){
	ListNode* head = new ListNode(3);
	head->next = new ListNode(2);
	head->next->next = new ListNode(0);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = head->next;
	Solution sln;
	sln.hasCycle(head);
	return 0;
}