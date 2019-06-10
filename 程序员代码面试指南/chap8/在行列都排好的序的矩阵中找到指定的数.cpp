#include <vector>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty())
			return 0;
		int row = matrix.size() - 1, col = 0;
		while (row >= 0 && col != matrix[0].size())
		{
			if (matrix[row][col] < target)
				++col;
			else if (matrix[row][col] > target)
				--row;
			else
				return true;
		}
		return false;
	}
};

int main()
{

	return 0;
}