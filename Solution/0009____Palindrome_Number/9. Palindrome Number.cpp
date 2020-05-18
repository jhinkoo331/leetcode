#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
			return false;
		int xx = x;
		int len = 0;
		while(xx != 0){
			len++;
			xx /= 10;
		}
		bool odd = len % 2;
		xx = len / 2;
		stack<int> s;
		while(xx--){
			s.push(x % 10);
			x /= 10;
		}
		if(odd)
			x /= 10;
		while(!s.empty()){
			if(s.top() == x % 10){
				s.pop();
				x /= 10;
			}else
			{
				return 0;
			}
			
		}
		return 1;
    }
};

int main(){
	Solution sln;
	while(true){
		int i;
		cin >> i;
		sln.isPalindrome(i);
	}
	return 0;
}