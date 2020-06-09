#include <cmath>
#include <climits>
class Solution {
public:
	// call c std library function.
	int mySqrt_1(int x){
		return (int)pow(x, 0.5);
	}
	// check from 0, 1, 2, 3...to 46340.
	int mySqrt_2(int x){
		if(x >= this->max_root_square)
			return this->max_root;
		int result = 1;
		while(result * result <= x) result++;
		return result - 1;
	}
	// try to enhance mySqrt_2
	int mySqrt_3(int x){
		int root = 1;
		int step = 3;
		unsigned square = 1;
		while(square <= x){
			root++;
			square += step;
			step += 2;
		}
		return root - 1;
	}
	// binary search.
	int mySqrt_4(int x){
		int left = 0, right = x < this->max_root ? x : this->max_root;
		while(left != right - 1 && left != right){
			int mid = (left + right) / 2;
			if(mid * mid > x){
				left = left;
				right = mid - 1;
			}else{
				left = mid;
				right = right;
			}
		}
		if(right * right <= x)
			return right;
		else
			return left;
	}

private:
	int max_root = 46340;
	int max_root_square = 2147395600;
};


int main(){
	float right = pow(INT_MAX, 0.5);
	Solution sln;
	sln.mySqrt_2(4);
	return 0;
}