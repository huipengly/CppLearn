#include <vector>
using std::vector;
#include <utility>
using std::pair;
#include <stack>
using std::stack;
#include <numeric>
using std::iota;

// 若有环则无法完成，只判断环，不需要拓补排序
class Solution {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		if (prerequisites.empty())
		{
			vector<int> ret(numCourses);
			iota(ret.begin(), ret.end(), 0);
			return ret;
		}
		// 有向图，A节点指向B节点。说明A是B的先决条件。
		vector<vector<int>> G(numCourses);
		for (auto p : prerequisites)	// 处理数据为图
		{
			G[p.second].push_back(p.first);
		}
		marked = vector<bool>(G.size(), false);
		on_stack = vector<bool>(G.size(), false);
		for (int v = 0; v != G.size(); ++v)
			if (!marked[v])
				dfs(G, v);
		if (cycle)
			return vector<int>();
		return vector<int>(reversePost.crbegin(), reversePost.crend());
	}
private:
	vector<int> reversePost;
	vector<bool> marked;
	vector<bool> on_stack;
	bool cycle = false;
	void dfs(const vector<vector<int>> &G, int v)
	{
		marked[v] = true;
		on_stack[v] = true;
		for (auto w : G[v])
		{
			if (cycle)
				return;
			else if (!marked[w])
				dfs(G, w);
			else if (on_stack[w])
			{
				cycle = true;
				return;
			}
		}
		on_stack[v] = false;
		reversePost.push_back(v);
	}
};

int main()
{
	vector<pair<int, int>> vp{ {0, 1}, {1, 0} };
	Solution s;
	s.canFinish(2, vp);
	return 0;
}