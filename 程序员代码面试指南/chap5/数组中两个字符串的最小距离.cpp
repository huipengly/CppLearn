#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int minDistance(const vector<string>& strs, const string& str1, const string& str2)
{
	if (strs.empty() || str1.empty() || str2.empty())
		return -1;
	if (str1 == str2)
		return 0;
	int last1 = -1, last2 = -1;
	int min = INT_MAX;
	for (int i = 0; i != strs.size(); ++i)
	{
		if (strs[i] == str1)
		{
			min = std::min(min, last2 == -1 ? INT_MAX : i - last2);
			last1 = i;
		}
		else if (strs[i] == str2)
		{
			min = std::min(min, last1 == -1 ? INT_MAX : i - last1);
			last2 = i;
		}
	}
	return min == INT_MAX ? -1 : min;
}

class Record{
public:
	Record(const vector<string>& strs)
	{
		unordered_map<string, int> indexMap;
		for (int i = 0; i != strs.size(); ++i)
		{
			update(indexMap, strs[i], i);
			indexMap[strs[i]] = i;
		}
	}
	int minDistance(const string& str1, const string& str2)
	{
		if (str1.empty() || str2.empty())
			return -1;
		if (str1 == str2)
			return 0;
		if (record.find(str1) == record.end() || record[str1].find(str2) == record[str1].end())
			return -1;
		return record[str1][str2];
	}
private:
	unordered_map<string, unordered_map<string, int>> record;
	void update(const unordered_map<string, int>& indexMap, const string& str, int i)
	{
		for (auto& indexPair : indexMap)
		{
			auto str1 = indexPair.first;
			auto index = indexPair.second;
			if (str1 != str)
			{
				if (record.find(str1) == record.end())
					record[str1][str] = i - index;
				else if (record[str1].find(str) == record[str1].end())
					record[str1][str] = i - index;
				else
					record[str1][str] = std::min(record[str1][str], i - index);

				if (record.find(str) == record.end())
					record[str][str1] = i - index;
				else if (record[str].find(str1) == record[str].end())
					record[str][str1] = i - index;
				else
					record[str][str1] = std::min(record[str][str1], i - index);
				
				// 下面的方法是错的，因为不知道record[str1][str]是否存在
				//record[str1][str] = record.find(str1) == record.end() ? 
				//						(i - index) : min(record[str1][str], i - index);
				//record[str][str1] = record.find(str) == record.end() ?
				//						(i - index) : min(record[str][str1], i - index);
			}
		}
	}
};

int main()
{
	cout << minDistance({ "1", "3", "3", "3", "2", "3", "1" }, "1", "2") << endl;
	cout << minDistance({ "CD" }, "CD", "AB") << endl;
	Record record({ "1", "3", "3", "3", "2", "3", "1" });
	cout << record.minDistance("1", "2") << endl;
	return 0;
}