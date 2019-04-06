#include <cassert>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	string ReverseSentence(string str) {
		if (str.size() <= 1)
			return str;
		reverse(str.begin(), str.end());
		for (int i = 0; i < str.size() - 1; ++i)
		{
			if (str[i] == ' ')
				continue;
			int j = i + 1;
			for (; j < str.size(); ++j)
			{
				if (str[j] == ' ')
					break;
			}
			reverse(str.begin() + i, str.begin() + j);
			i = j;
		}
		return str;
	}
};

int main()
{
	Solution s;
	auto ret = s.ReverseSentence("i am a student.");
	return 0;
}