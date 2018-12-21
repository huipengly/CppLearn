#include <vector>
using std::vector;

// 问题简化未仅有一个环的图，找到使这个图成环的边
// 1. union find.每次连接两个点，若count没减少，说明成环
// 2. dfs 
//	2.1 构造整个图，寻找图中的环，找到vector中最靠后一个边。
//	2.2 每加入一个边就检查一下图是否成环，若成环则就是这个边。		// 很费时
// 3. 删除图中的叶，到无法删除，就是环

// 实现了1和2.2

class Solution_2_2 {
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		G.resize(edges.size());
		for (auto edge : edges)
		{
			auto v = edge.front() - 1, w = edge.back() - 1;	// 输入从1开始，修正为从0开始
			G[v].push_back(w);
			G[w].push_back(v);
			marked = vector<bool>(G.size(), false);
			for (int s = 0; s != G.size(); ++s)				// 图最开始可能是不连通的
				if (!marked[s])
					dfs(s, s);
			if (cycle)
				return edge;
		}
		return vector<int>();
	}
private:
	vector<vector<int>> G;
	vector<bool> marked;
	vector<int> cycle_vector;
	bool cycle = false;
	void dfs(int v, int u)
	{
		marked[v] = true;
		for (auto w : G[v])
			if (cycle)
				return;
			else if (!marked[w])
			{
				dfs(w, v);
			}
			else if (w != u) 
				cycle = true;
	}
};

#include <numeric>
using std::iota;
class WeightedQuickUnionWithCompressUF {
public:
	WeightedQuickUnionWithCompressUF(int N) : count_(N)
	{
		id_ = vector<int>(count_);
		iota(id_.begin(), id_.end(), 0);
		sz_ = vector<int>(count_, 1);
	}

	int count() { return count_; }
	bool connected(int p, int q) { return find(p) == find(q); }

	int find(int p)
	{
		while (id_[p] != p)
		{
			id_[p] = id_[id_[p]];	// 权重压缩，将当前树连接到其父的上一代上。
			p = id_[p];
		}
		return p;
	}

	void union_point(int p, int q)
	{
		int i = find(p);
		int j = find(q);
		if (i == j) return;			// p、q同根，则不需要合并
		if (sz_[i] < sz_[j])		// 将小树合并到大树上，并更新大树的sz，减少count
		{
			id_[i] = j;
			sz_[j] += sz_[i];
		}
		else
		{
			id_[j] = i;
			sz_[i] += sz_[j];
		}
		--count_;
	}
private:
	vector<int> id_;
	vector<int> sz_;
	int count_;
};

class Solution_1 {
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		WeightedQuickUnionWithCompressUF uf(edges.size() + 1);		// 输入的边从1开始的
		for (auto &edge : edges)
		{
			auto v = edge.front(), w = edge.back();
			auto last_count = uf.count();
			uf.union_point(v, w);
			if (last_count == uf.count())							// 没有减少连通块，说明成环
				return edge;
		}
		return vector<int>();
	}
};

using Solution = Solution_1;

int main()
{
	vector<vector<int>> edges{{2, 7}, {7, 8}, {3, 6}, {2, 5}, {6, 8}, {4, 8}, {2, 8}, {1, 8}, {7, 10}, {3, 9}};
	Solution s;
	auto ret = s.findRedundantConnection(edges);
	return 0;
}