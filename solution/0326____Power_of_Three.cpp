
int table_len = 21;
int table[21] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 4782969, 14348907, 43046721, 129140163, 387420489, 1162261467, 0x7fffffff};

class Solution {
public:
        bool isPowerOfThree(int n) {
                return isPowerOfThree_1(n);
        }
private:
        bool isPowerOfThree_1(int n){
                if(n <= 0)
                        return false;
                while(n % 3 == 0)
                        n /= 3;
                return n == 1;
        }
        //* perf: [55, 100]
        bool isPowerOfThree_2(int n){
                if(n <= 0)
                        return false;
                int power_3_10 = 59049;
                while(n % power_3_10 == 0)
                        n /= power_3_10;
                while(n % 3 == 0)
                        n /= 3;
                return n == 1;
        }

        //* list all possible answer and check them one by one
        //* perf: [74, 100]
        //! note that, the max number of 32 bit int is 0x7fffffff, which is not a power of 3
        bool isPowerOfThree_3(int n){
                if(n != 0x7fffffff)
                        for(int i = 0; ; ++i)
                                if(n == table[i])
                                        return true;
                                else if(n < table[i])
                                        return false;		//* this line fields better perf, from [74, 100] -> [89, 100]
                return false;
        }
        //* perf[74, 100]
        bool isPowerOfThree_4(int n){
                if(n < 1)
                        return false;
                return 1162261467 % n == 0;
        }
};


int main(){
        int i = 0x80000000 % 3;		//* i = 2, which indicates that 0x80000000 is not power of 3
        i = 0x7fffffff % 3;
        bool check_table = true;
        for(int i = 1; i < 18; ++i){
                if(table[i] != table[i - 1] * 3){
                        check_table = false;
                }
        }
        return 0;
}


