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

// 这道题一定存在一条通路，所以说只需要dfs搜索就行，不需要考虑回退的问题。
// 字符优先级的问题使用set解决
// 这里使用multiset是因为有可能多张A到B

class Solution {
public:
	vector<string> findItinerary(vector<pair<string, string>> tickets) {
		unordered_map<string, multiset<string>> G;	// 不需要排序的地方用无需map
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