#include <vector>
#include <iostream>
using namespace std;

void printMatrixZigZag(const vector<vector<int>>& matrix)
{
	if (matrix.empty())
		return;
	bool fromTop = false;
	int tR = 0, tC = 0, dR = 0, dC = 0;
	int rows = matrix.size(), cols = matrix[0].size();
	while (tR != rows)
	{
		if (fromTop)
		{
			for (int row = tR, col = tC; row <= dR && col >= dC; ++row, --col)
			{
				cout << matrix[row][col] << " ";
			}
		}
		else
		{
			for (int row = dR, col = dC; row >= tR && col <= tC; --row, ++col)
			{
				cout << matrix[row][col] << " ";
			}
		}
		if (tC != cols - 1)
			++tC;
		else
			++tR;

		if (dR != rows - 1)
			++dR;
		else
			++dC;

		// �������ĸ�˳�����Ҫ���������ϵ�д�����һ��Ǿ���if�á�һ��ԭ�����ٱȽϣ���һ��ԭ���ǲ���Ҫ����˳��
		//tR = tC == (cols - 1) ? (tR + 1) : tR;
		//tC = tC == (cols - 1) ? tC : (tC + 1);
		//dC = dR == (rows - 1) ? (dC + 1) : dC;
		//dR = dR == (rows - 1) ? dR : (dR + 1);
		fromTop = !fromTop;
	}
}

int main()
{
	vector<vector<int>> matrix{ {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };
	printMatrixZigZag(matrix);
	return 0;
}