#include "model\TreeNode.h"
#include "util\frequently_included.h"

class Solution {
public:
        TreeNode* deleteNode(TreeNode* root, int key) {
                return _1(root, key);
        }
private:
        /**
         * @perf: 91, 42
         */
        TreeNode* _1(TreeNode* root, int key){
                auto to_delete = searchByKey(root, key);
                if(!to_delete.first)    // the key doesn't exists, just return
                        return root;
                while(true){
                        auto next = next_to_delete(to_delete.first);
                        if(!next.first)
                                break;
                        to_delete.first->val = next.first->val;
                        to_delete = next;
                }
                if(!to_delete.second)   // the root is leaf node and to be deleted, so return a empty tree
                        return nullptr;
                else if(to_delete.second->left == to_delete.first)
                        to_delete.second->left = nullptr;
                else
                        to_delete.second->right = nullptr;
                return root;
        }
        /**
         * @time: log(n)
         * @return TreeNode* return non-nullptr if key exists else nullptr
         */
        pair<TreeNode*, TreeNode*> searchByKey(TreeNode* root, int key){
                pair<TreeNode*, TreeNode*> ans = {root, nullptr};
                while(ans.first && ans.first->val != key){
                        ans.second = ans.first;
                        if(ans.first->val < key)
                                ans.first = ans.first->right;
                        else
                                ans.first = ans.first->left;
                }
                return ans;
        }
        pair<TreeNode*, TreeNode*> next_to_delete(TreeNode* to_delete){
                pair<TreeNode*, TreeNode*> ans = {nullptr, nullptr};
                if(to_delete->left){
                        ans = {to_delete->left, to_delete};
                        while(ans.first->right){
                                ans.second = ans.first;
                                ans.first = ans.first->right;
                        }
                }else if(to_delete->right){
                        ans = {to_delete->right, to_delete};
                        while(ans.first->left){
                                ans.second = ans.first;
                                ans.first = ans.first->left;
                        }
                }
                return ans;
        }
};