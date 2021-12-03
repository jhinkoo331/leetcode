#include "model\ListNode.h"
#include "util\frequently_included.h"

class Solution {
public:
        int numComponents(ListNode* head, vector<int>& G) {
                return _1(head, G);
        }
private:
        /**
         * @perf: 91, 9
         */
        int _1(ListNode* head, vector<int>& G){
                unordered_set<int> us;
                for(int e: G)
                        us.insert(e);
                int ans = 0;
                while(head != nullptr && us.find(head->val) == us.end())
                        head = head->next;
                while(head != nullptr){
                        ++ans;
                        while(head != nullptr && us.find(head->val) != us.end())
                                head = head->next;
                        while(head != nullptr && us.find(head->val) == us.end())
                                head = head->next;
                }
                return ans;
        }
};