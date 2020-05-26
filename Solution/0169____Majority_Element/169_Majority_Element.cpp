#include <vector>
using namespace std;


class Solution {
public:
	int majorityElement(vector<int>& nums) {
		//* todo: what if `nums` is empty
		int num;
		int count = 0;
		for(const auto& elem: nums){
			if(count == 0){
				num = elem;
				count++;
			}else if(elem == num){
				count++;
			}else{
				count--;
			}
		}
		return num;
	}
};