#include <queue>
#include <vector>
using std::priority_queue;

class Solution {
public:
	int nthUglyNumber(int n) {
		return nthUglyNumber_1(n);
	}
private:
	const int a = 0x7fffffff / 2;
	const int b = 0x7fffffff / 3;
	const int c = 0x7fffffff / 5;
	/*
	 * perf: [12, 51]
	 * time:
	 * space:
	 */
	int nthUglyNumber_1(int n){
		int cur = 1;
		priority_queue<int, std::vector<int>, std::greater<int>> pq;
		pq.push(2);
		pq.push(3);
		pq.push(5);
		while(--n){
			while(pq.top() <= cur)
				pq.pop();
			cur = pq.top();
			pq.pop();
			if(cur < c){
				pq.push(cur * 5);
				pq.push(cur * 3);
				pq.push(cur * 2);
			}else if(cur < b){
				pq.push(cur * 3);
				pq.push(cur * 2);
			}else if(cur < a){
				pq.push(cur * 2);
			}
		}
		return cur;
	}
};

int main(){
	Solution sln;
	sln.nthUglyNumber(16);
	return 0;
}
