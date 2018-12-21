#include <string>
using std::string; using std::to_string;
#include <vector>
using std::vector;
#include <map>
using std::map;
#include <algorithm>
using std::transform;

class Solution {
public:
	string largestNumber(vector<int>& nums) {
		// ����գ��򷵻�0
		if (nums.empty())
		{
			return "0";
		}
		vector<string> vstr;
		transform(nums.begin(), nums.end(), std::back_inserter(vstr), [](const int &i) {return to_string(i); });
		sort(vstr.rbegin(), vstr.rend(), 
			[](const string &str1, const string &str2)
			{
				// �жϴ�С
				int size = str1.size() < str2.size() ? str1.size() : str2.size();
				for (int i = 0; i != size; ++i)
				{
					if (str1[i] < str2[i])
						return true;
					else if (str1[i] > str2[i])
						return false;
				}
				// �����ͬ���ȴ���ͬ����ô�жϲ�ͬ���˳���С
				return str1 + str2 < str2 + str1;
			}
		);
		// �����һ��λΪ0���������Ϊ0
		if (vstr[0] == "0")
			return "0";
		string ret{""};
		for (auto s : vstr)
		{
			ret += s;
		}
		return ret;
	}
};

int main()
{
	vector<int> vec{ 3,30,34,5,9 };
	vector<int> vec2{ 0, 0, 0, 0, 0, 0, 0 };
	vector<int> *ptr = nullptr;
	Solution s;
	s.largestNumber(vec2);
	return 0;
}