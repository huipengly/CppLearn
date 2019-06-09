#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

void allCandsMinusOne(unordered_map<int, int>& cands)
{
	vector<int> removes;
	for (auto& cand : cands)
	{
		if (cand.second == 1)
			removes.push_back(cand.first);
		else
			--cand.second;
	}
	for (int remove : removes)
		cands.erase(remove);
}

// 这里实现方式和书上不同，直接在cands的map里计数。
void getReals(const vector<int>& nums, unordered_map<int, int>& cands)
{
	for (auto& cand : cands)
		cand.second = 0;
	for (int num : nums)
	{
		if (cands.find(num) != cands.end())
			++cands[num];
	}
}

vector<int> printKMajor(const vector<int>& nums, int k)
{
	unordered_map<int, int> cands;
	for (int num : nums)
	{
		if (cands.find(num) != cands.end())
			++cands[num];
		else
		{
			if (cands.size() == k - 1)
				allCandsMinusOne(cands);
			else
				cands[num] = 1;
		}
	}
	getReals(nums, cands);
	vector<int> res;
	res.reserve(cands.size());
	for (auto& cand : cands)
	{
		if (cand.second > nums.size() / k)
			res.push_back(cand.first);
	}
	return res;
}

int main()
{
	auto ret = printKMajor({ 1,1,1,3,3,2,2,2 }, 3);
	for (auto i : ret)
		cout << i << " ";
	cout << endl;
	return 0;
}