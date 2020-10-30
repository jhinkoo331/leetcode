#include "model\TreeNode.h"
#include "util\frequently_included.h"
#include "util\Serial.h"

class Solution {
public:
        int kthSmallest(TreeNode* root, int k) {
                return _1(root, k).second;
        }
private:
        /**
         * @brief 
         * @perf: 92, 45
         * @param root 
         * @param k 
         * @return if bool = true, the return value is the k-th smallest number,
         * 		if bool = false, the return value is count of nodes in the sub-tree
         */
        pair<bool, int> _1(TreeNode* root, int k){
                if(root == nullptr)
                        return {false, 0};
                pair<bool, int> left = _1(root->left, k);
                if(left.first)
                        return left;
                if(left.second + 1 == k)
                        return {true, root->val};
                auto right = _1(root->right, k - left.second - 1);
                if(right.first)
                        return right;
                return {false, left.second + 1 + right.second};
        }
};

int main(){
        TreeNode* root;
        Serial::de_serialize(root, "[5,3,6,2,4,null,null,1]"); 
        Solution sln;
        sln.kthSmallest(root, 3);
        return 0;
}
