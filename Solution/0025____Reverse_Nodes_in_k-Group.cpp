#include "model\ListNode.h"
#include <vector>
#include <algorithm>
using std::vector;
using std::reverse;


class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		return reverseKGroup_1(head, k);
	}
private:
	/**
	 * [47, 5]
	 * Time Complexity: O(n)
	 * Space Complexity: O(n)
	 */
	ListNode* reverseKGroup_1(ListNode* head, int k){
		vector<ListNode*> v;
		while(head != nullptr){
			v.push_back(head);
			head = head->next;
		}
		int t = v.size() / k;
		for(int i = 0; i < t; ++i)
		reverse(v.begin() + i * k, v.begin() + i * k + k);
		v.push_back(nullptr);
		for(int i = 1; i < v.size(); ++i){
			v[i - 1]->next = v[i];
		}
		return v.front();
	}
};
