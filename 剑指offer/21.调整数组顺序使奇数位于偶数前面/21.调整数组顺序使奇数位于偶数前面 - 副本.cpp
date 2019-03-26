#include <vector>
#include <iostream>
using std::cout; using std::endl;
using std::vector;
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		int end = array.size();

		for (int i = 0; i != array.size() && i < end; ++i)
		{
			if (!(array[i] & 0x1))	// 偶数
			{
				std::swap(array[i--], array[--end]);
			}
		}
	}
};

int main()
{
	Solution s;
	vector<int> vint{ 1, 3, 4, 5, 7, 8, 9, 10 };
	s.reOrderArray(vint);
	for (auto i : vint)
		cout << i << endl;
	return 0;
}