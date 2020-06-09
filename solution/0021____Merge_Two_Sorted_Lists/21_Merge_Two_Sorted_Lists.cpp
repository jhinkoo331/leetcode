// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode head = ListNode(0);
		ListNode* tail = &head;
		while(l1 != nullptr & l2 != nullptr){
			if(l1->val <= l2->val){
				tail->next = l1;
				l1 = l1->next;
				tail = tail->next;
			}else{
				tail->next = l2;
				l2 = l2->next;
				tail = tail->next;
			}
		}
		if(l1 != nullptr){
			tail->next = l1;
		}else{
			tail->next = l2;
		}
		tail = head.next;
		return tail;
	}
};


int main(){
	ListNode* l1 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(4);
	ListNode* l2 = new ListNode(1);
	l2->next = new ListNode(3);
	l2->next->next = new ListNode(4);
	Solution sln;
	sln.mergeTwoLists(l1, l2);
	sln.mergeTwoLists(nullptr, nullptr);
	return 0;
}