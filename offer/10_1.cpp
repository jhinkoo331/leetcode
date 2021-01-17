class Solution {
public:
        int fib(int n) {
                return _1(n);
        }
private:
        /**
         * @brief 0ms, 94
         */
        int _1(int n){
                int module = 1e9 + 7;
                int values[2] = {0, 1};
                bool odd = n & 1;
                n /= 2;
                while(n--){
                        values[0] = (values[0] + values[1]) % module;
                        values[1] = (values[0] + values[1]) % module;
                }
                return odd ? values[1] : values[0];
        }
};