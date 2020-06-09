#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		return s == t;
    }
};

int main(){
	Solution sln;
	bool ret;
	ret = sln.isAnagram("hello", "llohe");
	ret = sln.isAnagram("thiss", "isth");
	return 0;
}