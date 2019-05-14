#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
	// 翻转字符串原题
	void reverseWords(string& s) {
		reverse(s, 0, s.size() - 1);
		int start = 0, end = 0;
		while (end != s.size())
		{
			if (s[end] == ' ')
			{
				reverse(s, start, end - 1);
				start = end + 1;
			}
			++end;
		}
		reverse(s, start, end - 1);
	}
	// 补充问题
	void rotate1(string& s, int size)
	{
		if (s.empty() || s.size() < size)
			return;
		reverse(s, 0, size - 1);
		reverse(s, size, s.size() - 1);
		reverse(s, 0, s.size() - 1);
	}

	void rotate2(string& s, int size)
	{
		int start = 0, end = s.size() - 1;
		int lpart = size, rpart = s.size() - size;
		int min_size = std::min(lpart, rpart);
		int d = lpart - rpart;
		while (d != 0)
		{
			exchange(s, start, end, min_size);
			if (d > 0)
			{
				start = start + min_size;
				lpart = d;
			}
			else
			{
				end = end - min_size;
				rpart = -d;
			}
			min_size = std::min(lpart, rpart);
			d = lpart - rpart;
		}
		exchange(s, start, end, min_size);	// 如果左右相等，则需要执行互换一次
	}
private:
	void reverse(string& s, int start, int end)
	{
		while (start >= 0 && start < s.size() &&
			end >= 0 && end < s.size() &&
			start < end)
		{
			swap(s[start++], s[end--]);
		}
	}
	void exchange(string& s, int start, int end, int size)
	{
		end = end - size + 1;
		while (size-- != 0 && start < s.size() && end < s.size())
		{
			swap(s[start++], s[end++]);
		}
	}
};

int main()
{
	Solution s;
	string str = "dog loves pig", str2 = "";
	s.reverseWords(str);
	cout << str << endl;
	string str3 = "123456ABCD", str4 = str3;
	s.rotate1(str3, 6);
	s.rotate2(str4, 6);
	cout << "str3: " << str3 << endl;
	cout << "str4: " << str4 << endl;
	return 0;
}