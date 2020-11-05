#include "util\frequently_included.h"
#include "model\ListNode.h"
#include "util\Serial.h"

class Solution {
public:
        ListNode* removeZeroSumSublists(ListNode* head) {
                return removeZeroSumSublists_1(head);
        }
private:
        ListNode* removeZeroSumSublists_1(ListNode* head){
                vector<ListNode*> v;
                set<int> s;
                int sum = 0;
                while(head != nullptr){
                        ListNode* next = head->next;
                        sum += head->val;
                        if(sum == 0){		//* delete all previous nodes
                                delete head;
                                for(int i = 0; i < v.size(); ++i){
                                        delete v[i];
                                }
                                v.clear();
                                s.clear();
                        }else if(s.find(sum) != s.end()){	//* remove sub array
                                int temp = sum;
                                sum -= head->val;
                                delete head;
                                while(sum != temp){
                                        s.erase(sum);
                                        sum -= v.back()->val;
                                        delete v.back();
                                        v.pop_back();
                                }
                        }else{
                                v.push_back(head);
                                s.insert(sum);
                        }
                        head = next;
                }
                if(v.empty()){
                        return nullptr;
                }else{
                        for(int i = 1; i < v.size(); ++i){
                                v[i - 1]->next = v[i];
                        }
                        return v.front();
                }
        }
        /**
         * @perf: 57, 6
         * @time: O(n)
         * @space: O(n)
         */
        ListNode* _1(ListNode* head){
                ListNode dummy(0);
                dummy.next = head;
                head = &dummy;
                int sum = 0;
                ListNode* cur = head;
                unordered_map<int, ListNode*> um;
                while(cur != nullptr){
                        sum += cur->val;
                        auto temp = um.find(sum);
                        if(temp == um.end())
                                um.insert({sum, cur});
                        else{
                                int temp_sum = sum;
                                auto to_remove = temp->second->next;
                                temp->second->next = cur->next;
                                while(to_remove != cur){
                                        temp_sum += to_remove->val;
                                        um.erase(um.find(temp_sum));
                                        to_remove = to_remove->next;
                                }
                        }
                        cur = cur->next;
                }
                return dummy.next;
        }
};

int main(){
        ListNode* head;
        Serial::de_serialize(head, "[1,3,2,-3,-2,5,5,-5,1]");
        Serial::de_serialize(head, "1 2 -3 3 1");
        Solution sln;
        sln.removeZeroSumSublists(head);
        return 0;
}

