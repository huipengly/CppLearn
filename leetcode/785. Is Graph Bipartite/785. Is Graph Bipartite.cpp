#include <vector>
using std::vector;

class Solution {
public:
	bool isBipartite(vector<vector<int>>& graph) {
		auto &G = graph;
		marked = vector<bool>(G.size());
		color = vector<bool>(G.size());
		bipatite = true;
		for (int s = 0; s != G.size(); ++s)
			if (!marked[s])
				dfs(G, s);
		return bipatite;
	}
private:
	vector<bool> marked;
	vector<bool> color;
	bool bipatite;
	void dfs(vector<vector<int>> &G, int v)
	{
		marked[v] = true;
		for (auto w : G[v])
			if (!bipatite)
				return;
			else if (!marked[w])
			{
				color[w] = !color[v];		// 先上色
				dfs(G, w);
			}
			else if (color[w] == color[v])	// 不是未上色的就判断是否矛盾
				bipatite = false;
	}
};

int main()
{
	vector<vector<int>> g{{1, 3}, {0, 2}, {1, 3}, {0, 2}};
	vector<vector<int>> test;
	Solution s;
	auto ret = s.isBipartite(test);
	return 0;
}