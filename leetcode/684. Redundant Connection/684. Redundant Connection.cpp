#include <vector>
using std::vector;

// �����δ����һ������ͼ���ҵ�ʹ���ͼ�ɻ��ı�
// 1. union find.ÿ�����������㣬��countû���٣�˵���ɻ�
// 2. dfs 
//	2.1 ��������ͼ��Ѱ��ͼ�еĻ����ҵ�vector�����һ���ߡ�
//	2.2 ÿ����һ���߾ͼ��һ��ͼ�Ƿ�ɻ������ɻ����������ߡ�		// �ܷ�ʱ
// 3. ɾ��ͼ�е�Ҷ�����޷�ɾ�������ǻ�

// ʵ����1��2.2

class Solution_2_2 {
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		G.resize(edges.size());
		for (auto edge : edges)
		{
			auto v = edge.front() - 1, w = edge.back() - 1;	// �����1��ʼ������Ϊ��0��ʼ
			G[v].push_back(w);
			G[w].push_back(v);
			marked = vector<bool>(G.size(), false);
			for (int s = 0; s != G.size(); ++s)				// ͼ�ʼ�����ǲ���ͨ��
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
			id_[p] = id_[id_[p]];	// Ȩ��ѹ��������ǰ�����ӵ��丸����һ���ϡ�
			p = id_[p];
		}
		return p;
	}

	void union_point(int p, int q)
	{
		int i = find(p);
		int j = find(q);
		if (i == j) return;			// p��qͬ��������Ҫ�ϲ�
		if (sz_[i] < sz_[j])		// ��С���ϲ��������ϣ������´�����sz������count
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
		WeightedQuickUnionWithCompressUF uf(edges.size() + 1);		// ����ıߴ�1��ʼ��
		for (auto &edge : edges)
		{
			auto v = edge.front(), w = edge.back();
			auto last_count = uf.count();
			uf.union_point(v, w);
			if (last_count == uf.count())							// û�м�����ͨ�飬˵���ɻ�
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