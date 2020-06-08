#include <vector>
using namespace std;

class Solution {
public:
	int numOfWays(int n) {
		return numOfWays_2(n);
	}
private:
	/**
	 * ! [100, 34]
	 * If we pain the first column as "RYR", the second column has 5 different choice:
	 * YRY, GRY, YRG, GRG, YGY; 3 of which are in format "ABA" and two of which are in format "ABC"
	 * If we pain the first column as "GRY", the second column has 4 different choice:
	 * RYR, RYG, RGR, YGR; two of which are in format "ABA" and the other 2 are in format "ABC"
	 */
	int numOfWays_1(int n){
		if(n <= 0)
			return 0;
		const int m = 1000000000 + 7;
		//* ABA[i] means a grid of length `i`, and the first column is pained in format "ABA" has ABA[i] different ways to pain
		vector<unsigned> ABA(n + 1);
		//* ABC[i] means a grind of length `i`, ..............................in format "ABC" has ABC[i] ......
		vector<unsigned> ABC(n + 1);
		ABA[1] = 6;
		ABC[1] = 6;
		for(int i = 2; i <= n; ++i){
			//* ABA[i] = 3 * ABA[i - 1] + 2 * ABC[i - 1]
			ABA[i] = ((3 * ABA[i - 1]) % m + (2 * ABC[i - 1]) % m) % m;
			//* ABC[i] = 2 * ABA[i - 1] + 2 * ABC[i - 1]
			ABC[i] = ((2 * ABA[i - 1]) % m + (2 * ABC[i - 1]) % m) % m;
		}
		return (ABA[n] + ABC[n]) % m;
	}
	/**
	 * ! [100, 95]
	 * We may reduce vector<unsigned> ABA and ABC to only two unsigned number ABA and ABC to reduce memory used
	 */
	int numOfWays_2(int n){
		if(n <= 0)
			return 0;
		const int m = 1000000000 + 7;
		unsigned ABA = 6, ABC = 6;
		for(int i = 2; i <= n; ++i){
			unsigned temp = ((3 * ABA) % m + (2 * ABC) % m) % m;
			ABC = ((2 * ABA) % m + (2 * ABC) % m) % m;
			ABA = temp;
		}
		return (ABA + ABC) % m;
	}
};

int main(int argc, char const *argv[])
{
	Solution sln;
	int ans;
	ans = sln.numOfWays(2);
	ans = sln.numOfWays(3);
	ans = sln.numOfWays(7);
	ans = sln.numOfWays(5000);
	return 0;
}
