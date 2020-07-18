#include "model\ListNode.h"
#include "util\Serial.h"
#include <stack>

using namespace std;

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		// return reverseBetween_1(head, m, n);
		return _2(head, m, n);
	}

private:
	ListNode* reverseBetween_1(ListNode* head, int m, int n){
		n = n - m + 1;
		ListNode new_head;
		new_head.next = head;
		ListNode* cur = &new_head;
		for(int i = 1; i < m; ++i)
			cur = cur->next;
		ListNode* tail = cur;
		ListNode* temp = cur->next;
		while(n--){
			tail->next = temp->next;
			temp->next = cur->next;
			cur->next = temp;
			temp = tail->next;
			tail = tail->next;
		}
		return new_head.next;
	}
	/**
	 * @perf: [4ms, 47]
	 * @time: O(n)
	 * @space: O(m - n)
	 */
	ListNode* _2(ListNode* head, int m, int n){
		ListNode temp;
		temp.next = head;
		head = &temp;
		ListNode* pre = head;
		for(int i = 1; i < m; ++i)
			pre = pre->next;
		std::stack<ListNode*> s;
		ListNode* cur = pre->next;
		while(m <= n){
			s.push(cur);
			cur = cur->next;
			++m;
		}
		while(!s.empty()){
			pre->next = s.top();
			s.pop();
			pre = pre->next;
		}
		pre->next = cur;
		return head->next;
	}
};

int main(){
	ListNode* head = nullptr;
	Serial::de_serialize(head, "[1,2,3,4,5]");
	Solution sln;
	sln.reverseBetween(head, 2, 4);
	return 0;
}
