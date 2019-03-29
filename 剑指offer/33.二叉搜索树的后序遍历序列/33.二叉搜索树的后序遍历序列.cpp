#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.size() < 2)
			return true;
		int root_val = sequence.back();
		auto sub_begin = sequence.begin(), sub_end = sequence.end() - 1;
		auto ret = find_if(sub_begin, sub_end,[root_val](int n) { return root_val < n; });
		if (ret != sub_end && any_of(ret, sub_end, [root_val](int n) { return n < root_val; }))
			return false;
		bool left, right;

		left = true;
		if (ret > sub_begin)
		{
			left = VerifySquenceOfBST(vector<int>(sequence.begin(), ret));
		}

		right = true;
		if (ret < sub_end)
		{
			right = VerifySquenceOfBST(vector<int>(ret, sub_end));
		}
		
		return left && right;
	}
};

int main()
{
	Solution s;
	cout << s.VerifySquenceOfBST({5, 7, 6, 9, 11, 10, 8}) << endl;
	return 0;
}