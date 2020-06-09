#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
		if(n == 0)
			return 0;
		//* pre-work
        this->n = n;
		this->results = 0;
		this->path.clear();
		this->valid.resize(n, 1);
		//* start
		this->find_result();
		return this->results;
    }
private:
	int n;
	int results;
	vector<int> path;
	vector<int> valid;

	void find_result(){
		if(path.size() == n)
			this->results++;
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
	sln.totalNQueens(4);
	sln.totalNQueens(0);
	return 0;
}