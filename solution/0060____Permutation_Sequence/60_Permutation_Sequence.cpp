#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string getPermutation(int n, int k){
		k--;
		string ret;
		if(n == 0){
			return ret;
		}
		vector<char> nums(n);
		for(int i = 0; i < nums.size(); ++i){
			nums[i] = '0' + i + 1;
		}
		int factorial = 1;
		for(int i = n - 1; i > 0; --i){
			factorial *= i;
		}
		n--;
		while(n){
			int quotient = k / factorial;
			k %= factorial;
			factorial /= n;
			ret += nums[quotient];
			nums.erase(nums.begin() + quotient);
			n--;
		}
		ret += nums.front();
		return ret;
	}
};

int main(){
	Solution sln;
	sln.getPermutation(3, 3);
	sln.getPermutation(4, 9);
	return 0;
}