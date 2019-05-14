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
        return s;
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