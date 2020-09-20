
class Solution {
public:
        int minSteps(int n){
                return _1(n);
        }

public:
        /**
         * @brief 
         * @perf: 0ms, 74
         */
        int _1(int n) {
                //* At first, there is an 'A' on the notepad, and clipboard is empty
                if(n == 1)
                        return 0;
                int count = 1;          //* copy content in notepad to clipboard
                int i = 2;              //* to find divisor of n
                while(n != 1)
                        for(; i <= n; ++i)
                                if(n % i == 0)
                                        if(n == i){             //* keep pasting till finish
                                                count += n - 1;
                                                n = 1;
                                                break;
                                        }else{                  //* paste, and copy to update clipboard
                                                count += i;
                                                n /= i;
                                                break;
                                        }
                return count;
        }
};


int main(){
        int i;
        Solution sln;
        i = sln.minSteps(4);
        i = sln.minSteps(1);
        i = sln.minSteps(2);
        i = sln.minSteps(3);
        i = sln.minSteps(128);
        return 0;
}