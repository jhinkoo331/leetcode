#include <map>
#include <vector>
#include <set>
#include "model\ListNode.h"
#include "util\Serial.h"

using namespace std;

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
};

int main(){
	ListNode* head;
	Serial::de_serialize(head, "[1,3,2,-3,-2,5,5,-5,1]");
	Serial::de_serialize(head, "1 2 -3 3 1");
	Solution sln;
	sln.removeZeroSumSublists(head);
	return 0;
}

