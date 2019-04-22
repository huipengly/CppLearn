// 牛客 XOR
// https://www.nowcoder.com/questionTerminal/7cffea0c097c4337821ab3ba25447c1c
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int mostXOR(vector<int> &arr)
{
    if (arr.empty())
        return 0;

    unordered_map<int, int> map;
    vector<int> dp(arr.size(), 0);

    int eor = arr[0];
    map[0] = -1;
    map[eor] = 0;
    dp[0] = arr[0] == 0 ? 1 : 0;
    for (int i = 1; i != arr.size(); ++i)
    {
        eor ^= arr[i];
        if (map.find(eor) != map.end())
        {
            int preEorIndex = map[eor];
            dp[i] = preEorIndex == -1 ? 1 : (dp[preEorIndex] + 1);
        }
        dp[i] = std::max(dp[i - 1], dp[i]);
        map[eor] = i;
    }
    return dp.back();
}

int main()
{
    int N;
    cin >> N;
    vector<int> arr(N, 0);
    for (auto &i : arr)
        cin >> i;
    cout << mostXOR(arr) << endl;
    return 0;
}