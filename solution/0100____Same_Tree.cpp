#include "model\TreeNode.h"
#include <stack>
using std::stack;

class Solution {
public:
        bool isSameTree(TreeNode* p, TreeNode* q) {
                return _1(p, q);
        }
private:
        /**
         * @brief recursive
         * @perf: 52, 100
         */
        bool _1(TreeNode* p, TreeNode* q){
                if(p == nullptr & q == nullptr)
                        return true;
                if(p == nullptr ^ q == nullptr)
                        return false;
                if(p->val == q->val && _1(p->left, q->left) && _1(p->right, q->right))
                        return true;
                return false;
        }
        /**
         * @brief iterative
         * @perf: 0ms, 100
         */
        bool _2(TreeNode* p, TreeNode* q){
                stack<TreeNode*> ps, qs;
                ps.push(p);
                qs.push(q);
                while(!ps.empty()){
                        p = ps.top();
                        ps.pop();
                        q = qs.top();
                        qs.pop();
                        if(p == nullptr && q == nullptr)
                                continue;
                        if(p == nullptr ^ q == nullptr)
                                return false;
                        if(p->val != q->val)
                                return false;
                        ps.push(p->left);
                        ps.push(p->right);
                        qs.push(q->left);
                        qs.push(q->right);
                }
                return qs.empty();
        }
};
