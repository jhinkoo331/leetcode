#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
        vector<string> generateParenthesis(int n) {
                return _1(n);
        }
private:
        /**
         * @perf: 4ms, 5
         */
        vector<string> _1(int n){
                if(n == 0)
                        return vector<string>{};                //! critical
                string result;
                result.reserve(2 * n);
                vector<string> results(this->_1_cal(n));
                _1_helper(n, 0, result, results);
                return results;
        }
        /**
         * @param n             how many left parenthisis remain to be placed
         * @param count         how many left parenthisis remain unpaired in result
         */
        void _1_helper(int n, int count, string& result, vector<string>& results){
                if(n == 0){		//* a result is found here
                        results.push_back(result);
                        for(int i = 0; i < count; ++i)
                                results.back().push_back(')');
                }else{
                        if(count != 0){
                                result.push_back(')');
                                _1_helper(n, count - 1, result, results);
                                result.pop_back();
                        }
                        result.push_back('(');
                        _1_helper(n - 1, count + 1, result, results);
                        result.pop_back();
                }
        }
        int _1_cal(int n){
                int ans = 1;
                while(n--)
                        ans *= n;
                return ans;
        }
};


int main(){
        Solution sln;
        sln.generateParenthesis(0);
        sln.generateParenthesis(1);
        sln.generateParenthesis(2);
        sln.generateParenthesis(3);
        sln.generateParenthesis(4);
        return 0;
}

