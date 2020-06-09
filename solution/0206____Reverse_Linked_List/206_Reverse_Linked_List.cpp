#include <vector>
#include <stack>
#include "model\ListNode.h"
#include "util\Serial.h"

using namespace std;


class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		return reverseList_1(head);
	}
private:
	//* stack
	//* perf: [70, 100]
	ListNode* reverseList_1(ListNode* head){
		stack<ListNode*> s;
		while(head != nullptr){
			s.push(head);
			head = head->next;
		}
		ListNode* ret = new ListNode();
		ListNode* tail = ret;
		while(!s.empty()){
			tail->next = s.top();
			tail = tail->next;
			s.pop();
		}
		tail->next = nullptr;
		//* free `ret`, use `tail` to store it
		tail = ret;
		ret = ret->next;
		delete tail;
		return ret;
	}
};


int main(){
	Solution sln;
	ListNode* head;
	Serial::de_serialize(head, "1 2 3 4 5");
	sln.reverseList(head);
	return 0;
}