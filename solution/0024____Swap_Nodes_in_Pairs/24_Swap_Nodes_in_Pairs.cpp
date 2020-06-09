
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
	ListNode* swapPairs(ListNode* head) {
		ListNode* temp = new ListNode(0);
		ListNode* cur = temp;
		temp->next = head;
		while(true){
			if(cur->next != nullptr && cur->next->next != nullptr){		//* cur is guaranteed not null
				//* continue swapping
				ListNode* t = cur->next->next;
				cur->next->next = cur->next->next->next;
				t->next = cur->next;
				cur->next = t;
				cur = cur->next->next;
			}else{
				return temp->next;
			}
		}
	}
};

int main(){
	Solution sln;
	sln.swapPairs(nullptr);
	ListNode* ln = new ListNode(0);
	// sln.swapPairs(ln);
	ln->next = new ListNode(1);
	// sln.swapPairs(ln);
	ln->next->next = new ListNode(2);
	// sln.swapPairs(ln);
	ln->next->next->next = new ListNode(3);
	sln.swapPairs(ln);
	return 0;
}