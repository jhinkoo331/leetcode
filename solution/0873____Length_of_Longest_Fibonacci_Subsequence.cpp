#include "util\frequently_included.h"

class Solution {
public:
        int lenLongestFibSubseq(vector<int>& A) {
                return _1(A);
        }
private:
        /**
         * @brief: brute force
         * @perf: 36, 28
         */
        int _1(vector<int>& A){
                unordered_set<int> s;           //! set<int> raises tle err.
                int max_len = 0;
                for(auto e: A)
                        s.insert(e);
                for(int i = 0; i < A.size(); ++i)
                        for(int ii = i + 1; ii < A.size(); ++ii){
                                int cur_len = 2;
                                int t = A[i], tt = A[ii];
                                while(s.find(t + tt) != s.end()){
                                        ++cur_len;
                                        int temp = t + tt;
                                        t = tt;
                                        tt = temp;
                                }
                                max_len = cur_len > max_len ? cur_len : max_len;
                        }
                return max_len > 2 ? max_len : 0;
        }

        /**
         * @brief dynamic programming
         * @perf: 
         */
        int _2(vector<int> A){

        }
};
