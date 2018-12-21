#include <vector>
using std::vector;
#include <set>
using std::multiset; using std::set;
#include <string>
using std::string;
#include <utility>
using std::pair;
#include <unordered_map>
using std::unordered_map;

// �����һ������һ��ͨ·������˵ֻ��Ҫdfs�������У�����Ҫ���ǻ��˵����⡣
// �ַ����ȼ�������ʹ��set���
// ����ʹ��multiset����Ϊ�п��ܶ���A��B

class Solution {
public:
	vector<string> findItinerary(vector<pair<string, string>> tickets) {
		unordered_map<string, multiset<string>> G;	// ����Ҫ����ĵط�������map
		for (auto &ticket : tickets)
		{
			auto &v = ticket.first, &w = ticket.second;
			G[v].insert(w);
		}
		dfs(G, "JFK");
		return vector<string>(itinerary.rbegin(), itinerary.rend());
	}
private:
	vector<string> itinerary;
	
	void dfs(unordered_map<string, multiset<string>> &G, string n)
	{
		while (!G[n].empty())
		{
			auto next = *G[n].begin();
			G[n].erase(G[n].begin());
			dfs(G, next);
		}
		itinerary.push_back(n);
	}
};

int main()
{
	Solution s;
	vector<pair<string, string>> vs{ {"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"} };
	auto i = s.findItinerary(vs);
	return 0;
}