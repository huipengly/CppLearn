#include <deque>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 这里处理加减的逻辑
int getNum(deque<string>& deq)
{
	int res = 0;
	bool add = true;
	string cur;
	int num = 0;
	while (!deq.empty())
	{
		cur = deq.front();
		deq.pop_front();
		if (cur == "+")
			add = true;
		else if (cur == "-")
			add = false;
		else
		{
			num = stoi(cur);
			res += add ? num : (-num);
		}
	}
	return res;
}

// 所有的乘除都在这里处理了
void addNum(deque<string>& deq, int num)
{
	if (!deq.empty())
	{
		int cur = 0;
		string top = deq.back();
		deq.pop_back();
		if (top == "+" || top == "-")
		{
			deq.push_back(top);
		}
		else
		{
			cur = stoi(deq.back());
			deq.pop_back();
			num = top == "*" ? (cur * num) : (cur / num);
		}
	}
	deq.push_back(to_string(num));
}

vector<int> value(const string& str, int i)
{
	deque<string> deq;
	int pre = 0;
	vector<int> bra;
	while (i < str.size() && str[i] != ')')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			pre = pre * 10 + str[i++] - '0';
		}
		else if (str[i] != '(')
		{
			addNum(deq, pre);
			deq.push_back(string{ str[i++] });
			pre = 0;
		}
		else
		{
			bra = value(str, i + 1);
			pre = bra[0];
			i = bra[1] + 1;
		}
	}
	addNum(deq, pre);
	return { getNum(deq), i };
}

int getValue(const string& str)
{
	return value(str, 0)[0];
}

int main()
{
	string str;
	while (1)
	{
		cout << "please input a valid function. Input q to quie." << endl;
		cin >> str;
		if (str == "q")
			break;
		cout << str << "=" << getValue(str) << endl;
	}

	return 0;
}