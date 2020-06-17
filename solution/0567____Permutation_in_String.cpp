#include <string>
#include <vector>
#include <unordered_map>
using std::string;
using std::vector;

class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		return _2(s1, s2);
	}
private:
	/**
	 * @perf: [72, 71]
	 * 
	 * @param s1 
	 * @param s2 
	 * @return true 
	 * @return false 
	 */
	bool _1(string& s1, string& s2){
		if(s2.size() < s1.size())
			return false;
		int table[128] = {0};
		int non_zero_count = 0;
		for(auto e: s1)
			if(table[e]++ == 0)
				non_zero_count++;
		int ll = 0, rr = 0;
		for(; rr < s1.size(); ++rr){
			table[s2[rr]]--;
			if(table[s2[rr]] == 0)
				non_zero_count--;
			else if(table[s2[rr]] == -1)
				non_zero_count++;
		}
		while(rr != s2.size()){
			if(non_zero_count == 0)
				return true;
			table[s2[ll]]++;
			if(table[s2[ll]] == 0)
				non_zero_count--;
			if(table[s2[ll]] == 1)
				non_zero_count++;
			ll++;
			table[s2[rr]]--;
			if(table[s2[rr]] == 0)
				non_zero_count--;
			if(table[s2[rr]] == -1)
				non_zero_count++;
			rr++;
		}
		return non_zero_count == 0;
	}
	/**
	 * @perf: [34, 11]
	 * 
	 * @param s1 
	 * @param s2 
	 * @return true 
	 * @return false 
	 */
	bool _2(string& s1, string& s2){
		if(s2.size() < s1.size())
			return false;
		std::unordered_map<char, int> um;
		for(int i = 0; i < s1.size(); ++i)
			um[s1[i]]++;
		int ll = 0, rr = 0;
		for(; rr < s1.size(); ++rr)
			if(--um[s2[rr]] == 0)
				um.erase(s2[rr]);
		while(rr < s2.size()){
			if(um.empty())
				return true;
			if(++um[s2[ll]] == 0)
				um.erase(s2[ll]);
			ll++;
			if(--um[s2[rr]] == 0)
				um.erase(s2[rr]);
			rr++;
		}
		return um.empty();
	}
};


int main(){
	bool ans = 0;
	Solution sln;
	sln.checkInclusion("adc", "dcda");
	sln.checkInclusion("", "");
	sln.checkInclusion("ab", "eidbaooo");
	sln.checkInclusion("ab", "eidboaoo");
	return 0;
}

