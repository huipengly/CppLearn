#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.empty())
			return {};
		int tR = 0, tC = 0;
		int dR = matrix.size(), dC = matrix[0].size();
		res.reserve(dR-- * dC--);
		while (tR <= dR && tC <= dC)
			spiralOrder(matrix, tR++, tC++, dR--, dC--);
		return res;
	}
private:
	vector<int> res;
	void spiralOrder(const vector<vector<int>>& matrix, int tR, int tC, int dR, int dC)
	{
		if (tR > dR || tC > dC)
			return;
		if (tR == dR)
		{
			for (int col = tC; col <= dC; ++col)
				res.push_back(matrix[tR][col]);
		}
		else if (tC == dC)
		{
			for (int row = tR; row <= dR; ++row)
				res.push_back(matrix[row][tC]);
		}
		else
		{
			for (int col = tC; col <= dC; ++col)
				res.push_back(matrix[tR][col]);
			for (int row = tR + 1; row <= dR; ++row)
				res.push_back(matrix[row][dC]);
			for (int col = dC - 1; col >= tC; --col)
				res.push_back(matrix[dR][col]);
			for (int row = dR - 1; row > tR; --row)
				res.push_back(matrix[row][tC]);
		}
	}
};

int main()
{
	Solution s;
	vector<vector<int>> matrix{ {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16} };
	vector<vector<int>> matrix2{ {1, 2, 3, 4}, {5, 6, 7, 8} };
	auto ret = s.spiralOrder(matrix);
	for (int i : ret)
		cout << i << " ";
	cout << endl;
	return 0;
}