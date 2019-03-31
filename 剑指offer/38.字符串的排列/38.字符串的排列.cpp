#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// 不用辅助空间
class Solution {
public:
	vector<string> Permutation(string str) {
		if (str.empty())
			return {};
		vector<string> permutation;
		Permutation(str, "", permutation);
		sort(permutation.begin(), permutation.end());
		return permutation;
	}
private:
	void Permutation(string original, string str, vector<string> &permutation)
	{
		if (original.size() == 0)
		{
			permutation.push_back(str);
			return;
		}

		if (str == "c")
			int a = 0;

		for (int i = 0; i != original.size(); ++i)
		{
			if (i == 0 || original[0] != original[i])
			{
				swap(original[0], original[i]);
				Permutation(original.substr(1), str + original[0], permutation);
				swap(original[0], original[i]);
			}
		}
	}
};

// STL
//class Solution {
//public:
//	vector<string> Permutation(string str) {
//		if (str.empty())
//			return {};
//		vector<string> permutation;
//		permutation.push_back(str);
//		while (next_permutation(str.begin(), str.end()))
//			permutation.push_back(str);
//
//		return permutation;
//	}
//};

// 辅助空间
//class Solution {
//public:
//	vector<string> Permutation(string str) {
//		if (str.empty())
//			return {};
//
//		sort(str.begin(), str.end());
//
//		vector<string> permutation;
//		vector<bool> mark(str.size(), false);
//		Permutation(mark, str, "", permutation);
//		return permutation;
//	}
//private:
//	void Permutation(vector<bool> &mark, string &original, string str, vector<string> &permutation)
//	{
//		if (find(mark.begin(), mark.end(), false) == mark.end())
//		{
//			permutation.push_back(str);
//			return;
//		}
//
//		char last_c = '\0';
//		for (int i = 0; i != mark.size(); ++i)
//		{
//			if (!mark[i] && original[i] != last_c)
//			{
//				last_c = original[i];
//				mark[i] = true;
//				Permutation(mark, original, str + last_c, permutation);
//				mark[i] = false;
//			}
//		}
//	}
//};

int main()
{
	Solution s;
	auto ret = s.Permutation("abc");
	return 0;
}