#include <vector>
using namespace std;
class ReverseStack {
public:
	vector<int> reverseStackRecursively(vector<int> stack, int top) {
		if (stack.empty() || top == 0)
			return {};
		vector<int> ret;
		reverseStackRecursively(stack, ret);
		return ret;
	}
private:
	int get_and_remove_last_element(vector<int> &stack)
	{
		int value = stack.back();
		stack.pop_back();
		if (stack.empty())
			return value;
		else
		{
			auto ret = get_and_remove_last_element(stack);
			stack.push_back(value);
			return ret;
		}
	}
	void reverseStackRecursively(vector<int> &stack, vector<int> &ret)
	{
		if (stack.empty())
			return;
		int value = get_and_remove_last_element(stack);
		reverseStackRecursively(stack, ret);
		ret.push_back(value);
	}
};

int main()
{
	ReverseStack r;
	auto ret = r.reverseStackRecursively({ 1, 2, 3, 4, 5 }, 5);
	return 0;
}