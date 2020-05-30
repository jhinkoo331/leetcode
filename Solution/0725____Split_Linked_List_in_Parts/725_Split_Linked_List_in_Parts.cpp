#include <vector>
#include ".\..\..\model\ListNode.cpp"
using namespace std;

class Solution {
public:
	vector<ListNode*> splitListToParts(ListNode* root, int k) {
		return splitListToParts_1(root, k);
	}

private:
	vector<ListNode*> splitListToParts_1(ListNode* root, int k){
		vector<ListNode*> ret(k, nullptr);
		int total_len = 0;
		ListNode* temp = root;
		while(temp != nullptr){
			total_len++;
			temp = temp->next;
		}
		int right_len = total_len / k;
		int left_count = total_len - right_len * k;
		for(int i = 0; i < left_count; ++i){
			ret[i] = root;
			for(int ii = 0; ii < right_len; ++ii){
				root = root->next;
			}
			temp = root;
			root = root->next;
			temp->next = nullptr;
		}
		if(right_len != 0){
			for(int i = left_count; i < k; ++i){
				// cout << i << endl;
				ret[i] = root;
				for(int ii = 1; ii < right_len; ++ii){
					root = root->next;
				}
				temp = root;
				root = root->next;
				temp->next = nullptr;
			}
		}
		return ret;
	}
};
