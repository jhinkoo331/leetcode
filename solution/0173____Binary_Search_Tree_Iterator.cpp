#include "util\frequently_included.h"
#include "model\TreeNode.h"
#include "util\Serial.h"

/**
 * @brief 
 * @perf: 93, 13
 * @space: height of the binary search tree
 */
class BSTIterator {
public:
        BSTIterator(TreeNode* root) {
                if(root == nullptr){
                        return;
                }
                s.push({root, 0});
                while(s.top().first->left)
                        s.push({s.top().first->left, 0});
        }

        /** @return the next smallest number */
        int next() {
                int ans = s.top().first->val;
                s.top().second = 1;
                if(s.top().first->right != nullptr){
                        s.push({s.top().first->right, 0});
                        while(s.top().first->left != nullptr)
                                s.push({s.top().first->left, 0});
                }
                while(!s.empty() && s.top().second == 1)
                        s.pop();
                return ans;
        }
        
        /** @return whether we have a next smallest number */
        bool hasNext() {
                return !s.empty();
        }
private:
        // int == 0, the val of the node is not visited, int == 1, visited.
        stack<pair<TreeNode*, int>> s;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

