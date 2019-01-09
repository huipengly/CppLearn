// 这里没有用到
#include <vector>
#include <numeric>

class WeightedQuickUnionWithCompressUF {
public:
	WeightedQuickUnionWithCompressUF(const int N) : count_(N)
	{
		id_ = std::vector<int>(count_);
		std::iota(id_.begin(), id_.end(), 0);
		sz_ = std::vector<int>(count_, 1);
	}

	int count() const { return count_; }
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
		auto i = find(p);
		auto j = find(q);
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
	std::vector<int> id_;
	std::vector<int> sz_;
	int count_;
};
