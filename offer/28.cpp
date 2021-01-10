/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include "util\frequently_included.h"
#include "model\TreeNode.h"
class Solution {
public:
        bool isSymmetric(TreeNode* root) {
                return _1(root);
        }
private:
        /**
         * @brief iterative
         * @perf: 31, 6
         * @time: n
         * @space: deep of the tree
         */
        bool _1(TreeNode* root){
                if(root == nullptr)
                        return true;
                stack<TreeNode*> s, ss;
                s.push(root);
                ss.push(root);
                while(s.size() && ss.size()){
                        auto t = s.top();
                        auto tt = ss.top();
                        s.pop();
                        ss.pop();
                        if(t->val != tt->val)
                                return false;
                        if(t->left == nullptr ^ tt->right == nullptr)
                                return false;
                        if(t->right == nullptr ^ tt->left == nullptr)
                                return false;
                        if(t->left != nullptr){
                                s.push(t->left);
                                ss.push(tt->right);
                        }
                        if(t->right != nullptr){
                                s.push(t->right);
                                ss.push(tt->left);
                        }
                }
                return s.empty() & ss.empty();
        }
};
