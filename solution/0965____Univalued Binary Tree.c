
int val;

bool helper(struct TreeNode* root){
        if(root->val != val)
                return false;
        if(root->left && !helper(root->left))
                return false;
        if(root->right && !helper(root->right))
                return false;
        return true;
}

/**
 * @brief 0ms, 100
 */
bool isUnivalTree(struct TreeNode* root){
        if(root == NULL)
                return true;
        val = root->val;
        if(root->left && !helper(root->left))
                return false;
        if(root->right && !helper(root->right))
                return false;
        return true;
}