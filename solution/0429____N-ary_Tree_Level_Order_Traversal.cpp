#include ".h"
#include <queue>
using std::queue;

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
        vector<vector<int>> levelOrder(Node* root) {
                _1(root);
                return ans;
        }
private:
        vector<vector<int>> ans;
        /**
         * @brief 82, 17
         * @TODO: space complexity, use recursion to reduce space used
         * @param root 
         */
        void _1(Node* root){
                ans.clear();
                queue<Node*> q;
                if(root != nullptr)
                        q.push(root);
                while(!q.empty()){
                        int k = q.size();
                        vector<int> temp;
                        while(k--){
                                temp.push_back(q.front()->val);
                                for(int i = 0; i < q.front()->children.size(); ++i)
                                        q.push(q.front()->children[i]);
                                q.pop();
                        }
                        ans.push_back(temp);
                }
        }
};
