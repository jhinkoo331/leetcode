#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};


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


int main(){
	ListNode* root = new ListNode(1);
	root->next = new ListNode(2);
	root->next->next = new ListNode(3);
	root->next->next->next = new ListNode(4);
	root->next->next->next->next = new ListNode(5);
	root->next->next->next->next->next = new ListNode(6);
	root->next->next->next->next->next->next = new ListNode(7);
	root->next->next->next->next->next->next->next = new ListNode(8);
	root->next->next->next->next->next->next->next->next = new ListNode(9);
	root->next->next->next->next->next->next->next->next->next = new ListNode(10);
	Solution sln;
	sln.splitListToParts(root, 3);
	return 0;
}
