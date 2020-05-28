#include <vector>
#include <algorithm>
using namespace std;



class Solution {
public:
	int hIndex(vector<int>& citations) {
		return hIndex_1(citations);
	}
private:
	int hIndex_1(vector<int>& citations){
		sort(citations.begin(), citations.end(), greater<int>());
		for(int i = 0; i < citations.size(); ++i){
			if(citations[i] < i + 1){
				return i;
			}
		}
		return citations.size();
	}
};
