#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
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
};

int main()
{
	Solution s;
	string str = "dog loves pig", str2 = "";
	s.reverseWords(str2);
	cout << str2 << endl;
	return 0;
}