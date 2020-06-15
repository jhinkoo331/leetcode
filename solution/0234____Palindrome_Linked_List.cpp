#include "model\ListNode.h"
#include <stack>
using std::stack;

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		return _1(head);
	}
private:
	/**
	 * @brief A in-place algorithm, reverse the right half part, and compare left part and right part iteratively.
	 * but the original list would be modified.
	 * @perf: [72, 55]
	 * @param head 
	 * @return true the list is palindrome
	 * @return false not palindrome
	 */
	bool _1(ListNode* head){
		if(head == nullptr)
			return true;		//todo
		ListNode* slow = head;
		ListNode* fast = head;
		while(fast->next != nullptr && fast->next->next != nullptr){
			fast = fast->next->next;
			slow = slow->next;
		}
		//* now slow is the mid node.
		ListNode dummy;
		ListNode* dmy = &dummy;
		slow = slow->next;
		while(slow != nullptr){
			ListNode* temp = slow;
			slow = slow->next;
			temp->next = dmy->next;
			dmy->next = temp;
		}
		while(dmy->next != nullptr)
			if(dmy->val != head->val)
				return false;
			else{
				dmy = dmy->next;
				head = head->next;
			}
		return true;
	}
};

int main(int argc, char const *argv[])
{
	ListNode* head = new ListNode(1);
	Solution sln;
	sln.isPalindrome(head);
	return 0;
}

