#include <vector>
using namespace std;

class Solution {
public:
        int climbStairs(int n){

        }
public:
        /**
         * @perf: 0ms, 8
         * @time: n
         * @space: n
         */
        int _1(int n) {
                if(n == 0)              //* special condition
                        return 1;
                vector<int> v(n + 1);
                v[0] = 1;
                v[1] = 1;
                for(int i = 2; i <= n; ++i)
                        v[i] = v[i - 1] + v[i - 2];
                return v[n];
        }

        /**
         * @perf: 0ms, 57 
         * @time: n
         * @space: 1
         */
        int _2(int n){
                int i = 1, ii = 1;
                bool n_is_odd = n & 1;
                n /= 2;
                while(n--){
                        i += ii;
                        ii += i;
                }
                return n_is_odd ? ii : i;
        }
};


int main(){
        Solution sln;
        sln.climbStairs(6);
        return 0;
}