#include <vector>
#include <map>
#include <algorithm>
using std::vector;


class Solution {
public:
	int numRescueBoats(vector<int>& people, int limit) {
		return _2(people, limit);
	}
private:
	/**
	 * @brief 
	 * @perf: [23, 5]
	 * @time: O(limit)
	 * @space: O(limit)
	 * @param people 
	 * @param limit 
	 * @return int 
	 */
	int _1(vector<int>& people, int limit){
		std::map<int, int> m;
		for(int i = 0; i < people.size(); ++i)
			m[people[i]]++;
		int boat = m[limit];
		m.erase(limit);
		while(!m.empty()){
			int target = limit - m.begin()->first;
			int people_count = m.begin()->second;
			m.erase(m.begin());
			while(!m.empty()){
				if(m.rbegin()->first > target){
					boat += m.rbegin()->second;
					m.erase(m.rbegin()->first);
				}else if(people_count == 0){
					break;
				}else if(m.rbegin()->second <= people_count){
					boat += m.rbegin()->second;
					people_count -= m.rbegin()->second;
					m.erase(m.rbegin()->first);
				}else if(people_count != 0){
					boat += people_count;
					m.rbegin()->second -= people_count;
					people_count = 0;
				}
			}
			if(people_count != 0){
				//* target = limit - weight
				//* limit < 2 * weight
				if(target < (limit + 1) / 2)
					boat += people_count;
				else	//* limit >= 2 * weight
					boat += (people_count + 1) / 2;
			}
		}
		return boat;
	}
	/**
	 * @perf: [35, 19]
	 * @time: O(nlog(n)), to sort `people`
	 * @space: constant
	 */
	int _2(vector<int>& people, int limit){
		std::sort(people.begin(), people.end());
		int ll = 0, rr = people.size() - 1;
		int boat = 0;
		while(ll <= rr){
			boat++;
			if(people[ll] + people[rr] <= limit)
				ll++;
			rr--;
		}
		return boat;
	}
};

int main(int argc, char const *argv[])
{
	vector<int> v = {3,2,2,1};
	Solution sln;
	sln.numRescueBoats(v, 3);

	return 0;
}

