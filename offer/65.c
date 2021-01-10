#include <stdbool.h>

int _1(int a, int b);

int add(int a, int b){
        return _1(a, b);
}

/**
 * @brief 0ms, 19
 * @todo: simplify bit operation
 * @todo: https://www.jianshu.com/p/7bba031b11e7
 */
int _1(int a, int b){
        unsigned ans = 0;
        bool carry = 0;
        for(unsigned mask = 1; mask; mask <<= 1){
                bool a_bit = mask & a;
                bool b_bit = mask & b;
                bool temp = (a_bit & b_bit & carry) | (a_bit & ~b_bit & ~carry) | (~a_bit & b_bit & ~carry) | (~a_bit & ~b_bit & carry);
                if(temp)
                        ans ^= mask;
                carry = (a_bit & b_bit) | (b_bit & carry) | (carry & a_bit);
        }
        return ans;
}

int main(){
        add(12, 6);
        return 0;
}
