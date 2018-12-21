#include <string>
using std::string;
#include <vector>
using std::vector;

class Solution {
public:
	bool isValid(string s) {
		vector<char> stack;
		for (auto c : s)
		{
			if (c == '(' || c == '[' || c == '{')
				stack.push_back(c);
			else if (c == ')')
				if (!stack.empty() && stack.back() == '(')
					stack.pop_back();
				else
					return false;
			else if (c == ']')
				if (!stack.empty() && stack.back() == '[')
					stack.pop_back();
				else
					return false;
			else if (c == '}')
				if (!stack.empty() && stack.back() == '{')
					stack.pop_back();
				else
					return false;
		}
		return stack.empty();
	}
};

int main()
{
	Solution s;
	string str{ "()" };
	auto ret = s.isValid(str);
	return 0;
}