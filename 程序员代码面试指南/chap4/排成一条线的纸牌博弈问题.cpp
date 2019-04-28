#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Cards {
public:
	int cardGame(vector<int> A, int n) {
		if (n <= 0 || A.empty())
			return 0;
		vector<vector<int>> f(n, vector<int>(n)), s(n, vector<int>(n));
		for (int i = n - 1; i >= 0; --i)
		{
			f[i][i] = A[i];
			s[i][i] = 0;
			for (int j = i + 1; j != n; ++j)
			{
				f[i][j] = std::max(A[i] + s[i + 1][j], A[j] + s[i][j - 1]);
				s[i][j] = std::min(f[i + 1][j], f[i][j - 1]);
			}
		}
		return std::max(f[0][n - 1], s[0][n - 1]);
	}
};

class Cards_brute_force {
public:
	int cardGame(vector<int> A, int n) {
		if (n <= 0 || A.empty())
			return 0;
		return std::max(f(A, 0, n - 1), s(A, 0, n - 1));
	}
private:
	int f(const vector<int>& A, int l, int r)
	{
		if (l == r)
			return A[l];
		return std::max(A[l] + s(A, l + 1, r), A[r] + s(A, l, r - 1));
	}
	int s(const vector<int>& A, int l, int r)
	{
		if (l == r)
			return 0;
		return std::min(f(A, l + 1, r), f(A, l, r - 1));
	}
};

int main()
{
	Cards c;
	cout << c.cardGame({ 1, 100, 2 }, 3) << endl;
	return 0;
}