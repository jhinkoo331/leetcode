#ifndef SERIAL_H
#define SERIAL_H 

#include <string>
#include <sstream>
#include "model\ListNode.h"


class Serial{
public:
	static int k;
	static void de_serialize(ListNode*& head, std::string s);
};



void Serial::de_serialize(ListNode*& head, std::string s){
	for(int i = 0; i < s.size(); ++i){
		if(!isdigit(s[i])){
			s[i] = ' ';
		}
	}
	std::stringstream ss;
	ss << s;
	int val;
	head = new ListNode();
	ListNode* tail = head;
	while(ss >> val){
		tail->next = new ListNode(val);
		tail = tail->next;
	}
	ListNode* temp = head->next;
	delete head;
	head = temp;
}


#endif
