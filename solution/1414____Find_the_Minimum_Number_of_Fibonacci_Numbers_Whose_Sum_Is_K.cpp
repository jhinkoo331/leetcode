#include <vector>


//TODO: discuss

class Solution {
public:
        int findMinFibonacciNumbers(int k) {
                return _1(k);
        }
private:
        static std::vector<int> fib;
        /**
         * @brief 4ms, 82
         */
        int _1(int k){
                while(fib.back() < k)
                        fib.push_back(fib.back() + fib[fib.size() - 2]);
                int ans = 0;
                int index = fib.size() - 1;
                while(k != 0){
                        while(fib[index] > k)
                                --index;
                        k -= fib[index];
                        ++ans;
                        --index;
                }
                return ans;
        }
};

std::vector<int> Solution::fib = {1, 1};

int main(){
        Solution sln;
        sln.findMinFibonacciNumbers(7);
        sln.findMinFibonacciNumbers(10);
        sln.findMinFibonacciNumbers(19);
        return 0;
}