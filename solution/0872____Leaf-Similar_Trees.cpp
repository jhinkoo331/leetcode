#include "util\frequently_included.h"
#include "model\TreeNode.h"

class Solution {
public:
        bool leafSimilar(TreeNode* root1, TreeNode* root2) {
                return _1(root1, root2);
        }
private:
        /**
         * @brief implement iterating via stack rather than recursion
         * @perf: 4ms, 87
         */
        bool _1(TreeNode* root1, TreeNode* root2){
                stack<TreeNode*> s1, s2;
                if(root1 != nullptr)        
                        s1.push(root1);
                if(root2 != nullptr)
                        s2.push(root2);
                while(s1.size() && s2.size()){
                        _1_get_next_leaf(s1);
                        _1_get_next_leaf(s2);
                        if(s1.top()->val == s2.top()->val){
                                s1.pop();
                                s2.pop();
                        }else
                                return false;
                }
                return s1.empty() && s2.empty();
        }
        /**
         * @brief to make the stack's top element a leaf node
         */
        void _1_get_next_leaf(stack<TreeNode*>& s){
                while(s.top()->left != nullptr || s.top()->right != nullptr){
                        TreeNode* temp = s.top();
                        s.pop();
                        if(temp->right != nullptr)
                                s.push(temp->right);
                        if(temp->left != nullptr)
                                s.push(temp->left);
                }
        }
};
