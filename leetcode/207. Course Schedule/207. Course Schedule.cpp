#include <vector>
using std::vector;
#include <utility>
using std::pair;
#include <stack>
using std::stack;

// ���л����޷���ɣ�ֻ�жϻ�������Ҫ�ز�����
class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		if (prerequisites.empty())
			return true;
		// ����ͼ��A�ڵ�ָ��B�ڵ㡣˵��A��B���Ⱦ�������
		vector<vector<int>> G(numCourses);
		for (auto p : prerequisites)	// ��������Ϊͼ
		{
			G[p.second].push_back(p.first);
		}
		marked = vector<bool>(G.size(), false);
		on_stack = vector<bool>(G.size(), false);
		for (int v = 0; v != G.size(); ++v)
			if (!marked[v])
				dfs(G, v);
		return !cycle;
	}
private:
	vector<bool> marked;
	vector<bool> on_stack;
	bool cycle = false;
	void dfs(const vector<vector<int>> &G, int v)
	{
		marked[v] = true;
		on_stack[v] = true;
		for (auto w : G[v])
			if (cycle)
				return;
			else if (!marked[w])
				dfs(G, w);
			else if (on_stack[w])
			{
				cycle = true;
				return;
			}
		on_stack[v] = false;
	}
};

int main()
{
	vector<pair<int, int>> vp{ {0, 1}, {1, 0} };
	Solution s;
	s.canFinish(2, vp);
	return 0;
}