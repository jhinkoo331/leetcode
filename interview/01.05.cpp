#include <string>
using std::string;

class Solution {
public:
	bool oneEditAway(string first, string second) {
		return _1(first, second);
	}
private:
	/**
	 * @perf: [4ms, 100]
	 * 
	 * @param first 
	 * @param second 
	 * @return true 
	 * @return false 
	 */
	bool _1(string first, string second){
		int table[128] = {0};
		for(auto e: first)
			++table[e];
		for(auto e: second)
			--table[e];
		char remove = 0;
		char add = 0;
		for(int i = 0; i < 128; ++i)
			if(table[i] > 1 || table[i] < -1)
				return false;
			else if(table[i] == 1)
				if(remove != 0)
					return false;
				else
					remove = i;
			else if(table[i] == -1)
				if(add != 0)
					return false;
				else
					add = i;

		if(remove == 0 & add == 0)	//* first is a permutation of second
			return first == second;
		else if(remove != 0 & add != 0){	//* change a char
			for(int i = 0; i < first.size(); ++i)
				if(first[i] != second[i]){
					first[i] = second[i];
					break;
				}
			return first == second;
		}else if(remove != 0){		//* remove a char from first
			int i = 0;
			for(; i < second.size(); ++i)
				if(first[i] != second [i])
					break;
			first.erase(first.begin() + i);
			return first == second;
		}else{				//* remove a char from second
			int i = 0;
			for(; i < first.size(); ++i)
				if(first[i] != second[i])
					break;
			second.erase(second.begin() + i);
			return first == second;
		}
	}
};
