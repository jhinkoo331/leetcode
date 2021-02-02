
int ans = 0;
unsigned mask = 0;

inline bool satisfy() {
        if(!mask)
                return true;
        if(!(mask & (mask - 1)))
                return true;
        return false;
}


// root is guaranteed not null
void helper(struct TreeNode* root) {
        unsigned temp = 1 << root->val;
        mask ^= temp;
        if(root->left)
                helper(root->left);
        if(root->right)
                helper(root->right);
        if(root->left == NULL && root->right == NULL && satisfy()){
                ++ans;
        }
        mask ^= temp;
}

/**
 * @brief 5, 7
 */
int pseudoPalindromicPaths (struct TreeNode* root){
        ans = 0;
        mask = 0;
        if(root == NULL)
                return 0;
        helper(root);
        return ans;
}

