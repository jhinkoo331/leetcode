class Solution {
public:
        vector<vector<int>> pathSum(TreeNode* root, int sum) {
                return _1(root, sum);
        }
private:
        vector<vector<int>> paths;
        vector<int> path;
        int cur_sum;
        int target_sum;
        /**
         * @brief 83, 99
         */
        vector<vector<int>> _1(TreeNode* root, int sum){
                paths.clear();
                path.clear();
                cur_sum = 0;
                target_sum = sum;
                if(root)
                        _11(root);
                return paths;
        }
        void _11(TreeNode* root){       // root should not be null
                path.push_back(root->val);
                cur_sum += root->val;
                if(cur_sum == target_sum && !root->left && !root->right)
                        paths.push_back(path);
                if(root->left)
                        _11(root->left);
                if(root->right)
                        _11(root->right);
                cur_sum -= root->val;
                path.pop_back();
        }
};
