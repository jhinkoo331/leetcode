#include <vector>
#include <algorithm>
using std::max;
using std::vector;

class Solution {
public:
	int longestMountain(vector<int>& A) {
		return _1(A);
	}
private:
	int _1(vector<int>& A){
		if(A.size() < 3)
			return 0;
		
		vector<int> local_min;
		if(A[0] <= A[1])
			local_min.push_back(0);
		for(int i = 1; i < A.size() - 1; ++i)
			if(A[i - 1] >= A[i] || A[i] <= A[i + 1])
				local_min.push_back(i);
		if(A[A.size() - 2] >= A[A.size() - 1])
			local_min.push_back(A.size() - 1);
		
		int max_len = 0;
		for(int i = 1; i < local_min.size(); ++i)
			max_len = max_len > local_min[i] - local_min[i - 1] ? max_len : local_min[i] - local_min[i - 1];
		++max_len;
		return max_len > 2 ? max_len : 0;
	}
};

int main(){
	vector<int> v1 = {2,1,4,7,3,2,5};
	vector<int> v2 = {0,1,2,3,4,5,4,3,2,1,0};
	vector<int> v3 = {0,1,2,3,4,5,4,3,2,1,0};
	vector<int> v4 = {1,2,2,2};
	Solution sln;
	sln.longestMountain(v4);
	return 0;
}
