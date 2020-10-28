#define NULL 0
#include "util\frequently_included.h"

class Node {
public:
        int val;
        Node* left;
        Node* right;
        Node* next;

        Node() : val(0), left(NULL), right(NULL), next(NULL) {}

        Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

        Node(int _val, Node* _left, Node* _right, Node* _next)
                : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
        Node* connect(Node* root) {
                return _1(root);
        }
private:
        /**
         * @brief level-traverse
         * @time: n
         * @space: width of the tree
         * @perf: 93, 78
         */
        Node* _1(Node* root){
                auto ans = root;
                queue<Node*> q;
                if(root != nullptr)
                        q.push(root);
                while(q.size()){
                        int sz = q.size();
                        while(--sz){
                                auto temp = q.front();
                                if(temp->left)
                                        q.push(temp->left);
                                if(temp->right)
                                        q.push(temp->right);
                                q.pop();
                                temp->next = q.front();
                        }
                        if(q.front()->left)
                                q.push(q.front()->left);
                        if(q.front()->right)
                                q.push(q.front()->right);
                        q.front()->next = nullptr;
                        q.pop();
                }
                return ans;
        }
        /**
         * @brief 
         * todo: recursive approach
         * @param root 
         * @return Node* 
         */
        Node* _2(Node* root){

        }
};
