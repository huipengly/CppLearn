/*
����ͼ�Ļ������Ǹ���������Ҫ����ı߲�һ�����������𣬷�Ϊ�������.
ʹ������ͼ���Ƿ��л���Ȼ��������ͼ�ϲ��������ı�

1. �ҵ������������ڵ�������ӽڵ㡣�ҵ���ת3���Ҳ�����ת2
2. ���Ҳ�������������ͼ�ķ�����
3. ʹ�������edges����union�ڵ㣬�����������ڵ�������ӽڵ�ı߲����ӡ�
	���ڵ��Ƿ���ӽڵ���ͨ������ͨ˵���б��·������ͨ�����л���˵��ֻ��һ�����ڵ��ڻ��Ϊcase2��ɾ���˱ߡ�
	��һֱ����ͨ��˵�����������ڵ���ڻ��ɾ����һ�����Ӹ��ڵ�ı�

ʹ��ѹ����Ȩunion��union��find������Ϊ1.����O(n)

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

class Solution {
public:
	vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
		vector<vector<int>> parents;
		parents.resize(edges.size() + 1);
		int special_child = -1;
		// �ҵ����������ڵ�ĵ�
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
		// �һ�
		if (special_child == -1)										// û��ӵ���������ڵ�ģ�case3
		{
			for (auto &edge : edges)
			{
				auto v = edge.front(), w = edge.back();
				auto last_count = uf.count();
				uf.union_point(v, w);
				if (last_count == uf.count())							// û�м�����ͨ�飬˵���ɻ�
					return edge;
			}
		}
		else
		{
			auto n1 = parents[special_child][0];						// �������ڵ�
			auto n2 = parents[special_child][1];
			for (auto &edge : edges)
			{
				auto v = edge.front(), w = edge.back();
				if ((v == n1 || v == n2) && w == special_child)			// �������ڵ�����߲�������ĳ�����ڵ㻹�ܺ��ӽڵ���������˵��Ϊcase2������Ϊcase1
					continue;
				uf.union_point(v, w);
				if (uf.find(special_child) == uf.find(n1))
					return vector<int>{n1, special_child};
				else if (uf.find(special_child) == uf.find(n2))
					return vector<int>{n2, special_child};
			}
			return vector<int>{n2, special_child};						// �����ڵ㶼��cycle��.case1
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