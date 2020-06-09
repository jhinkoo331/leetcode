#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
		//* pre-work
        this->n = n;
		this->results.clear();
		if(n == 0){
			return this->results;
		}
		this->path.clear();
		this->valid.resize(n, 1);
		//* start
		this->find_result();
		return this->results;
    }
private:
	int n;
	vector<vector<string>> results;
	vector<int> path;
	vector<int> valid;

	void find_result(){
		if(path.size() == n)
			add_result();
		else{
			for(int i = 0; i < n; ++i){
				if(valid[i] && no_conflict(i)){
					path.push_back(i);
					valid[i] = false;
					find_result();
					path.pop_back();
					valid[i] = true;
				}
			}
		}
	}
	void add_result(){
		// convert path into a vector<string> and push it into results
		vector<string> temp;
		temp.resize(n);
		for(auto& elem: temp)
			elem = string(n, '.');
		for(int i = 0; i < n; i++)
			temp[i][path[i]] = 'Q';
		results.push_back(temp);
	}
	bool no_conflict(int next){
		// check whether `i` would render a conflict with numbers in `path`
		for(int i = 0; i < path.size(); ++i){
			// [i, path[i]] and [path.size(), next]
			if(abs(i - (int)path.size()) == abs(path[i] - next))
				return false;
		}
		return true;
	}
};

int main(){
	Solution sln;
	sln.solveNQueens(4);
	sln.solveNQueens(0);
	return 0;
}