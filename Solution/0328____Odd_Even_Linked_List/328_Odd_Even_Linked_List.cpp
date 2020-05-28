
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		return oddEvenList_1(head);
	}
private:
	ListNode* oddEvenList_1(ListNode* head){
		if(head == nullptr || head->next == nullptr){
			return head;
		}
		ListNode* left_rear = head;
		ListNode* cur = head->next;
		while(true){
			if(cur == nullptr || cur->next == nullptr){
				break;
			}else{
				ListNode* temp = cur->next;
				cur->next = temp->next;
				cur = cur->next;
				
				temp->next = left_rear->next;
				left_rear->next = temp;
				left_rear = temp;
			}
		}
		return head;
	}
};


int main(){
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	Solution sln;
	sln.oddEvenList(head);
	return 0;
}
