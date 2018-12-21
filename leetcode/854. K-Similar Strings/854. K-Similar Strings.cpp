#include <string>
using std::string;
#include <algorithm>
using std::find_if; using std::swap;

// Ì°ÐÄÊÇ´íµÄ


class Solution {
public:
	int kSimilarity(string A, string B) {
		int min_swap = 0;
		for (int i = 0; i != A.size(); ++i)
		{
			if (A[i] != B[i])
			{
				for (int j = i + 1; j != A.size(); ++j)
				{
					if (B[j] == A[i] && B[j] != A[j])
						swap(B[i], B[j]);
				}
				++min_swap;
			}
		}
		return min_swap;
	}
};

int main()
{
	string s1{ "abcbca" }, s2{ "ababcc" };
	Solution s;
	auto ret = s.kSimilarity(s1, s2);
	return 0;
}