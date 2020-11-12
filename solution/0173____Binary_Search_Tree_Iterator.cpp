#include "util\frequently_included.h"
#include "model\TreeNode.h"
#include "util\Serial.h"

/**
 * @perf: 93, 13
 * @space: two times of the height of the bst
 */
class BSTIterator {
public:
        BSTIterator(TreeNode* root) {
                if(root == nullptr)
                        return;
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
 * @brief this method is elegant than the sln above, which is inspired by sln written by TomKing
 * @perf: 64, 27
 */

class BSTIterator {
public:
        BSTIterator(TreeNode* root) {
                while(s.size())
                        s.pop();
                this->forward(root);
        }
        
        /** @return the next smallest number */
        int next() {
                auto temp = this->s.top();
                s.pop();
                this->forward(temp->right);
                return temp->val;
        }
        
        /** @return whether we have a next smallest number */
        bool hasNext() {
                return !this->s.empty();        
        }
private:
        stack<TreeNode*> s;
        void forward(TreeNode* root){
                while(root){
                        s.push(root);
                        root = root->left;
                }
        }
};

