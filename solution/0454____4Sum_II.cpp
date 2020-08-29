#include <map>
#include <vector>
#include <unordered_map>
using std::unordered_map;
using std::vector;
using std::map;

class Solution {
public:
        int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
                return _2(A, B, C, D);
        }
private:
        /**
         * @brief 11, 5
         */
        int _1(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D){
                map<int, int> m, mm;
                for(auto e: A)
                        for(auto ee: B)
                                ++m[e + ee];
                for(auto e: C)
                        for(auto ee: D)
                                ++mm[e + ee];
                int ans = 0;
                for(auto e: m)
                        ans += mm[-e.first] * e.second;
                return ans;
        }

        /**
         * @brief updated from _1, perf is much better than _1, both run time and space
         * @perf: 59, 29
         */
        int _2(vector<int>& A, vector<int>& B, vector<int>& C, vector<int> D){
                unordered_map<int, int> um;
                for(auto e: A)
                        for(auto ee: B)
                                ++um[e + ee];
                int ans = 0;
                for(auto e: C)
                        for(auto ee: D)
                                ans += um[- e - ee];
                return ans;
        }

        /**
         * @brief compared with _2, we use index-based iterating rather than range-based one.
         * @perf: 63, 37. no improvement observed
         */
        int _3(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D){
                unordered_map<int, int> um;
                int sz = A.size();
                for(int i = 0; i < sz; ++i)
                        for(int ii = 0; ii < sz; ++ii)
                                ++um[A[i] + B[ii]];
                int ans = 0;
                for(int i = 0; i < sz; ++i)
                        for(int ii = 0; ii < sz; ++ii)
                                //TODO: reduce unnecessary um space consumption
                                ans += um[- C[i] - D[ii]];
                return ans;
        }
        //TODO: reduce runtime and space consumption by analysing 4 vector's sizes
};