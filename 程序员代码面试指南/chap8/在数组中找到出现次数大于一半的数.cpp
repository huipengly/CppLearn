#include <vector>
using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int candidate = 0;
		int times = 0;
		for (int num : nums)
		{
			if (times == 0)
			{
				candidate = num;
				times = 1;
			}
			else if (candidate == num)
				++times;
			else
				--times;
		}

		// ����Ƿ񳬹�1/2
		times = 0;
		for (int num : nums)
		{
			if (num == candidate)
				++times;
		}

		if (times > (nums.size() / 2))
			return candidate;
		else
		{
			error = true;
			return -1;
		}
	}
private:
	bool error = false;
};