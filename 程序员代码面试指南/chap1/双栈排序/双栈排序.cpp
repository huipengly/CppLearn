#include <stack>
#include <vector>
using namespace std;

class TwoStacks {
public:
	vector<int> twoStacksSort(vector<int> numbers) {
		vector<int> help;
		while (!numbers.empty())
		{
			int cur = numbers.back();
			numbers.pop_back();
			while (!help.empty() && cur < help.back())
			{
				numbers.push_back(help.back());
				help.pop_back();
			}
			help.push_back(cur);
		}

		while (!help.empty())
		{
			numbers.push_back(help.back());
			help.pop_back();
		}
		return numbers;
	}
};