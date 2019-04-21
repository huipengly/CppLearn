#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int N = envelopes.size();
        if (N < 2)
            return N;

        sort(envelopes.begin(), envelopes.end(),
                [](const pair<int, int> &lhs, const pair<int, int> &rhs){ return lhs.second > rhs.second; });
        stable_sort(envelopes.begin(), envelopes.end(),
             [](const pair<int, int> &lhs, const pair<int, int> &rhs){ return lhs.first < rhs.first; });

        vector<int> dp(N);
        vector<int> ends(N);     // ends[i]，表示索引i长度的子串中，末尾最小的元素值。
        dp[0] = 1;
        ends[0] = envelopes[0].second;
        int right = 0;
        int lo = 0, hi = 0, mid = 0;
        for (int i = 1; i != N; ++i)
        {
            lo = 0;
            hi = right;
            while (lo <= hi)
            {
                mid = lo + (hi - lo) / 2;
                if (ends[mid] < envelopes[i].second)
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
            right = max(right, lo);
            ends[lo] = envelopes[i].second;
            dp[i] = lo + 1;
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main()
{
    vector<pair<int, int>> env{{4,19},{6,16},{7,19},{9,2},{2,14},{9,8},{6,7},{9,19},{6,3},{5,1},{7,14},{20,2},{19,11},{10,12},{16,20},{12,4},{7,16},{10,10},{10,11},{18,1}};
    Solution s;
    auto ret = s.maxEnvelopes(env);
    return 0;
}