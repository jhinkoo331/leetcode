#include "util\frequently_included.h"
#include <ctype.h>

class Solution {
public:
        int calculate(string s) {
                return _1(s);
        }
private:
        int index;
        /**
         * @perf: 73, 6
         * todo: reduce the size of stk, if there are tree consecutive number in the stk, the first two can be added up.
         */
        int _1(string s){
                index = 0;
                stack<int> stk;
                int temp = get_next(s);
                if(temp == 0x80000000)  // the string is empty or all blankspaces
                        return 0;
                else if(temp >= 0)       // the first token is number
                        stk.push(temp);
                else                    // the first token is minus symbol
                        stk.push(-get_next(s));
                while(true){
                        int operate = get_next(s);      // operator
                        if(operate == 0x80000000)
                                break;
                        operate = -operate;
                        int num = get_next(s);
                        if(operate == '+')
                                stk.push(num);
                        else if(operate == '-')
                                stk.push(-num);
                        else if(operate == '*')
                                stk.top() *= num;
                        else if(operate == '/')
                                stk.top() /= num;
                        else{
                                // err
                        }
                }
                int ans = 0;
                while(stk.size()){
                        ans += stk.top();
                        stk.pop();
                }
                return ans;
        }
        /**
         * @brief Get the next object
         * 
         * @param s 
         * @return int  positive if the next is a number
         *              negative if ..            operator   
         *              0x80000000 if ..          reach the end
         */
        int get_next(const string& s){
                while(index < s.size() && ' ' == s[index])
                        ++index;
                if(index == s.size())
                        return 0x80000000;
                else if(!isdigit(s[index])){
                        ++index;
                        return -s[index - 1];
                }else{
                        int ans = 0;
                        while(index < s.size() && isdigit(s[index])){
                                ans *= 10;
                                ans += s[index] - '0';
                                ++index;
                        }
                        return ans;
                }
        }
};
