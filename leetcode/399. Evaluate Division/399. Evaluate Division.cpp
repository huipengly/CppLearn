#include <vector>
using std::vector;
#include <utility>
using std::pair;
#include <string>
using std::string;
#include <unordered_map>
using std::unordered_map;
#include <queue>
using std::priority_queue; using std::queue;
#include <numeric>
using std::iota;

/* 1.bfs。这个不需要用最短路径，因为a/b的值是一个定值，只要有一条路走到了，就是需要返回的值。
 * 2.union-find。
 *	记录每个节点x到其父节点p的距离(x/p)
 *	查询时，先判断两个节点a、b的父节点是否相同。若不同，则没有解。若相同，a/b = a/p / b/p.
**/

class SolutionBfs {
public:
	vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
		unordered_map<string, int> index;
		num = 0;
		vector<double> ret;
		if (queries.empty()) return ret;
		for (int i = 0; i != equations.size(); ++i)
		{
			auto &a = equations[i].first, &b = equations[i].second;
			if (index.find(a) == index.end())
				index[a] = num++;
			if (index.find(b) == index.end())
				index[b] = num++;
			if (G.size() != num)
				G.resize(num);
			G[index[a]][index[b]] = values[i];
			G[index[b]][index[a]] = 1 / values[i];
		}

		for (auto &query : queries)
		{
			unordered_map<string, int>::iterator it_s = index.find(query.first), it_t = index.find(query.second);
			if (it_s == index.end() || it_t == index.end())
			{
				ret.push_back(-1);
			}
			else
			{
				auto s = it_s->second, t = it_t->second;
				bfs(s, t);
				if (!marked[t])
					ret.push_back(-1);
				else
					ret.push_back(distance[t]);
			}
		}
		return ret;
	}
private:
	vector<unordered_map<int, double>> G;
	vector<bool> marked;
	vector<double> distance;
	int num;

	void bfs(int s, int t)
	{
		marked = vector<bool>(num, false);
		distance = vector<double>(num, 1);
		queue<int> queue;
		distance[s] = 1;
		marked[s] = true;
		queue.push(s);
		while (!queue.empty())
		{
			int v = queue.front();
			queue.pop();
			for (auto W : G[v])
			{
				auto w = W.first;
				if (!marked[w])
				{
					distance[w] = distance[v] * (G[v]).at(w);	// 到v的时间 + v到w的时间
					marked[w] = true;
					queue.push(w);
					if (w == t) return;
				}
			}
		}
	}
};

// 这里没有用到
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

/// union方法没写
//class SolutionUF {
//public:
//	vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
//		for (int i = 0; i != equations.size(); ++i)
//		{
//			auto p = equations[i].first, q = equations[i].second;
//			if (map.count(p) == 0)
//				map[p] = new Node;
//			if (map.count(q) == 0)
//				map[q] = new Node;
//			unionNode(map[p], map[q]);
//		}
//	}
//
//private:
//	class Node {
//	public:
//		Node() { parent = this; }
//		int value;
//		Node* parent;
//	};
//	unordered_map<string, Node*> map;
//	void unionNode(Node *p, Node *q)
//	{
//
//	}
//
//};

// leetcode方法
// https://leetcode.com/problems/evaluate-division/discuss/88170/0ms-C++-Union-Find-Solution-EASY-to-UNDERSTAND
class SolutionUF {
	// date: 2016-09-12     location: Santa Clara City Library
public:
	vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
		unordered_map<string, Node*> map;
		vector<double> res;
		for (int i = 0; i < equations.size(); i++) {
			string s1 = equations[i].first, s2 = equations[i].second;
			if (map.count(s1) == 0 && map.count(s2) == 0) {
				map[s1] = new Node();
				map[s2] = new Node();
				map[s1]->value = values[i];
				map[s2]->value = 1;
				map[s1]->parent = map[s2];
			}
			else if (map.count(s1) == 0) {
				map[s1] = new Node();
				map[s1]->value = map[s2]->value * values[i];
				map[s1]->parent = map[s2];
			}
			else if (map.count(s2) == 0) {
				map[s2] = new Node();
				map[s2]->value = map[s1]->value / values[i];
				map[s2]->parent = map[s1];
			}
			else {
				unionNodes(map[s1], map[s2], values[i], map);
			}
		}

		for (auto query : queries) {
			if (map.count(query.first) == 0 || map.count(query.second) == 0 || findParent(map[query.first]) != findParent(map[query.second]))
				res.push_back(-1);
			else
				res.push_back(map[query.first]->value / map[query.second]->value);
		}
		return res;
	}

private:
	struct Node {
		Node* parent;
		double value = 0.0;
		Node() { parent = this; }
	};

	void unionNodes(Node* node1, Node* node2, double num, unordered_map<string, Node*>& map) {
		Node* parent1 = findParent(node1), *parent2 = findParent(node2);
		double ratio = node2->value * num / node1->value;
		for (auto it = map.begin(); it != map.end(); it++)
			if (findParent(it->second) == parent1)
				it->second->value *= ratio;
		parent1->parent = parent2;
	}

	Node* findParent(Node* node) {
		if (node->parent == node)
			return node;
		node->parent = findParent(node->parent);
		return node->parent;
	}
};

using Solution = SolutionBfs;

int main()
{
	vector<pair<string, string>> equations{ {"a", "b"}, {"b", "c"} };
	vector<double> values{ 2.0, 3.0 };
	vector<pair<string, string>> queries{ {"a", "c"}, {"b", "c"}, {"a", "e"}, {"a", "a"}, {"x", "x"} };
	Solution s;
	auto ret = s.calcEquation(equations, values, queries);
	return 0;
}