#include <stack>
#include <cassert>
using namespace std;
class Solution {
public:
	void push(int value) {
		value_stack.push(value);
		if (min_stack.empty() || value < min_stack.top())
			min_stack.push(value);
		else
			min_stack.push(min_stack.top());
	}
	void pop() {
		assert(!value_stack.empty());

		value_stack.pop();
		min_stack.pop();
	}
	int top() {
		assert(!value_stack.empty());

		return value_stack.top();
	}
	int min() {
		assert(!min_stack.empty());

		return min_stack.top();
	}
private:
	stack<int> value_stack;
	stack<int> min_stack;
};