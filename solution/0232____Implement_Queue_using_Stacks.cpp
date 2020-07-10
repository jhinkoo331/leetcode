#include <stack>
using std::stack;

/**
 * @brief 
 * @perf: 4ms, 38
 * 
 */
class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() {
		while(in.size())
			in.pop();
		while(out.size())
			out.pop();
	}

	/** Push element x to the back of queue. */
	void push(int x) {
		in.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		adjust();
		int temp = out.top();
		out.pop();
		return temp;
	}

	/** Get the front element. */
	int peek() {
		adjust();
		return out.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return in.empty() && out.empty();
	}
private:
	stack<int> in, out;
	void adjust(){
		if(out.empty())
			while(in.size()){
				out.push(in.top());
				in.pop();
			}
	}
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */