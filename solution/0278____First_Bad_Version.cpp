// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		return _1(n);
	}
private:
	/**
	 * @brief binary search
	 * @perf: [4ms, 96]
	 */
	int _1(int n){
		int left = 1, right = n;
		while(left < right){
			int mid = left + (right - left) / 2;
			if(isBadVersion(mid))
				right = mid;
			else
				left = mid + 1;
		}
		return left;
	}
};
