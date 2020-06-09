#include "model\ListNode.h"
#include "util\Serial.h"

using namespace std;

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		return reverseBetween_1(head, m, n);
	}

private:
	ListNode* reverseBetween_1(ListNode* head, int m, int n){
		ListNode* pre = head;
		ListNode* pre_next;
		ListNode* cur = nullptr;
		for(int i = 2; i < m; ++i){
			pre = pre->next;
		}
		pre_next = pre->next;
		cur = pre_next->next;
		for(int i = m; i < n; ++i){
			ListNode* temp = pre_next->next;
			pre_next->next = temp->next;
			temp->next = pre_next;
			pre->next = temp;
		}
		return head;
	}
};

int main(){
	ListNode* head = nullptr;
	Serial::de_serialize(head, "[1,2,3,4,5]");
	Solution sln;
	sln.reverseBetween(head, 2, 4);
	return 0;
}
