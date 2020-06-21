#include "model\ListNode.h"
#ifndef NULL
#define NULL nullptr
#endif


class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* t1=l1;
		ListNode* t2=l2;
		ListNode* ret=new ListNode(0);
		ListNode* t3=ret;
		int flag=0;
		while(t1!=NULL&&t2!=NULL){
			t3->val=(t1->val+t2->val+flag)%10;
			flag=(t1->val+t2->val+flag)/10;
			t3->next=new ListNode(0);
			t3=t3->next;
			t1=t1->next;
			t2=t2->next;
		}
		if(t1==NULL&&t2==NULL&&flag!=0){
			t3->val=flag;
			t3->next=new ListNode(0);
			t3=t3->next;
			flag=0;
		}
		while(t1!=NULL){
			t3->val=t1->val+flag;
			t1=t1->next;
			t3->next=new ListNode(0);
			t3=t3->next;
			flag=0;	
		}while(t2!=NULL){
			t3->val=t2->val+flag;
			t2=t1->next;
			t3->next=new ListNode(0);
			t3=t3->next;
			flag=0;	
			t2=t2->next;
		}
		delete t3;
		t3=NULL;
		return ret;
	}
};
