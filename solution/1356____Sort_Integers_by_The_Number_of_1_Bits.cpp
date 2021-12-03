
#include "util\frequently_included.h"

int bit_count(int i){
        int ans = 0;
        for(unsigned mask = 1; mask; mask <<= 1)
                if(mask & i)
                        ++ans;
        return ans;
}

bool cmp(const int& i, const int& ii){
        int diff = bit_count(i) - bit_count(ii);
        if(diff < 0)
                return true;
        if(diff > 0)
                return false;
        return i < ii;
}

class Solution {
public:
        vector<int> sortByBits(vector<int>& arr) {
                _1(arr);
                return arr;
        }
private:
        void _1(vector<int>& arr){
                sort(arr.begin(), arr.end(), cmp);
        }
};

int main(){
        vector<int> arr = {0,1,2,3,4,5,6,7,8};
        Solution sln;
        sln.sortByBits(arr);
        return 0;
}

