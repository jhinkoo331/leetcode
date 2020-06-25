/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        return _1(root);
    }
private:
	/**
	 * @perf: [37, 32]
	 * 
	 * @param root 
	 * @return int 
	 */
    int _1(TreeNode* root){
        queue<TreeNode*> q;
        int max_sum = 0x80000000;
        if(root != NULL)
            q.push(root);
        int cur_level = 0;
        int max_level = 0;
        while(q.size()){
            ++cur_level;
            int k = q.size();
            int cur_sum = 0;
            while(k--){
                cur_sum += q.front()->val;
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
            if(cur_sum > max_sum){
                max_sum = cur_sum;
                max_level = cur_level;
            }
        }
        return max_level;
    }
};