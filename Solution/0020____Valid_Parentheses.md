When we meet a close bracket such as `]`, we need to check whether the top element of the stack is `[`. Before we calling function stack.top(), we must ensure that the stack is not empty, such as:
```cpp
stack<char> s;
if(s.empty() && s.top() == '['){
	return true;
}else{
	return false;
}
```
However, if we insert a `)` into the stack at the very beginning, there is no need to check whether the stack is empty or not! 'cuz when the stack is empty ( without pushing `)` firstly ), the stack has only one element `)`, which would return `false` as well.
Here is my solution: see `isValid_2`:
```cpp

class Solution {
public:
	bool isValid(string s){
		return isValid_2(s);
	}
private:
	//* perf[100, 100]
	//* compared with isValid_1, we push a ')' into the stack at the very first, so that so stack is never empty,
	//* we don't need to check whether the stack is empty before calling stack.top()
	bool isValid_2(const string& s){
		stack<char> stk;
		stk.push(')');			//* the stack is never empty
		for(const auto& c: s){
			if(c == '(' | c == '[' | c == '{'){
				stk.push(c);
			}else{
				switch (c)
				{
				case ')':
					if(stk.top() == '('){
						stk.pop();
					}else{
						return false;
					}
					break;
				case ']':
					if(stk.top() == '['){
						stk.pop();
					}else{
						return false;
					}
					break;
				case '}':
					if(stk.top() == '{'){
						stk.pop();
					}else{
						return false;
					}
					break;
				default:
					break;
				}
			}
		}
		if(stk.size() == 1){
			return true;
		}else{
			return false;
		}
	}
};
```
