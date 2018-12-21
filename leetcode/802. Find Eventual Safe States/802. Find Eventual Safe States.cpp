/*
* 这个问题就是找不在环上的点。
* 
* 1. 构造一个反向图rG，构造一个queue，然后将G中的eventually safty节点加入队列，
*	然后每回取一个点e，在反向图rG中e能到的邻接点，然后从G中删除这条路，然后将G中新最终安全点加入队列，重复直到队列为空。加入到队列里的点就是最终安全点
* 2. dfs黑白灰确定点是否在环上
* 
* 都是time O(n+E), space O(n)
* 
* */

#include <vector>
using std::vector;
#include <queue>
using std::queue;
#include <algorithm>
using std::find; using std::sort;

class Solution_1 {
public:
	vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
		vector<int> eventual_safa_nodes;
		vector<vector<int>> reverse_graph(graph.size());
		queue<int> safe_queue;

		for (int i = 0; i != graph.size(); ++i)
		{
			for (auto v : graph[i])		// 反转图
			{
				reverse_graph[v].push_back(i);
			}
			if (graph[i].empty())		// 没有出度的一定为安全点
			{
				safe_queue.push(i);
				eventual_safa_nodes.push_back(i);
			}
		}

		while (!safe_queue.empty())
		{
			auto node = safe_queue.front(); safe_queue.pop();
			for (auto w : reverse_graph[node])	// 删除G中w到node的路
			{
				auto it_node = find(graph[w].begin(), graph[w].end(), node);
				graph[w].erase(it_node);
				if(graph[w].empty())			// 如果w变为安全节点，则添加入队列
				{
					safe_queue.push(w);
					eventual_safa_nodes.push_back(w);
				}
			}
		}

		sort(eventual_safa_nodes.begin(), eventual_safa_nodes.end());		// 输出需要有序
		return eventual_safa_nodes;
	}
};

class Solution_2 {
public:
	vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
		vector<int> eventual_safa_nodes;
		color = vector<COLOR>(graph.size(), white);
		for (int s = 0; s != graph.size(); ++s)
			if (dfs(graph, s))
				eventual_safa_nodes.push_back(s);

		return eventual_safa_nodes;
	}
private:
	enum COLOR { white, gray, black };
	vector<COLOR> color;
	bool dfs(vector<vector<int>> &G, int v)
	{
		if (color[v] != white)	// 如果点已经有颜色，则直接根据颜色判断
			return color[v] == black;

		color[v] = gray;
		for (auto w : G[v])
		{
			if (color[v] == black)
			{
				return true;
			}
			else
			{
				if (color[w] == gray || !dfs(G, w))
				{
					return false;
				}
			}
		}

		color[v] = black;		// 能返回说明就不在环里
		return true;
	}
};

using Solution = Solution_2;

int main()
{
	Solution s;
	vector<vector<int>> graph{{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
	auto ret = s.eventualSafeNodes(graph);
	return 0;
}