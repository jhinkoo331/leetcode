#include <stack>
#include <algorithm>
using namespace std;

class MinStack {
public:
	MinStack(){
		while(!s.empty())
			s.pop();
		while(!min_s.empty())
			min_s.pop();
	}
	void push(int x) {
		s.push(x);
		if(min_s.empty()){
			min_s.push(x);
		}else{
			min_s.push(min(x, min_s.top()));
		}
	}
	void pop() {
		s.pop();
		min_s.pop();
	}
	int top() {
		return s.top();
	}
	int getMin() {
		return min_s.top();
	}
private:
	stack<int> s;
	stack<int> min_s;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */