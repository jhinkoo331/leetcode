#include "model\ListNode.h"
#include "util\frequently_included.h"

struct cmp{
        bool operator()(ListNode* lhs, ListNode* rhs){
                return lhs->val > rhs->val;
        }
};


class Solution {
public:
        ListNode* mergeKLists(vector<ListNode*>& lists){
                return _1(lists);
        }

public:
        /**
         * @brief priority queue
         * @perf: 50, 25
         * @time: n*log_k
         * @space: k
         */
        ListNode* _1(vector<ListNode*>& lists) {
                ListNode head;
                ListNode* tail = &head;
                priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
                for(const auto& elem: lists)
                        if(elem != nullptr)
                                pq.push(elem);
                while(!pq.empty()){
                        tail->next = pq.top();
                        tail = tail->next;
                        pq.pop();
                        if(tail->next != nullptr)
                                pq.push(tail->next);
                }
                // tail->next = nullptr;
                return head.next;
        }

        /**
         * @brief divide and conquer
         * @perf: 89, 24; seems better than _1; assume that there are k lists with equal length of n
         * @time: n*log_k
         * @space: 1
         */
        ListNode* _2(vector<ListNode*> lists){
                if(lists.empty())
                        return nullptr;
                while(lists.size() > 1){
                        if(lists.size() % 2 == 1)
                                lists.push_back(nullptr);
                        for(int i = 0; i < lists.size(); i += 2)
                                lists[i / 2] = _2_merge_two_lists(lists[i], lists[i + 1]);
                        lists.resize(lists.size() / 2);
                }
                return lists.front();
        }

        ListNode* _2_merge_two_lists(ListNode* l1, ListNode* l2){
                ListNode head;
                ListNode* tail = &head;
                while(l1 != nullptr && l2 != nullptr)
                        if(l1->val < l2->val){
                                tail->next = l1;
                                tail = tail->next;
                                l1 = l1->next;
                        }else{
                                tail->next = l2;
                                tail = tail->next;
                                l2 = l2->next;
                        }
                if(l1 != nullptr)
                        tail->next = l1;
                else
                        tail->next = l2;
                return head.next;
        }
};
