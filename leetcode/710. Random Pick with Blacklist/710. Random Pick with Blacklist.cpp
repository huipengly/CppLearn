#include <vector>
using std::vector;
#include <random>
using std::uniform_int_distribution; using std::default_random_engine;
#include <algorithm>
using std::sort; using std::upper_bound;
#include <ctime>
using std::time;

class Solution {
public:
	uniform_int_distribution<unsigned> u;
	default_random_engine e;
	vector<int> black_list;
	Solution(int N, vector<int> blacklist) : e(time(0)), u(0, N - blacklist.size() - 1) {
		black_list = blacklist;
		sort(black_list.begin(), black_list.end());
		for (int i = 0; i < black_list.size(); i++)
			black_list[i] -= i;
	}

	int pick() {
		int rand = u(e);
		auto it = upper_bound(black_list.begin(), black_list.end(), rand) - 1;
		return rand + (it - black_list.begin()) + 1;
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */
 
int main()
{
	int n = 4;
	vector<int> v{ 0, 1, 2 };
	Solution s(n, v);
	s.pick();
	return 0;
}