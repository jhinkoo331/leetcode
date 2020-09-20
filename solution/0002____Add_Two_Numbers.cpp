#include "model\ListNode.h"

class Solution {
public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
                // return addTwoNumbers_1(l1, l2);
                return addTwoNumbers_2(l1, l2);
        }
private:
        //* [94, 37]
        ListNode* _1(ListNode* l, ListNode* ll){
                ListNode ln;
                ListNode* tail = &ln;
                int carry = 0;
                while(l != nullptr | ll != nullptr){
                        if(l != nullptr){
                                carry += l->val;
                                l = l->next;
                        }
                        if(ll != nullptr){
                                carry += ll->val;
                                ll = ll->next;
                        }
                        ListNode* temp = new ListNode(carry % 10);
                        carry /= 10;
                        tail->next = temp;
                        tail = temp;
                }
                if(carry){
                        ListNode* temp = new ListNode(carry);
                        tail->next = temp;
                        tail = temp;
                }
                return ln.next;
        }
        //* [99, 60]
        ListNode* addTwoNumbers_2(ListNode* l, ListNode* ll){
                ListNode ln;
                ListNode* tail = &ln;
                int carry = 0;
                while(l != nullptr | ll != nullptr){
                        if(carry == 0)                  //* in some cases, we may append the remaining part after current list and return.
                                if(l == nullptr){
                                        tail->next = ll;
                                        return ln.next;
                                }else if(ll == nullptr){
                                        tail->next = l;
                                        return ln.next;
                                }
                        ListNode* temp;
                        if(l != nullptr){
                                temp = l;
                                carry += l->val;
                                l = l->next;
                        }
                        if(ll != nullptr){
                                temp = ll;
                                carry += ll->val;
                                ll = ll->next;
                        }
                        temp->val = carry % 10;
                        carry /= 10;
                        tail->next = temp;
                        tail = temp;
                }
                if(carry){
                        ListNode* temp = new ListNode(carry);
                        tail->next = temp;
                        tail = temp;
                }
                return ln.next;
        }
        /**
         * @brief use ListNode from the arguments to reduce memory consumption
         * @perf: 89, 24
         */
        ListNode* _2(ListNode* l, ListNode* ll){
                ListNode head;
                ListNode* tail = &head;
                int carry = 0;
                while(l != nullptr && ll != nullptr){
                        l->val += carry;
                        l->val += ll->val;
                        carry = l->val / 10;
                        l->val %= 10;
                        tail->next = l;
                        tail = tail->next;
                        //* shift l and ll
                        l = l->next;
                        ll = ll->next;
                }
                if(l != nullptr)
                        tail->next = l;
                else
                        tail->next = ll;
                while(tail->next != nullptr && carry){
                        tail = tail->next;
                        tail->val += carry;
                        carry = tail->val / 10;
                        tail->val %= 10;
                }
                if(carry)
                        tail->next = new ListNode(carry);
                return head.next;
        }
};
