#include <vector>
using namespace std;

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int counter = 0;
		for (int i = 0; i != grid.size(); ++i)
		{
			for (int j = 0; j != grid[0].size(); ++j)
			{
				if (grid[i][j] == '1')
				{
					++counter;
					infect(grid, i, j);
				}
			}
		}
		return counter;
	}
private:
	void infect(vector<vector<char>>& grid, int i, int j)
	{
		if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != '1')
			return;
		grid[i][j] = 2;
		infect(grid, i + 1, j);
		infect(grid, i - 1, j);
		infect(grid, i, j + 1);
		infect(grid, i, j - 1);
	}
};