#include "model\ListNode.h"
#include "util\Serial.h"


class Solution {
public:
        ListNode* deleteDuplicates(ListNode* head){
                return _1(head);
        }
private:
        //* perf: [83, 5]
        ListNode* _1(ListNode* head){
                if(head == nullptr)
                        return nullptr;
                ListNode* tail = head;
                while(tail->next != nullptr)
                        if(tail->val == tail->next->val){
                                ListNode* temp = tail->next;
                                tail->next = temp->next;
                                delete temp;
                        }else
                                tail = tail->next;
                return head;
        }
};

int main(){
        ListNode* head = nullptr;
        Serial::de_serialize(head, "[1,2,3,3,4,4,5]");
        Solution sln;
        head = sln.deleteDuplicates(head);
        return 0;
}


