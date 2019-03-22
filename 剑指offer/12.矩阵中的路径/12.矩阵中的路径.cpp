#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		if (matrix == nullptr || str == nullptr)
			return false;
		bool *mark = new bool[rows * cols]{ false };	// 初始化为false
		for (int i = 0; i != rows; ++i)
			for (int j = 0; j != cols; ++j)
			{
				if (Path(matrix, mark, rows, cols, i, j, str, 0))
					return true;
			}
		delete[] mark;
		return false;
	}
private:

	bool Path(char* matrix, bool *mark, int rows, int cols, int row, int col, char* str, int sindex)
	{
		if (str[sindex] == '\0')		// 匹配全部
			return true;

		if (row < 0 || row >= rows || col < 0 || col >= cols)	// 过边界
			return false;
		
		if (!mark[row * cols + col] && str[sindex] == matrix[row * cols + col])
		{
			mark[row * cols + col] = true;
			++sindex;
			auto ret = Path(matrix, mark, rows, cols, row - 1, col, str, sindex)
				|| Path(matrix, mark, rows, cols, row + 1, col, str, sindex)
				|| Path(matrix, mark, rows, cols, row, col - 1, str, sindex)
				|| Path(matrix, mark, rows, cols, row, col + 1, str, sindex);
			mark[row * cols + col] = false;		// 清除mark
			--sindex;
			return ret;
		}
		else
			return false;
	}
};


int main()
{
	char mat[] = {"ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS"};
	char str[] = {"SLHECCEIDEJFGGFIE"};
	Solution s;
	cout << s.hasPath(mat, 5, 8, str) << endl;
	return 0;
}