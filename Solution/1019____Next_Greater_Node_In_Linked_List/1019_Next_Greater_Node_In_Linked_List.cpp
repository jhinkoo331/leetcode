#include <vector>
#include <queue>
#include "model\ListNode.h"
using namespace std;

class Compare{
public:
	bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) const{
		return lhs.first > rhs.first;
	}
};

class Solution {
public:
	vector<int> nextLargerNodes(ListNode* head) {
		return nextLargerNodes_1(head);
	}
private:
	//! perf: [28, 5]
	vector<int> nextLargerNodes_1(ListNode* head){
		//! priority_queue<pair<value, index>>
		priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
		vector<int> ans;
		while(head != nullptr){
			ans.push_back(0);	//* 0 is the default value
			while(!pq.empty() && pq.top().first < head->val){
				ans[pq.top().second] = head->val;
				pq.pop();
			}
			pq.push({head->val, ans.size() - 1});
			head = head->next;
		}
		return ans;
	}
};


int main(){
	ListNode* head = new ListNode(2);
	head->next = new ListNode(1);
	head->next->next = new ListNode(5);
	Solution sln;
	sln.nextLargerNodes(head);
	return 0;
}
