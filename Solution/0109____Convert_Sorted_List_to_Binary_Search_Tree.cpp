#include "model\TreeNode.h"
#include "model\ListNode.h"
#include <vector>
using namespace std;


class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		// return sortedListToBST_1(head, nullptr);
		return sortedListToBST_2(head);
	}
private:
	/**
	 * *this function would not change the original ListNode which starts from `head`
	 * ![90, 91]
	 * ! the greatness of this function is that: Firstly: we won't change the original linked-list.
	 * ! Secondly, there is no need to maintain a ptr which pointing to the previous node of `slow` pointer
	 * @param head the head node of the Link-list, head is valid
	 * @param tail the last node of the linked-list, tail is not valid and it might be nullptr
	 */
	TreeNode* sortedListToBST_1(ListNode* head, ListNode* tail){
		if(head == tail)		//* no valid node!
			return nullptr;
		//* to find the mid node in the ListNode, `slow` is the mid node after while loop ends.
		ListNode* slow = head, * fast = head;
		while(fast->next != tail && fast->next->next != tail){
			fast = fast->next->next;
			slow = slow->next;
		}
		//* left part: [head, slow); right part: [slow->next, tail)
		TreeNode* root = new TreeNode(slow->val);
		root->left = sortedListToBST_1(head, slow);
		root->right = sortedListToBST_1(slow->next, tail);
		return root;
	}


	/**
	 * *convert the linked list to array firstly to allow random access of `mid` element.
	 * *[90, 36]
	 * @param head the head node of the linked-list
	 */
	TreeNode* sortedListToBST_2(ListNode* head){
		vector<int> v;
		while(head != nullptr){
			v.push_back(head->val);
			head = head->next;
		}
		if(v.empty())
			return nullptr;
		else
			return sortedListToBST_2_sup(v, 0, v.size());
	}
	/**
	 * ! valid in range [ll, rr), same with solution 1
	 * * [90, 36]
	 * @param v the array list casted from the original linked-list
	 * @param ll the left index of the array
	 * @param rr the right index of the array
	 */
	TreeNode* sortedListToBST_2_sup(const vector<int>& v, int ll, int rr){
		int mm = (rr - ll) / 2 + ll;		//* to avoid overflow
		TreeNode* root = new TreeNode(v[mm]);
		if(ll < mm)
			root->left = sortedListToBST_2_sup(v, ll, mm);
		if(mm + 1 < rr)
			root->right = sortedListToBST_2_sup(v, mm + 1, rr);
		return root;
	}
	//todo: Solution: Approach 3: Inorder Simulation
};
