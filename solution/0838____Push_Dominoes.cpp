#include "util\frequently_included.h"

class Solution {
public:
        string pushDominoes(string dominoes) {
                return _1(dominoes);
        }
private:
        /**
         * @perf: 99.59, 69
         */
        string _1(string& dominoes){
                size_t sz = dominoes.size();
                dominoes.push_back('R');                //* sentinel, it should be 'R' and must not be 'L'
                int left = 0, right;
                while(dominoes[left] == '.')
                        ++left;
                if(left == sz){
                        dominoes.pop_back();
                        return dominoes;
                }
                else if(dominoes[left] == 'L')
                        for(int i = 0; i < left; ++i)
                                dominoes[i] = 'L';
                while(left < sz){
                        right = left + 1;
                        while(dominoes[right] == '.')
                                ++right;
                        if(dominoes[left] == 'L' && dominoes[right] == 'L')
                                for(int i = left + 1; i < right; ++i)
                                        dominoes[i] = 'L';
                        else if(dominoes[left] == 'R' && dominoes[right] == 'R')
                                for(int i = left + 1; i < right; ++i)
                                        dominoes[i] = 'R';
                        else if(dominoes[left] == 'R' && dominoes[right] == 'L'){
                                int left_temp = left + 1;
                                int right_temp = right - 1;
                                while(left_temp < right_temp){
                                        dominoes[left_temp++] = 'R';
                                        dominoes[right_temp--] = 'L';
                                }
                        }
                        left = right;
                }
                dominoes.pop_back();
                return dominoes;
        }
};

int main(){
        string s = "R..L";
        Solution sln;
        sln.pushDominoes(".L.R...LR..L..");
        cout << sln.pushDominoes(".") << endl;
        cout << sln.pushDominoes("") << endl;
        return 0;
}