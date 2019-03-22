#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		if (threshold < 0 || rows < 0 || cols < 0)
			return 0;
		vector<vector<bool>> mark(rows, vector<bool>(cols, false));
		return move(threshold, rows, cols, 0, 0, mark);
	}
private:
	int move(int threshold, int rows, int cols, int row, int col, vector<vector<bool>> &mark)
	{
		if (sum_bit(row) + sum_bit(col) > threshold) return 0;
		if (row < 0 || row >= rows || col < 0 || col >= cols) return 0;
		if (mark[row][col]) return 0;

		mark[row][col] = true;
		return 1 + move(threshold, rows, cols, row - 1, col, mark) +
			move(threshold, rows, cols, row + 1, col, mark) +
			move(threshold, rows, cols, row , col + 1, mark) +
			move(threshold, rows, cols, row, col - 1, mark);
	}

	int sum_bit(int number)
	{
		int ret = 0;
		while (number > 0)
		{
			ret += number % 10;
			number /= 10;
		}
		return ret;
	}
};

int main()
{
	Solution s;
	cout << s.movingCount(3, 3, 3) << endl;
	return 0;
}