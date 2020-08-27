#include <vector>
#include <stack>
using std::stack;
using std::vector;


class Node {
public:
        int val;
        vector<Node*> children;

        Node() {}

        Node(int _val) {
                val = _val;
        }

        Node(int _val, vector<Node*> _children) {
                val = _val;
                children = _children;
        }
};

class Solution {
public:
        vector<int> postorder(Node* root) {
                _1(root);
                return ans;
        }
private:
        vector<int> ans;
        /**
         * @brief 92, 67
         * 
         * @param root 
         */
        void _1(Node* root){
                ans.clear();
                stack<std::pair<Node*, bool>> stk;
                if(root != nullptr)
                        stk.push({root, 0});
                while(!stk.empty()){
                        if(stk.top().second == 1){
                                ans.push_back(stk.top().first->val);
                                stk.pop();
                        }else{
                                Node* temp = stk.top().first;
                                stk.top().second = 1;
                                for(auto itr = temp->children.rbegin(); itr != temp->children.rend(); ++itr){
                                        stk.push({*itr, 0});
                                }
                        }
                }
        }
};
