
#include <vector>
#include <unordered_map>
#include <tuple>
#include <iostream>
using namespace std;

unordered_map<int, vector<int>> mp;

void debug() {
	for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
		for (auto itrr = mp)
	}
}


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		//* set up the map
		for (int i = 0; i < nums.size(); ++i)
			mp[nums[i] % target].push_back(i);
		int index, index2;
		for (index = 0; index < nums.size(); ++index) {
			auto temp = mp[(target - nums[index]) % target];
			for (auto itr = temp.begin(); itr != temp.end(); ++itr)
				if (nums[*itr] + nums[index] == target && *itr != index) {
					index2 = *itr;
					break;
				}
		}
		// debug
		for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
			cout << itr->first << ": ";
			for (auto itrr = itr->second.begin(); itrr != itr->second.end(); ++itrr)
				cout << *itrr << ' ';
			cout << endl;
		}
			// debug
			vector<int> ret = {index, index2};
		return ret;
	}
};

int main() {
	vector<int> arg1 = {2, 7, 11, 5};
	int target = 9;
	Solution sln;
	sln.twoSum(arg1, target);
	return 0;
}


