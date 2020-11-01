#include "model\TreeNode.h"
#include "util\frequently_included.h"

class Solution {
public:
        vector<int> rightSideView(TreeNode* root) {
                _2(root);
                return ans;
        }
private:
        /**
         * @brief level-traverse
         * @perf: 27, 5
         */
        vector<int> _1(TreeNode* root){
                vector<int> v;
                if(root == nullptr)
                        return v;
                queue<TreeNode*> q;
                q.push(nullptr);
                q.push(root);
                bool flag = false;
                while(!q.empty()){
                        if(q.front() == nullptr){
                                flag = true;
                                q.pop();
                        }else{
                                TreeNode* temp = q.front();
                                q.pop();
                                if(flag == true){
                                        q.push(nullptr);
                                        v.push_back(temp->val);
                                }
                                if(temp->right != nullptr)
                                        q.push(temp->right);
                                if(temp->left != nullptr)
                                        q.push(temp->left);
                                flag = false;
                        }
                }
                return v;
        }
        /**
         * @brief dfs with stack
         * @per: 0ms, 5.6
         */
        vector<int> ans;
        void _2(TreeNode* root){
                stack<pair<TreeNode*, int>> s;
                if(root != nullptr)
                        s.push({root, 1});
                while(s.size()){
                        auto temp = s.top();
                        s.pop();
                        if(temp.first->right != nullptr)
                                s.push({temp.first->right, temp.second + 1});
                        if(temp.first->left != nullptr)
                                s.push({temp.first->left, temp.second + 1});
                        if(temp.second > ans.size())
                                ans.push_back(temp.first->val);
                        else
                                ans[temp.second - 1] = temp.first->val;
                }
        }
        /**
         * @brief TODO: dfs with recursion
         * 
         * @param root 
         * @param level 
         */
        void _3(TreeNode* root, int level){
        }
};


