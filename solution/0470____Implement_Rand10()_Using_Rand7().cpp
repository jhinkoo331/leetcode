// The rand7() API is already defined for you.
int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
        int rand10() {
                return _1();
        }
private:
        /**
         * @perf: 85, 75
         */
        int _1(){
                int ans = 0;
                while(true){
                        int i = rand7();
                        if(i == 7)
                                continue;
                        else{
                                ans += i & 1 ? 5 : 0;
                                break;
                        }
                }
                while(true){
                        int i = rand7();
                        if(i <= 5)
                                return ans + i;
                }
                return -1;      // err
        }
};
