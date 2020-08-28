#include <cstdint>

//TODO: solution

class Solution {
public:
        uint32_t reverseBits(uint32_t n) {
                return _1(n);
        }

private:
        /**
         * @brief 4ms, 63
         */
        uint32_t _1(uint32_t n){
                uint32_t temp = 0;
                uint32_t n_mask = 0x80000000;
                uint32_t temp_mask = 0x1;
                for(int i = 0; i < 32; ++i){
                        if(n & n_mask)
                                temp |= temp_mask;
                        n_mask >>= 1;
                        temp_mask <<= 1;
                }
                return temp;
        }
};

