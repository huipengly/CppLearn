#include <vector>
using std::vector;
#include <algorithm>
using std::max_element;
#include <unordered_map>
using std::unordered_map;
#include <queue>
using std::queue;

// ��Ȩ��ͼ����̱���

class Solution {
public:
	// ����1 bfs����������ʱ�����
	int networkDelayTime(vector<vector<int>>& times, int N, int K) {
		if (times.empty())
		{
			return 0;
		}
		vector<unordered_map<int, int>> G;
		G.resize(N);
		marked = vector<bool>(N, false);
		delay_time = vector<int>(N, 1e10);
		for (auto time : times)
		{
			G[time[0] - 1][time[1] - 1] = time[2];	// �������Ϊ0��n-1
		}
		bfs(G, K - 1);
		for (auto mark : marked)
			if (!mark) return -1;
		return *max_element(delay_time.begin(), delay_time.end());
	}
private:
	vector<bool> marked;
	vector<int> delay_time;
	vector<int> edge;
	void bfs(const vector<unordered_map<int, int>> &G, int k)
	{
		queue<int> queue;
		delay_time[k] = 0;
		marked[k] = true;
		queue.push(k);
		while (!queue.empty())
		{
			int v = queue.front();
			queue.pop();
			for (auto w : G[v])
			{
				if (delay_time[w.first] > delay_time[v] + (G[v]).at(w.first))
				{
					delay_time[w.first] = delay_time[v] + (G[v]).at(w.first);	// ��v��ʱ�� + v��w��ʱ��
					marked[w.first] = true;
					queue.push(w.first);
				}
			}
		}
	}
};

int main()
{
	Solution s;
	vector<vector<int>> g{ {1, 2, 1}, {2, 3, 2}, {1, 3, 4} };
	s.networkDelayTime(g, 3, 1);
	return 0;
}