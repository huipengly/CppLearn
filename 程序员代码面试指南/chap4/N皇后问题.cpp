#include <vector>
#include <iostream>
using namespace std;
// 位运算方法
int process2(int upperLim, int colLim, int leftDiaLim, int rightDiaLim)
{
	if (upperLim == colLim)
		return 1;

	int pos = upperLim & (~(colLim | leftDiaLim | rightDiaLim));
	int res = 0;
	while (pos != 0)
	{
		int mostRightOne = pos & (~pos + 1);
		pos -= mostRightOne;
		res += process2(upperLim, colLim | mostRightOne, 
			(leftDiaLim | mostRightOne) << 1, 
			(rightDiaLim | mostRightOne) >> 1);
	}
	return res;
}

int nQueue2(int n)
{
	if (n < 1 || n > 32)
		return 0;
	int upperLim = n == 32 ? -1 : ((1 << n) - 1);
	return process2(upperLim, 0, 0, 0);
}

// 递归方法
bool isValid(int i, int j, const vector<int>& record)
{
	for (int k = 0; k != i; ++k)
	{
		if ((j == record[k]) || (abs(i - k) == abs(j - record[k])))
			return false;
	}
	return true;
}

int process(int i, vector<int>& record, int n)
{
	if (i == n)
		return 1;

	int res = 0;
	for (int j = 0; j != n; ++j)
	{
		if (isValid(i, j, record))
		{
			record[i] = j;
			res += process(i + 1, record, n);
		}
	}
	return res;
}

int nQueue(int n)
{
	if (n < 1)
		return 0;

	vector<int> record(n, 0);
	return process(0, record, n);
}

int main()
{
	cout << nQueue2(16) << endl;
	return 0;
}