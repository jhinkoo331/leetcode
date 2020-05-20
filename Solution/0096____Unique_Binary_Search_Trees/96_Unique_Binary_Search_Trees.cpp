#include <vector>
using namespace std;

class Solution {
public:
	int numTrees(int n) {		//* when n = 0, return 1 as well.
		vector<int> v(n + 1, 0);
		v[0] = 1;
		for(int i = 1; i <= n; ++i){		//* tree's size is `n`
			for(int ii = 0; ii < i; ++ii){
				v[i] += v[ii] * v[i - 1 - ii];
			}
		}
		return v[n];
	}
};

int main(){
	Solution sln;
	sln.numTrees(20);
	return 0;
}