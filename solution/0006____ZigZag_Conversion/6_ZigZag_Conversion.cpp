#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if(s == "" | numRows == 1){
			return s;
		}
		this->init(s, numRows);
		this->get_result(s, numRows);
		return get_string();
	}
private:
	vector<string> matrix;
	void init(const string& s, int numRows){
		int col = s.size() / (numRows * 2 - 2) * (numRows - 1) + (numRows - 1);
		matrix.clear();
		matrix.resize(numRows);
		for(auto& elem: matrix){
			elem.resize(col, '+');
		}
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
			if(count == s.size()){
				return;
			}
			for(int i = 1; i < row; ++i){
				loc.first++;
				matrix[loc.first][loc.second] = s[count];
				count++;
				if(count == s.size()){
					return;
				}
			}
			for(int i = 2; i < row; ++i){
				loc.first--;
				loc.second++;
				matrix[loc.first][loc.second] = s[count];
				count++;
				if(count == s.size()){
					return;
				}
			}
		}
	}
	string get_string(){
		string s;
		for(int i = 0; i < matrix.size(); ++i){
			for(int ii = 0; ii < matrix.front().size(); ++ii){
				if(matrix[i][ii] != '+'){
					s.push_back(matrix[i][ii]);
				}
			}
		}
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