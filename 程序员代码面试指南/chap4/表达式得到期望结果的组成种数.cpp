#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/**
	 *	表达式得到期望结果的组成种数
	 *	输入：表达式exp；期待的结果desired
	 *	返回：表达式得到期望结果有多少种组合
	 */
	int getDesiredNum(string exp, bool desired) {
		if (exp.empty() || !isValid(exp))
			return 0;

		int n = exp.size();
		vector<vector<int>> t(n, vector<int>(n));
		vector<vector<int>> f(n, vector<int>(n));
		t[0][0] = exp[0] == '1' ? 1 : 0;
		f[0][0] = exp[0] == '0' ? 1 : 0;
		for (int i = 2; i < n; i += 2)
		{
			t[i][i] = exp[i] == '1' ? 1 : 0;
			f[i][i] = exp[i] == '0' ? 1 : 0;
			for (int j = i - 2; j >= 0; j -= 2)
			{
				for (int k = j; k < i; k += 2)
				{
					switch (exp[k + 1])
					{
					case '&':
						t[j][i] += t[j][k] * t[k + 2][i];
						f[j][i] += f[j][k] * f[k + 2][i] + t[j][k] * f[k + 2][i] + f[j][k] * t[k + 2][i];
						break;
					case '|':
						t[j][i] += t[j][k] * t[k + 2][i] + t[j][k] * f[k + 2][i] + f[j][k] * t[k + 2][i];
						f[j][i] += f[j][k] * f[k + 2][i];
						break;
					case '^':
						t[j][i] += t[j][k] * f[k + 2][i] + f[j][k] * t[k + 2][i];
						f[j][i] += t[j][k] * t[k + 2][i] + f[j][k] * f[k + 2][i];
						break;
					}
				}
			}
		}
		return desired ? t[0].back() : f[0].back();
	}
private:
	bool isValid(string exp)
	{
		if ((exp.size() & 1) == 0)
			return false;
		for (int i = 0; i < exp.size(); i += 2)
		{
			if (exp[i] != '0' && exp[i] != '1')
				return false;
		}
		for (int i = 1; i < exp.size(); i += 2)
		{
			if (exp[i] != '|' && exp[i] != '&' && exp[i] != '^')
				return false;
		}
		return true;
	}
};

class Solution_brute_force {
public:
	/**
	 *	表达式得到期望结果的组成种数
	 *	输入：表达式exp；期待的结果desired
	 *	返回：表达式得到期望结果有多少种组合
	 */
	int getDesiredNum(string exp, bool desired) {
		if (exp.empty() || !isValid(exp))
			return 0;

		return process(exp, desired, 0, exp.size() - 1);

	}
private:
	bool isValid(string exp)
	{
		if ((exp.size() & 1) == 0)
			return false;
		for (int i = 0; i < exp.size(); i += 2)
		{
			if (exp[i] != '0' && exp[i] != '1')
				return false;
		}
		for (int i = 1; i < exp.size(); i += 2)
		{
			if (exp[i] != '|' && exp[i] != '&' && exp[i] != '^')
				return false;
		}
		return true;
	}

	int process(const string &exp, bool desired, int l, int r)
	{
		if (l == r)
		{
			if (desired)
				return exp[l] == '1' ? 1 : 0;
			else
				return exp[l] == '0' ? 1 : 0;
		}

		int res = 0;
		if (desired)
		{
			for (int i = l + 1; i < r; i += 2)
			{
				switch (exp[i])
				{
				case '&':
					res += process(exp, true, l, i - 1) * process(exp, true, i + 1, r);
					break;
				case '|':
					res += process(exp, true, l, i - 1) * process(exp, true, i + 1, r);
					res += process(exp, true, l, i - 1) * process(exp, false, i + 1, r);
					res += process(exp, false, l, i - 1) * process(exp, true, i + 1, r);
					break;
				case '^':
					res += process(exp, true, l, i - 1) * process(exp, false, i + 1, r);
					res += process(exp, false, l, i - 1) * process(exp, true, i + 1, r);
					break;
				}
			}
		}
		else
		{
			for (int i = l + 1; i < r; i += 2)
			{
				switch (exp[i])
				{
				case '&':
					res += process(exp, true, l, i - 1) * process(exp, false, i + 1, r);
					res += process(exp, false, l, i - 1) * process(exp, true, i + 1, r);
					res += process(exp, false, l, i - 1) * process(exp, false, i + 1, r);
					break;
				case '|':
					res += process(exp, false, l, i - 1) * process(exp, false, i + 1, r);
					break;
				case '^':
					res += process(exp, true, l, i - 1) * process(exp, true, i + 1, r);
					res += process(exp, false, l, i - 1) * process(exp, false, i + 1, r);
					break;
				}
			}
		}
		return res;
	}
};

int main()
{
	Solution_brute_force s;
	cout << s.getDesiredNum("1^0|0|1", false) << endl;
	return 0;
}