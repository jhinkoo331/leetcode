#include <vector>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int left = 0, right = numbers.size() - 1;
		while(true){
			while(numbers[left] + numbers[right] > target)
				right--;
			if(numbers[left] + numbers[right] == target)
				return vector<int> {left + 1, right + 1};
			while(numbers[left] + numbers[right] < target)
				left++;
			if(numbers[left] + numbers[right] == target)
				return vector<int> {left + 1, right + 1};
		}
		return vector<int> {};
	}
};


int main(){
	vector<int> v1 = {2, 7, 11, 15};
	Solution sln;
	sln.twoSum(v1, 9);
	return 0;
}