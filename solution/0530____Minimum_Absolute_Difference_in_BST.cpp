#include "model\TreeNode.h"
#include "util\frequently_included.h"

class Solution {
public:
        int getMinimumDifference(TreeNode* root) {
                min_diff = 0x7fffffff;
                if(root != nullptr)
                        _1(root);
                return min_diff;
        }
private:
        int min_diff;
        /**
         * @brief recursive 
         * @perf: 71, 64
         * @param root 
         * @return pair<int, int> pair<min, max>
         */
        pair<int, int> _1(TreeNode* root){
                pair<int, int> temp, ret {root->val, root->val};
                if(root->left != nullptr){
                        temp = _1(root->left);
                        ret.first = temp.first;
                        if(root->val - temp.second < min_diff)
                                min_diff = root->val - temp.second;
                }
                if(root->right != nullptr){
                        temp = _1(root->right);
                        ret.second = temp.second;
                        if(temp.first - root->val < min_diff)
                                min_diff = temp.first - root->val;
                }
                return ret;
        }
};

