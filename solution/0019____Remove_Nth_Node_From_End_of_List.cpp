#include "model\ListNode.h"
#include "util\frequently_included.h"

class Solution{
public:
        ListNode* removeNthFromEnd(ListNode* head, int n){
                return _1(head, n);
        }
private:
        /**
         * @brief dual pointers
         * @perf: 4ms, 62
         * @time: n
         * @space: constant 
         */
        ListNode* _1(ListNode *head, int n){
                ListNode* left_pre = nullptr;
                ListNode* left = head;
                ListNode* right = head;
                while(n--)                             // shift `right` for `n` times
                        if(right == nullptr)
                                return head;            // the ListNode's length is less than `n`, no node will be removed, just return `head`
                        else
                                right = right->next;    // shift `right`
                if(right == nullptr)                   // the very first node should be removed
                        return head->next;
                while(right != nullptr){                // shift `left` and `right` simultaneously
                        left_pre = left;                // the node at the left-side of `left`
                        left = left->next;
                        right = right->next;
                }
                left_pre->next = left->next;
                delete left;
                return head;
        }

        // solution with stack
        // perf: 4ms, 18
        ListNode* _2(ListNode* head, int n){
                stack<ListNode*> s;
                while(head != nullptr){
                        s.push(head);
                        head = head->next;
                }
                ListNode* tail = nullptr;
                int cnt = 0;
                while(!s.empty()){
                        cnt++;
                        if(cnt != n){
                                s.top()->next = tail;
                                tail = s.top();
                                s.pop();
                        }else{		// when we meet the n-th node, merely delete and pop it out.
                                delete s.top();
                                s.pop();
                        }
                }
                return tail;
        }
};





int main(){
        ListNode* _1 = new ListNode(1);
        ListNode* _2 = new ListNode(2);
        ListNode* _3 = new ListNode(3);
        ListNode* _4 = new ListNode(4);
        ListNode* _5 = new ListNode(5);
        _1->next = _2;
        _2->next = _3;
        _3->next = _4;
        _4->next = _5;
        Solution sln;
        sln.removeNthFromEnd(_1, 2);
        return 0;
}