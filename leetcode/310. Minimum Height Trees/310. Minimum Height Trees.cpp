#include <vector>
using std::vector;
#include <unordered_set>
using std::unordered_set;
#include <utility>
using std::pair;

/*	1.构造邻接表
	2.计算树叶，只有一个连通节点
	3.删除树叶，更新树叶
	4.重复2.3，直到仅剩1或2个节点，就是根
*/
class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		if (n == 1)
		{
			return vector<int>{0};
		}
		vector<unordered_set<int>> G;
		G.resize(n);
		for (auto &edge : edges)
		{
			int v = edge.first, w = edge.second;
			G[v].insert(w);
			G[w].insert(v);
		}

		vector<int> leaves;
		leaves.reserve(n / 2);
		for (int v = 0; v != G.size(); ++v)
		{
			auto adj = G[v];
			if (adj.size() == 1)
				leaves.push_back(v);
		}

		while (n > 2)
		{
			n -= leaves.size();
			vector<int> new_leaves;
			for (auto v : leaves)
			{
				int w = *G[v].begin();
				G[w].erase(v);
				if (G[w].size() == 1)
					new_leaves.push_back(w);
			}
			leaves = std::move(new_leaves);
		}

		return leaves;
	}
};

int main()
{
	vector<pair<int, int>> edges{ {0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4} };
	Solution s;
	auto root = s.findMinHeightTrees(6, edges);
	return 0;
}