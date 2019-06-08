#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> matrix(n, vector<int>(n));
		int tR = 0, tC = 0;
		int dR = n - 1, dC = n - 1;
		int number = 1;
		while (tR <= dR && tC <= dC)
			spiralOrder(matrix, tR++, tC++, dR--, dC--, number);
		return matrix;
	}
private:
	void spiralOrder(vector<vector<int>>& matrix, int tR, int tC, int dR, int dC, int& number)
	{
		if (tR > dR || tC > dC)
			return;
		if (tR == dR)
		{
			for (int col = tC; col <= dC; ++col)
				matrix[tR][col] = number++;
		}
		else if (tC == dC)
		{
			for (int row = tR; row <= dR; ++row)
				matrix[row][tC] = number++;
		}
		else
		{
			for (int col = tC; col <= dC; ++col)
				matrix[tR][col] = number++;
			for (int row = tR + 1; row <= dR; ++row)
				matrix[row][dC] = number++;
			for (int col = dC - 1; col >= tC; --col)
				matrix[dR][col] = number++;
			for (int row = dR - 1; row > tR; --row)
				matrix[row][tC] = number++;
		}
	}
};

int main()
{
	Solution s;
	auto res = s.generateMatrix(0);
	for (auto arr : res)
	{
		for (int i : arr)
			cout << i << " ";
		cout << endl;
	}
	cout << endl;
	return 0;
}