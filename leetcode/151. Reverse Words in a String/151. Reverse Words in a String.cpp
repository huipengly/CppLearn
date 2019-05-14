#include <string>
#include <iostream>
using namespace std;
// 我这里是先去了空格，然后对去除后的整体翻转，然后再对单词翻转。
// 更好的方法是，在去空格时，对单词进行翻转，去除之后对整体翻转。少一次翻转
class Solution {
public:
	string reverseWords(string s) {
		if (s.empty())
			return s;
		int start = 0, end = 0;
		while (start < s.size())
		{
			if (end == 0 && s[start] == ' ')	// 开头空格
				++start;
			else if (start != 0 && s[start] == ' ' && s[start - 1] == ' ')	// 连续空格
				++start;
			else
				s[end++] = s[start++];
		}
		--end;
		if (end >= 0 && s[end] == ' ')
			--end;
		return reverseWords(s, end).substr(0, end + 1);
	}
private:
	string reverseWords(string& s, int stopIndex)
	{
		reverse(s, 0, stopIndex);
		int start = 0, end = 0;
		while (end != stopIndex + 1)
		{
			if (s[end] == ' ')
			{
				reverse(s, start, end - 1);
				start = end + 1;
			}
			++end;
		}
		reverse(s, start, end - 1);
		return s;
	}
	void reverse(string& s, int start, int end)
	{
		while (start >= 0 && start < s.size() &&
			end >= 0 && end < s.size() &&
			start < end)
		{
			swap(s[start++], s[end--]);
		}
	}
};

int main()
{
	Solution s;
	string str = "  hello  my   world!  ";
	cout << s.reverseWords(str) << endl;
	return 0;
}