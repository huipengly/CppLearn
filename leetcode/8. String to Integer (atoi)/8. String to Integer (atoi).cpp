#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		str = str.substr(find_if(str.begin(), str.end(), [](char c) { return c != ' '; }) - str.begin());	// È¥¿Õ¸ñ
		auto it = str.begin(), end = str.end();
		int status = 0;
		long long number = 0;
		bool positive = true;
		while (it != end)
		{
			switch (status)
			{
			case 0:
				if (*it == '-')
					positive = false;
				else if (*it == '+')
					positive = true;
				else if (*it >= '0' && *it <= '9')
					number = *it - '0';
				else if (*it < '0' || *it > '9')
				{
					status = 10;
					break;
				}
				status = 1;
				break;
			case 1:
				if (*it >= '0' && *it <= '9')
				{
					number = number * 10 + *it - '0';
					if (number > INT_MAX)
					{
						status = 10;
						number = positive ? INT_MAX : (INT_MAX + 1);
					}
				}
				else if (*it < '0' || *it > '9')
					status = 10;
				break;
			case 10:
				it = end - 1;
				break;
			}
			++it;
		}
		return positive ? number : -number;
	}
};

int main()
{
	Solution s;
	cout << s.myAtoi(".1") << endl;
	return 0;
}