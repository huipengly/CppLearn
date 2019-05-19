#include <algorithm>
#include <string>
#include <stack>
#include <iostream>
#include <vector>
using namespace std;

// stack方法占空间多一点吧
bool isValid1(const string& str)
{
	stack<char> stack;
	for (char c : str)
	{
		if (c == '(')
			stack.push(c);
		else if (c == ')')
		{
			if (stack.top() != '(')
				return false;
			stack.pop();
		}
		else
			return false;
	}
	return true;
}

// 书上的计数方法。如果需要计数比较两个数大小，可以对一个变量进行加减，判断正负。
bool isValid2(const string& str)
{
	int status = 0;
	for (char c : str)
	{
		if (c != '(' && c != ')')
			return false;
		else if (c == ')' && --status < 0)
			return false;
		else
			++status;
	}
	return status == 0;
}

int maxLength(const string& str)
{
	vector<int> dp(str.size(), 0);
	int pre = 0;
	for (int i = 1; i != str.size(); ++i)
	{
		pre = i - dp[i - 1] - 1;
		if (str[i] == ')' && pre >= 0 && str[pre] == '(')
		{
			dp[i] = dp[i - 1] + 2 + (pre > 0 ? dp[pre - 1] : 0);
		}
	}
	return *max_element(dp.begin(), dp.end());
}

int main()
{
	cout << isValid1("()a()") << endl;
	cout << maxLength("()(()()(") << endl;
	return 0;
}