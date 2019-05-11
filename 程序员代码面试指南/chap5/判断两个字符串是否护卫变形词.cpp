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
// ��stl��map����leetcode����Ϊֻ��Сд��ĸ�����Կ�����һ����СΪ26��char����
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