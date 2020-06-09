#include <climits>
#include <stdlib.h>
#include <iostream>
using namespace std;
class Solution {
public:
    double myPow(double x, int n){
		// record the property of n, then change n to its absolute value
		bool is_min = n == INT_MIN;
		bool is_neg = n < 0;
		if(is_min)
			n++;
		n = abs(n);
		// set up the table
		double data[31];
		data[0] = x;
		for(int i = 1; i < 31; i++)
			data[i] = data[i - 1] * data[i - 1];
		// get the result of n			//! this is not the final result
		double ret = 1;
		unsigned temp = 1;				//! if we use integer rather than unsigned int, it would render a error.
		for(int i = 0; i < 31; i++){
			int t = n & temp;
			cout << i << ' ' << temp << ' ' << (n & temp) << endl;
			if(n & temp)
				ret *= data[i];
			temp *= 2;
		}
		if(is_min)
			ret *= x;			// ! we let n plus 1 before
		if(is_neg)				//! if the exponent is negative
			ret = 1 / ret;
		cout << "The result is: " << ret << endl;
		return ret;
    }
};


int main(){
	Solution sln;
	sln.myPow(3, 13);
	sln.myPow(2, -2);
	return 0;
}