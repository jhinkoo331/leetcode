

#define NULL 0

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		return solution1(headA, headB);
	}
private:
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
};
