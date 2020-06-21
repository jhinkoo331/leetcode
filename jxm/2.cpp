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
		//* 在处理完两个list后再处理flag != 0的问题
		// if(t1==NULL&&t2==NULL&&flag!=0){
		// 	t3->val=flag;
		// 	t3->next=new ListNode(0);
		// 	t3=t3->next;
		// 	flag=0;
		// }
		while(t1!=NULL){
			// t3->val=t1->val+flag;		//* 这一步操作之后t3->val可能大于等于10
			// t1=t1->next;
			// t3->next=new ListNode(0);
			// t3=t3->next;
			// flag=0;	
			t3->val = t1->val + flag;
			flag = t3->val / 10;
			t3->val %= 10;
			t1 = t1->next;
			t3->next = new ListNode(0);
			t3 = t3->next;
		}while(t2!=NULL){
			// t3->val=t2->val+flag;
			// t2=t1->next;
			// t3->next=new ListNode(0);
			// t3=t3->next;
			// flag=0;	
			// t2=t2->next;
			//* update t3->val and flag
			t3->val = t2->val + flag;
			flag = t3->val / 10;
			t3->val %= 10;
			t2 = t2->next;
			t3->next = new ListNode(0);
			t3 = t3->next;
		}
		//* 两个链表都处理结束后, 处理flag != 0的情况
		if(flag != 0){
			t3->val = flag;
			t3->next = new ListNode(0);
			t3 = t3->next;
		}
		//* t3前面的那个节点的next指针依然是指向原来存储t3的那块内存, 因为t3被移除了, 所以t3->prev->next指针指向了一块未定义的内存
		// delete t3;
		// t3=NULL;
		//* 移除t3需要将t3前面的那个节点的next指针设为nullptr, t3是该链表的最后一个节点, pre保存的是当前节点的前一个节点
		ListNode* pre;
		ListNode* cur = ret;
		while(cur->next != nullptr){
			pre = cur;
			cur = cur->next;
		}
		pre->next = nullptr;
		delete cur;
		return ret;
	}
};

#include "util\Serial.h"

int main(){
	ListNode* l, * ll;
	Serial::de_serialize(l, "5");
	Serial::de_serialize(ll, "5");
	Solution sln;
	sln.addTwoNumbers(l, ll);
	return 0;
}