#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int getMaxLength(const vector<int>& arr, int k)
{
	int left = 0, right = 0;
	int maxLen = 0, sum = 0;
	while (right < arr.size())
	{
		if (sum == k)
		{
			maxLen = std::max(right - left + 1, maxLen);
			sum -= arr[left++];
		}
		else if (sum < k)
		{
			if (++right == arr.size())		// ·ÀÖ¹Ô½½ç
				break;
			sum += arr[right];
		}
		else if (sum > k)
		{
			sum -= arr[left++];
		}
	}
	return maxLen;
}

int main()
{
	cout << getMaxLength({ 1, 2, 1, 1, 1 }, 3) << endl;
	return 0;
}