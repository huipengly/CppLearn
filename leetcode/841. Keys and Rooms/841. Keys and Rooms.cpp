#include <vector>
using std::vector;

class Solution {
public:
	bool canVisitAllRooms(vector<vector<int>>& rooms) {
		marked = vector<bool>(rooms.size());
		opened_num = 0;
		dfs(rooms, 0);
		return opened_num == rooms.size();
	}
private:
	vector<bool> marked;
	int opened_num;
	void dfs(vector<vector<int>> &G, int v)
	{
		marked[v] = true;
		++opened_num;
		for (auto w : G[v])
			if (!marked[w])
			{
				dfs(G, w);
			}
	}
};

int main()
{
	Solution s;
	vector<vector<int>> rooms{{1, 3}, {3, 0, 1}, {2}, {0}};
	auto ret = s.canVisitAllRooms(rooms);
	return 0;
}