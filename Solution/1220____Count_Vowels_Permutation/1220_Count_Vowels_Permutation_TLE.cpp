//! this method renders Time Limit Exceed error once `n` reaches 144



#include <vector>
using namespace std;

enum vowel {a, e, i, o, u, x};

class Solution {
public:
	int countVowelPermutation(int n) {
		if(n <= 0){
			return 0;		//! important, see Solution::get_result::if(n == 0) count++;
		}
		this->count = 0;
		this->get_result(n, x);
		return this->count;
	}

private:
	//* a, e, i, o, u, x is represented by 0, 1, 2, 3, 4, 5
	vector<vector<int>> v = {
		{e},
		{a, i},
		{a, e, o, u},
		{i, u},
		{a},
		{a, e, i, o, u}
	};
	int count;
	void get_result(int n, int last){
		if(n == 0){
			count++;
		}else{
			for(const auto elem: v[last]){
				get_result(n - 1, elem);
			}
		}
	}
};

int main(){
	Solution sln;
	int ret = -1;
	for(int i = 0; i < 10; ++i){
		ret = sln.countVowelPermutation(i);
	}
	return 0;
}