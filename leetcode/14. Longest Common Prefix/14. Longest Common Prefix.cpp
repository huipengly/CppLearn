#include <string>
using std::string;
#include <vector>
using std::vector;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0)
			return "";
		string prefix = "";
		auto end_flag = false;
		int index = 0;
		while (!end_flag)
		{
			char c = 0;
			for (int i = 0; i != strs.size(); ++i)
			{
				if (index == strs[i].size())	// 到最后一位
				{
					end_flag = true;
					break;
				}
				if (c == 0)
					c = strs[i][index];
				else if (c != strs[i][index])
				{
					end_flag = true;
					break;
				}
			}
			if (!end_flag)
				prefix += c;
			++index;
		}
		return prefix;
	}
};

int main()
{
	Solution s;
	vector<string> strs{ };
	auto ret = s.longestCommonPrefix(strs);

	return 0;
}