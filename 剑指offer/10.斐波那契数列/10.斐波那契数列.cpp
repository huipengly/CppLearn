#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
int Fibonacci(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int Fibonacci2(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	int l = 1, ll = 0;
	for (int i = 2; i <= n; ++i)
	{
		int temp = l;
		l += ll;
		ll = temp;
	}
	return l;
}

vector<vector<int>> matrix_mul(vector<vector<int>> lhs, vector<vector<int>> rhs)
{
	if (lhs.empty() || rhs.empty() || lhs[0].size() != rhs.size())
		cerr << "wrong matrix." << endl;
	vector<vector<int>> res(lhs.size(), vector<int>(rhs[0].size(), 0));
	// m*n和n*l
	for (int m = 0; m != lhs.size(); ++m)
	{
		for (int l = 0; l != rhs[0].size(); ++l)
		{
			for (int n = 0; n != lhs[0].size(); ++n)
			{
				res[m][l] += lhs[m][n] * rhs[n][l];
			}
		}
	}
	return res;
}

vector<vector<int>> matrix_power(vector<vector<int>> mat, int power)
{
	if (mat.empty())
		cerr << "empty matrix." << endl;

	vector<vector<int>> res(mat.size(), vector<int>(mat[0].size(), 0));
	// 设置为单位矩阵
	for (int i = 0; i != res.size(); ++i)
		res[i][i] = 1;
	while (power != 0)
	{
		if ((power & 1) != 0)
		{
			res = matrix_mul(res, mat);
		}
		mat = matrix_mul(mat, mat);
		power >>= 1;
	}
	return res;
}

int Fibonacci3(int n)
{
	if (n <= 0)
		return 0;
	if (n == 1 || n == 2)
		return 1;

	auto matrix = matrix_power({{1, 1}, {1, 0}}, n - 2);
	return matrix[0][0] + matrix[1][0];
}

int main()
{
	for (int i = 0; i != 20; ++i)
		assert(Fibonacci2(i) == Fibonacci3(i));
	return 0;
}