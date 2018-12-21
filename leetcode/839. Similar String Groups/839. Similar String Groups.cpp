#include <vector>
using std::vector;
#include <string>
using std::string;

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
	int numSimilarGroups(vector<string>& A) {
		WeightedQuickUnionWithCompressUF uf(A.size());
		for (int i = 0; i != A.size(); ++i)
			for (int j = i + 1; j != A.size(); ++j)
			{
				if (similar(A[i], A[j]))
				{
					uf.union_point(i, j);
				}
			}
		return uf.count();
	}
private:
	bool similar(const string &s1, const string &s2)
	{
		int error_bit = 0;
		char c1, c2;
		for (int i = 0; i != s1.size(); ++i)
		{
			if (s1[i] != s2[i])
			{
				++error_bit;
				if (error_bit == 1)
				{
					c1 = s1[i];
					c2 = s2[i];
				}
				else if (error_bit == 2)
				{
					if (c1 != s2[i] || c2 != s1[i])
						return false;
				}
				else if (error_bit > 2)
					return false;
			}
		}
		return error_bit == 2 || error_bit == 0;
	}
};

int main()
{
	Solution s;
	vector<string> vs{"aaaa", "aaaa", "aaaa", "aaaa"};
	auto ret = s.numSimilarGroups(vs);
	return 0;
}