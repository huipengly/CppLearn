#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		if (matrix.empty())
			return;
		int tR = 0, tC = 0;
		int dR = matrix.size() - 1, dC = matrix[0].size() - 1;
		//while (tR <= dR && tC <= dC)	// 错的，不需要考虑最后行列相等的一个，不需要旋转。考虑了会造成数组溢出。
		while (tR < dR)
			rotate(matrix, tR++, tC++, dR--, dC--);
	}
private:
	void rotate(vector<vector<int>>& matrix, int tR, int tC, int dR, int dC)
	{
		//for (int i = tC; i != dC; ++i)   // 错的，i是偏移量，应该从0开始
		for (int i = 0; i != dC - tC; ++i)
		{
			int temp = matrix[tR][tC + i];
			matrix[tR][tC + i] = matrix[dR - i][tC];
			matrix[dR - i][tC] = matrix[dR][dC - i];
			matrix[dR][dC - i] = matrix[tR + i][dC];
			matrix[tR + i][dC] = temp;
		}
	}
};

int main()
{
	Solution s;
	vector<vector<int>> matrix{ {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16} };
	vector<vector<int>> matrix2{ {1, 2, 3}, {5, 6, 7}, {9, 10, 11}, {13, 14, 15} };
	for (auto arr : matrix2)
	{
		for (auto i : arr)
		{
			cout << i << " ";
		}
		cout << endl;
	}
	s.rotate(matrix2);
	for (auto arr : matrix2)
	{
		for (auto i : arr)
		{
			cout << i << " ";
		}
		cout << endl;
	}

	vector<vector<int>> test {{2, 29, 20, 26, 16, 28}, {12, 27, 9, 25, 13, 21}, {32, 33, 32, 2, 28, 14}, {13, 14, 32, 27, 22, 26}, {33, 1, 20, 7, 21, 7}, {4, 24, 1, 6, 32, 34}} ;
	vector<vector<int>> output{ {4, 33, 13, 32, 12, 2}, {24, 1, 7, 33, 27, 29}, {1, 20, 32, 2, 14, 20}, {6, 28, 32, 27, 25, 26}, {32, 21, 22, 9, 13, 16}, {34, 7, 26, 14, 21, 28} };
	vector<vector<int>> expect{ {4, 33, 13, 32, 12, 2}, {24, 1, 14, 33, 27, 29}, {1, 20, 32, 32, 9, 20}, {6, 7, 27, 2, 25, 26}, {32, 21, 22, 28, 13, 16}, {34, 7, 26, 14, 21, 28} };
	for (auto arr : test)
	{
		for (auto i : arr)
		{
			cout << i << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (auto arr : output)
	{
		for (auto i : arr)
		{
			cout << i << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (auto arr : expect)
	{
		for (auto i : arr)
		{
			cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}