#include <cassert>
#include <vector>
using namespace std;
class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		int number = 0;
		for (auto i : data)
			number ^= i;

		int aux = 1;
		int index = 0;
		for (int i = 0; i != 32; ++i)
		{
			if (number & aux)
				break;
			aux <<= 1;
		}

		*num1 = 0;
		*num2 = 0;
		for (auto i : data)
		{
			if (i & aux)
				*num1 ^= i;
			else
				*num2 ^= i;
		}
	}
};

int main()
{
	Solution s;
	int a, b;
	s.FindNumsAppearOnce({ 2, 4, 3, 6, 3, 2, 5, 5 }, &a, &b);
	return 0;
}