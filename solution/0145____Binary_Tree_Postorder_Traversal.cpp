#include "model\TreeNode.h"
#include "util\Serial.h"

#include <stack>
#include <vector>
using std::vector;
using std::stack;
using std::pair;

class Solution {
public:
        vector<int> postorderTraversal(TreeNode* root) {
                return _1(root);
        }
private:
        vector<int> ans;
        /**
         * @brief 4ms, 80
         * @TODO: discuss review
         * @param root 
         * @return vector<int> 
         */
        vector<int> _1(TreeNode* root){
                ans.clear();
                //* the second argument `bool` indicates whether the node's child nodes have be visited.
                stack<pair<TreeNode*, bool>> stk;
                if(root != nullptr)
                        stk.push({root, 0});
                while(!stk.empty()){
                        if(stk.top().second == 1){      //* the node's children have be visited already
                                ans.push_back(stk.top().first->val);
                                stk.pop();
                        }else{
                                stk.top().second = 1;
                                TreeNode* temp = stk.top().first;
                                if(temp->right != nullptr)
                                        stk.push({temp->right, 0});
                                if(temp->left != nullptr)
                                        stk.push({temp->left, 0});
                        }
                }
                return ans;
        }
};

int main(){
        TreeNode* root;
        Serial::de_serialize(root, "3,1,2");
        Solution sln;
        sln.postorderTraversal(root);
        return 0;

}