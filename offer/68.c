#include "model\TreeNode.h"

/**
 * @brief 38, 27, recursive.
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
        while(root){
                if(root->val > p->val && root->val > q->val)
                        root = root->left;
                else if(root->val < p->val && root->val < q->val)
                        root = root->right;
                else
                        break;
        }
        return root;
}