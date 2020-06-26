#include <vector>
#include <string>
#include <set>
using std::multiset;
using std::vector;
using std::string;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		return _1(s, words);
	}
private:
	multiset<string> ms;
	/**
	 * @brief 
	 * @perf: [5, 13]
	 * @param s 
	 * @param words 
	 * @return vector<int> 
	 */
	vector<int> _1(const string& s, const vector<string>& words){
		vector<int> ans;
		if(words.empty())
			return ans;
		int map[128] = {0};
		int non_zero_count = 0;
		//* set up multiset
		for(int i = 0; i < words.size(); ++i)
			ms.insert(words[i]);
		//* set up map
		for(const auto& e: words)
			for(const auto& ee: e){
				--map[ee];
				if(map[ee] == -1)
					++non_zero_count;
			}
		int total_len = words.size() * words.front().size();
		if(s.size() < total_len)
			return ans;
		int ll = 0, rr = 0;
		while(rr < total_len){
			++map[s[rr]];
			if(map[s[rr]] == 0)
				--non_zero_count;
			else if(map[s[rr]] == 1)
				++non_zero_count;
			++rr;
		}
		while(true){
			//* check current substring
			if(non_zero_count == 0 && _1_test_substring(s, ll))
				ans.push_back(ll);
			//* shift window
			if(rr == s.size())
				break;
			--map[s[ll]];
			if(map[s[ll]] == 0)
				--non_zero_count;
			else if(map[s[ll]] == -1)
				++non_zero_count;
			++ll;
			++map[s[rr]];
			if(map[s[rr]] == 1)
				++non_zero_count;
			else if(map[s[rr]] == 0)
				--non_zero_count;
			++rr;
		}
		return ans;
	}

	bool _1_test_substring(const string& s, int i){
		multiset<string> temp(ms);
		int len = ms.begin()->size();
		int times = temp.size();
		while(times--){
			if(temp.find(s.substr(i, len)) != temp.end())
				temp.erase(temp.find(s.substr(i, len)));
			else
				return false;
			i += len;
		}
		return true;
	}
};

int main(){
	string s = "abababab";
	vector<string> v = {"ab", "ba"};
	Solution sln;
	sln.findSubstring(s, v);
	return 0;
}




