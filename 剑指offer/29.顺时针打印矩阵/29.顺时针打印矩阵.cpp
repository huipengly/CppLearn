#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		if (matrix.empty() || matrix[0].empty())
			return {};
		int rows = matrix.size(), cols = matrix[0].size();
		vector<int> ret;
		int x[2] = { 0, rows - 1 }, y[2] = { 0, cols - 1 };
		while (x[0] <= x[1] && y[0] <= y[1])
		{
			print_circle(ret, matrix, x[0], y[0], x[1], y[1]);
			++x[0]; ++y[0];
			--x[1]; --y[1];
		}

		return ret;
	}
private:
	void print_circle(vector<int> &arr, const vector<vector<int>> &matrix, int x0, int y0, int x1, int y1)
	{
		if (x0 != x1 && y0 != y1)
		{
			for (int i = y0; i <= y1; ++i)
				arr.push_back(matrix[x0][i]);


			for (int i = x0 + 1; i <= x1; ++i)
				arr.push_back(matrix[i][y1]);


			for (int i = y1 - 1; i >= y0; --i)
				arr.push_back(matrix[x1][i]);


			for (int i = x1 - 1; i >= x0 + 1; --i)
				arr.push_back(matrix[i][y0]);
		}
		else if (x0 == x1)
		{
			for (int i = y0; i <= y1; ++i)
				arr.push_back(matrix[x0][i]);
		}
		else if (y0 == y1)
		{
			for (int i = x0; i <= x1; ++i)
				arr.push_back(matrix[i][y0]);
		}
	}
};

int main()
{
	Solution s;
	vector<vector<int>> matrix{ {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
	auto ret = s.printMatrix(matrix);
	for (auto i : ret)
		cout << i << endl;
	return 0;
}