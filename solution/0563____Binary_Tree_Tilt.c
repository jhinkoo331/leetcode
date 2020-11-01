#include "model\TreeNode.h"

inline int abs(int i){
        return i < 0 ? -i : i;
}

int ans;

/**
 * @perf: 97, 100
 */
int helper(struct TreeNode* root){
        if(root == 0)
                return 0;
        int left = helper(root->left);
        int right = helper(root->right);
        ans += abs(left - right);
        return  left + right + root->val;
}

int findTilt(struct TreeNode* root){
        ans = 0;
        helper(root);
        return ans;
}
