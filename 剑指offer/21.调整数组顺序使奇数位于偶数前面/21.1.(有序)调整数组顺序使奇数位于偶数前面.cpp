#include <vector>
#include <iostream>
#include <algorithm>
using std::cout; using std::endl;
using std::vector;
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		//std::stable_partition(array.begin(), array.end(), [](int i) {return i & 1;});

		for (int i = 0; i != array.size(); ++i)
		{
			if (!(array[i] & 1))
			{
				int j = i + 1;
				for (; j != array.size(); ++j)
				{
					if (array[j] & 1)
						break;
				}
				if (j == array.size())
					break;
				else
				{
					auto temp = array[j];
					for (int k = j; k != i; --k)
					{
						array[k] = array[k - 1];
					}
					array[i] = temp;
				}
			}
		}
	}
};

int main()
{
	Solution s;
	vector<int> vint{ 1, 2, 3, 4, 5, 6, 7 };
	s.reOrderArray(vint);
	for (auto i : vint)
		cout << i << endl;
	return 0;
}