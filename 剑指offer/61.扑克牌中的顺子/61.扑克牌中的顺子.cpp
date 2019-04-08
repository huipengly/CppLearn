#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool IsContinuous(vector<int> numbers) {
		if (numbers.size() < 5)
			return false;
		sort(numbers.begin(), numbers.end());
		
		int i = 0;
		for (; i != 5; ++i)
		{
			if (numbers[i] != 0) 
				break;
		}

		if (unique(numbers.begin() + i, numbers.end()) != numbers.end())
			return false;
		if (numbers.back() - numbers[i] == 4 || i == 4)
			return true;
		return false;
	}
};

int main()
{
	Solution s;
	s.IsContinuous({ 0, 3, 2, 6, 4 });
	return 0;
}