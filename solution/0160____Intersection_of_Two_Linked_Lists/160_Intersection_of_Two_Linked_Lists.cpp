#include <stack>
using namespace std;

#define NULL 0

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		return sln_3(headA, headB);
	}
private:
	//* shift one of two pointers
	ListNode* solution1(ListNode* h, ListNode* hh){
		if(h == nullptr || hh == nullptr){		// todo
			return nullptr;
		}
		int len = 0, lenlen = 0;
		ListNode* t = h,* tt = hh;
		while(t->next != nullptr){
			len++;
			t = t->next;
		}
		while(tt->next != nullptr){
			lenlen++;
			tt = tt->next;
		}
		if(t != tt){
			return nullptr;
		}
		if(len > lenlen){
			for(int i = 0; i < len - lenlen; ++i){
				h = h->next;
			}
		}else{
			for(int i = 0; i < lenlen - len; ++i){
				hh = hh->next;
			}
		}
		while(h != hh){
			h = h->next;
			hh = hh->next;
		}
		return h;
	}  

	//* use stack to iterate List backward
	ListNode* sln_2(ListNode* h, ListNode* hh){
		stack<ListNode*> s, ss;
		while(h != nullptr){
			s.push(h);
			h = h->next;
		}
		while(hh != nullptr){
			ss.push(hh);
			hh = hh->next;
		}
		ListNode* pre = nullptr;
		while(!s.empty() && !ss.empty() && s.top() == ss.top()){
			pre = s.top();
			s.pop();
			ss.pop();
		}
		return pre;
	}
	//* maintain two pointers
	ListNode* sln_3(ListNode* h, ListNode* hh){
		ListNode* t = h, * tt = hh;
		while(true){
			if(t == tt){
				return t;
			}else{
				if(t == nullptr){
					t = hh;
				}else{
					t = t->next;
				}
				if(tt == nullptr){
					tt = h;
				}else{
					tt = tt->next;
				}
			}
		}
		return nullptr;		//* make it compile
	}
};
