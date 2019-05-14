#include <string>
#include <iostream>
using namespace std;
// ����������ȥ�˿ո�Ȼ���ȥ��������巭ת��Ȼ���ٶԵ��ʷ�ת��
// ���õķ����ǣ���ȥ�ո�ʱ���Ե��ʽ��з�ת��ȥ��֮������巭ת����һ�η�ת
class Solution {
public:
	string reverseWords(string s) {
		if (s.empty())
			return s;
		int start = 0, end = 0;
		while (start < s.size())
		{
			if (end == 0 && s[start] == ' ')	// ��ͷ�ո�
				++start;
			else if (start != 0 && s[start] == ' ' && s[start - 1] == ' ')	// �����ո�
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