#include <string>
#include <stack>
#include <vector>
#include <sstream>
using std::vector;
using std::stack;
using std::string;
class Solution {
public:
	bool isValidSerialization(string preorder) {
		return _1(preorder);
	}
private:
	vector<string> v;
	/**
	 * @brief
	 * @perf: [40, 40]
	 * @time: O(n)
	 * @space: worst: O(n), avg: O(log_n)
	 */
	bool _1(string& preorder){
		_1_preprocess(preorder);
		/**
		 * @brief the element in s is:
		 * @zero: the node is added
		 * @one: the node's left child has be accessed
		 * @two: the node's right child has be accessed
		 */
		stack<int> s;
		//* push the root node into the stack
		if(v[0] == "#")
			return v.size() == 1;		//! the tree is empty
		else
			s.push(0);
		for(int i = 1; i < v.size(); ++i){
			if(s.empty())
				return false;
			if(v[i] == "#"){
				++s.top();
				while(!s.empty() && s.top() == 2)
					s.pop();
			}else{
				++s.top();
				s.push(0);
			}
		}
		return s.empty();
	}
	void _1_preprocess(string& preorder){
		int count = 1;
		for(int i = 0; i < preorder.size(); ++i)
			if(preorder[i] == ','){
				++count;
				preorder[i] = ' ';
			}
		v.resize(count);
		std::stringstream ss;
		ss << preorder;
		for(int i = 0; i < count; ++i)
			ss >> v[i];
	}
};

int main(){
	Solution sln;
	sln.isValidSerialization("");
	sln.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#");
	return 0;
}