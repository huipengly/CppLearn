/*
有向图的环还是那个环，但是要拆掉的边不一样，不能随便拆，分为三种情况.
使用无向图找是否有环，然后在有向图上拆掉有问题的边

1. 找到存在两个父节点的特殊子节点。找到跳转3，找不到跳转2
2. 若找不到，则按照无向图的方法做
3. 使用输入的edges不断union节点，除了两个父节点和特殊子节点的边不连接。
	父节点是否和子节点连通，若连通说明有别的路可以连通，则有环，说明只有一个父节点在环里，为case2。删除此边。
	若一直不连通，说明有两个父节点均在环里。删除后一个连接父节点的边

使用压缩加权union，union和find都可认为1.所以O(n)

There are 3 cases:

1.No loop, but there is one node who has 2 parents.
2.A loop, and there is one node who has 2 parents, that node must be inside the loop.
3.A loop, and every node has only 1 parent.
Case 1 : e.g.[[1, 2], [1, 3], [2, 3]], node 3 has 2 parents([1, 3] and [2, 3]).Return the edge that occurs last that is, return[2, 3].
Case 2 : e.g.[[1, 2], [2, 3], [3, 1], [4, 1]], { 1->2->3->1 } is a loop, node 1 has 2 parents([4, 1] and [3, 1]).Return the edge that is inside the loop, that is, return[3, 1].
Case 3 : e.g.[[1, 2], [2, 3], [3, 1], [1, 4]], { 1->2->3->1 } is a loop, you can remove any edge in a loop, the graph is still valid.Thus, return the one that occurs last, that is, return[3, 1].
*/

#include <vector>
using std::vector;


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

class Solution {
public:
	vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
		vector<vector<int>> parents;
		parents.resize(edges.size() + 1);
		int special_child = -1;
		// 找到有两个父节点的点
		for (auto &edge : edges)
		{
			auto child = edge.back(), parent = edge.front();
			parents[child].push_back(parent);
			if (parents[child].size() == 2)
			{
				special_child = child;
				break;
			}
		}

		WeightedQuickUnionWithCompressUF uf(edges.size() + 1);
		// 找环
		if (special_child == -1)										// 没有拥有两个父节点的，case3
		{
			for (auto &edge : edges)
			{
				auto v = edge.front(), w = edge.back();
				auto last_count = uf.count();
				uf.union_point(v, w);
				if (last_count == uf.count())							// 没有减少连通块，说明成环
					return edge;
			}
		}
		else
		{
			auto n1 = parents[special_child][0];						// 两个父节点
			auto n2 = parents[special_child][1];
			for (auto &edge : edges)
			{
				auto v = edge.front(), w = edge.back();
				if ((v == n1 || v == n2) && w == special_child)			// 两个父节点的连线不连，若某个父节点还能和子节点相连，则说明为case2。否则为case1
					continue;
				uf.union_point(v, w);
				if (uf.find(special_child) == uf.find(n1))
					return vector<int>{n1, special_child};
				else if (uf.find(special_child) == uf.find(n2))
					return vector<int>{n2, special_child};
			}
			return vector<int>{n2, special_child};						// 两个节点都在cycle里.case1
		}
	}
};

int main()
{
	vector<vector<int>> edges{{1, 2}, {1, 3}, {2, 3}};
	Solution s;
	auto ret = s.findRedundantDirectedConnection(edges);
	return 0;
}