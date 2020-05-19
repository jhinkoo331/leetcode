#include <vector>
using namespace std;

enum vowel {a, e, i, o, u, x};

class Solution {
public:
	int countVowelPermutation(int n) {
		if(n <= 0){
			return 0;
		}
		vector<vector<unsigned>> v(5);
		for(int ii = 0; ii < 5; ++ii){
			v[ii].resize(n);
			v[ii][0] = 1;
		}
		for(int ii = 1; ii < n; ++ii){
			int iii = ii - 1;
			v[a][ii] = v[e][iii];
			v[e][ii] = (v[a][iii] + v[i][iii]) % divisor;
			v[i][ii] = (v[a][iii] + v[e][iii] + v[o][iii] + v[u][iii]) % divisor;
			v[o][ii] = (v[i][iii] + v[u][iii]) % divisor;
			v[u][ii] = v[a][iii];
		}
		int sum = 0;
		for(int i = 0; i < 5; ++i){
			sum += v[i].back();
			sum %= divisor;
		}
		return sum;
	}
private:
	const int divisor = 1000000000 + 7;
};

int main(){
	Solution sln;
	int ret = -1;
	ret = sln.countVowelPermutation(-1);
	ret = sln.countVowelPermutation(0);
	ret = sln.countVowelPermutation(1);
	ret = sln.countVowelPermutation(5);
	ret = sln.countVowelPermutation(144);
	ret = sln.countVowelPermutation(0x80000000);
	ret = sln.countVowelPermutation(0x7fffffff);
	return 0;
}