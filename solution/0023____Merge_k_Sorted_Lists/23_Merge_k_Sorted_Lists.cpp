struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};



#include <vector>
#include <queue>
using namespace std;


struct cmp{
	bool operator()(ListNode* lhs, ListNode* rhs){
		return lhs->val > rhs->val;
	}
};


class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode* head = new ListNode(0);		// head node
		ListNode* tail = head;
		priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
		for(const auto& elem: lists){
			if(elem != nullptr){
				pq.push(elem);
			}
		}
		while(!pq.empty()){
			tail->next = pq.top();
			tail = tail->next;
			pq.pop();
			if(tail->next != nullptr){
				pq.push(tail->next);
			}
		}
		tail->next = nullptr;
		return head->next;
	}
};


int main(){
	// 1-3-8
	// 2-4-7
	// 0-0-1
	ListNode* a = new ListNode(1);
	a->next = new ListNode(3);
	a->next->next = new ListNode(8);
	ListNode* b = new ListNode(2);
	b->next = new ListNode(4);
	b->next->next = new ListNode(7);
	ListNode* c = new ListNode(0);
	c->next = new ListNode(0);
	c->next->next = new ListNode(1);
	vector<ListNode*> v = {a, b, c};
	Solution sln;
	sln.mergeKLists(v);
	return 0;
}