#include <iostream>
using namespace std;
class Solution {
public:
	int  NumberOf1(int n) {
		// 当一个数m减去1变为n，在m最右边的1会变为0，此1右边的0变为1.
		// m和n按位与，得到的结果是m最右边1这一位到末尾变为0.
		// 循环，每个有一个1，则可以执行一次。
		int counter = 0;
		while (n)
		{
			n &= n - 1;
			++counter;
		}
		return counter;

		// 方法1
		//int number = 1;
		//int count = 0;
		//while (number)	// 不需要考虑int长度
		//{
		//	count += 1 && (n & number);
		//	number < 1;
		//}
		//return count;
	}
};

int main()
{
	Solution s;
	cout << s.NumberOf1(4) << endl;
	return 0;
}