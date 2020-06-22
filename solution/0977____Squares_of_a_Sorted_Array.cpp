#include <vector>
using std::vector;


class Solution {
public:
	vector<int> sortedSquares(vector<int>& A) {
		return _1(A);
	}
private:
	/**
	 * @brief find the index of the first non-negative number in A
	 * @return return A.size() when there is no positive number in A
	 * TODO: binary search
	 */
	int helper_1(vector<int>& A){
		A.push_back(0);
		int i = 0;
		while(A[i] < 0)
			++i;
		A.pop_back();
		return i;
	}
	/**
	 * @perf: [85, 55]
	 * @time: O(n), size of A
	 * @space: O(n), size of A
	 * @return vector<int> 
	 * TODO: use existing space rather than make a new vector
	 */
	vector<int> _1(vector<int>& A){
		int rr = helper_1(A);
		int ll = rr - 1;
		vector<int> v;
		v.reserve(A.size());
		while(ll >= 0 && rr < A.size()){
			if(-A[ll] < A[rr]){
				v.push_back(A[ll] * A[ll]);
				--ll;
			}else{
				v.push_back(A[rr] * A[rr]);
				++rr;
			}
		}
		while(ll >= 0){
			v.push_back(A[ll] * A[ll]);
			--ll;
		}
		while(rr < A.size()){
			v.push_back(A[rr] * A[rr]);
			++rr;
		}
		return v;
	}
};
