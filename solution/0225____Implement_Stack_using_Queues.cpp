#include <queue>
using std::queue;

/**
 * @brief 
 * @perf: 100, 15
 */
class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {
		while(q.size())
			q.pop();
		while(temp.size())
			temp.size();
	}

	/** Push element x onto stack. */
	void push(int x) {
		temp.push(x);
		while(q.size()){
			temp.push(q.front());
			q.pop();
		}
		q.swap(temp);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int temp = q.front();
		q.pop();
		return temp;
	}

	/** Get the top element. */
	int top() {
		return q.front();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return q.empty();
	}
private:
	queue<int> q, temp;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */