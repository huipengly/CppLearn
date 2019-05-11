#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.size() != t.size())
			return false;
		vector<int> map(26, 0);
		for (auto c : s)
			++map[c - 'a'];
		for (auto c : t)
			if (--map[c - 'a'] < 0)
				return false;
		return true;
	}
};
// 用stl的map，在leetcode里因为只有小写字母，所以可以用一个大小为26的char数组
class Solution_stl {
public:
	bool isAnagram(string s, string t) {
		if (s.size() != t.size())
			return false;
		unordered_map<char, int> map;
		for (auto c : s)
		{
			if (map.find(c) == map.end())
				map[c] = 0;
			++map[c];
		}
		for (auto c : t)
		{
			if (map.find(c) == map.end())
				return false;
			--map[c];
			if (map[c] == 0)
				map.erase(c);
		}
		return true;
	}
};