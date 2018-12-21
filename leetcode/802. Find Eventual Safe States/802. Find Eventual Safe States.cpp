/*
* �����������Ҳ��ڻ��ϵĵ㡣
* 
* 1. ����һ������ͼrG������һ��queue��Ȼ��G�е�eventually safty�ڵ������У�
*	Ȼ��ÿ��ȡһ����e���ڷ���ͼrG��e�ܵ����ڽӵ㣬Ȼ���G��ɾ������·��Ȼ��G�������հ�ȫ�������У��ظ�ֱ������Ϊ�ա����뵽������ĵ�������հ�ȫ��
* 2. dfs�ڰ׻�ȷ�����Ƿ��ڻ���
* 
* ����time O(n+E), space O(n)
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
			for (auto v : graph[i])		// ��תͼ
			{
				reverse_graph[v].push_back(i);
			}
			if (graph[i].empty())		// û�г��ȵ�һ��Ϊ��ȫ��
			{
				safe_queue.push(i);
				eventual_safa_nodes.push_back(i);
			}
		}

		while (!safe_queue.empty())
		{
			auto node = safe_queue.front(); safe_queue.pop();
			for (auto w : reverse_graph[node])	// ɾ��G��w��node��·
			{
				auto it_node = find(graph[w].begin(), graph[w].end(), node);
				graph[w].erase(it_node);
				if(graph[w].empty())			// ���w��Ϊ��ȫ�ڵ㣬����������
				{
					safe_queue.push(w);
					eventual_safa_nodes.push_back(w);
				}
			}
		}

		sort(eventual_safa_nodes.begin(), eventual_safa_nodes.end());		// �����Ҫ����
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
		if (color[v] != white)	// ������Ѿ�����ɫ����ֱ�Ӹ�����ɫ�ж�
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

		color[v] = black;		// �ܷ���˵���Ͳ��ڻ���
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