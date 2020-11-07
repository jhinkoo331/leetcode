#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	/**
	 * @brief this method takes lots of memory and calculation
	 * @perf: [5, 5]
	 * @time: n
	 * @space: n^2
	 */
	string _1(string s, int numRows) {
		if(s == "" | numRows == 1){
			return s;
		}
		this->init(s, numRows);
		this->get_result(s, numRows);
		return get_string();
	}
	string convert(string s, int numRows){
		string ans;
		_2(s, numRows, ans);
		return ans;
	}
private:
	/**
	 * @perf: 4ms, 99, 5
	 * @time: n
	 * @space: n
	 */
	void _2(string& s, int numRows, string& ans){
		if(numRows == 1){
			ans = s;
			return;
		}
		ans.reserve(s.size());
		// the first row
		for(int i = 0; i < s.size(); i += numRows * 2-  2)
			ans.push_back(s[i]);
		// mid rows, there are two skeps per round
		int first_skip = numRows * 2 - 2 - 2;
		int second_skip = 2;
		while(first_skip != 0){
			for(int i = second_skip / 2; i < s.size(); ){
				ans.push_back(s[i]);
				i += first_skip;
				if(i < s.size())
					ans.push_back(s[i]);
				i += second_skip;
			}
			first_skip -= 2;
			second_skip += 2;
		}
		// the last row
		for(int i = numRows - 1; i < s.size(); i += numRows * 2 - 2)
			ans.push_back(s[i]);
	}
	vector<string> matrix;
	void init(const string& s, int numRows){
		int col = s.size() / (numRows * 2 - 2) * (numRows - 1) + (numRows - 1);
		matrix.clear();
		matrix.resize(numRows);
		for(auto& elem: matrix)
			elem.resize(col, '+');
	}
	void get_result(const string& s, int row){
		int cur = 0;
		pair<int, int> loc = {1, -1};
		int count = 0;
		while(true){
			loc.first--;
			loc.second++;
			matrix[loc.first][loc.second] = s[count];
			count++;
			if(count == s.size())
				return;
			for(int i = 1; i < row; ++i){
				loc.first++;
				matrix[loc.first][loc.second] = s[count];
				count++;
				if(count == s.size())
					return;
			}
			for(int i = 2; i < row; ++i){
				loc.first--;
				loc.second++;
				matrix[loc.first][loc.second] = s[count];
				count++;
				if(count == s.size())
					return;
			}
		}
	}
	string get_string(){
		string s;
		for(int i = 0; i < matrix.size(); ++i)
			for(int ii = 0; ii < matrix.front().size(); ++ii)
				if(matrix[i][ii] != '+')
					s.push_back(matrix[i][ii]);
		return s;
	}
};

int main(){
	string s;
	Solution sln;
	s = sln.convert("PAYPALISHIRING", 2);
	s = sln.convert("PAYPALISHIRING", 3);
	s = sln.convert("PAYPALISHIRING", 4);
	s = sln.convert("", 5);
	return 0;
}