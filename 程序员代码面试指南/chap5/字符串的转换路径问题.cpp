#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iostream>
using namespace std;

vector<string> getNexts(string& word, unordered_set<string>& dicts)
{
	vector<string> res;
	for (int i = 0; i != word.size(); ++i)
	{
		for (char c = 'a'; c <= 'z'; ++c)
		{
			if (word[i] != c)
			{
				char temp = word[i];
				word[i] = c;
				if (dicts.find(word) != dicts.end())
				{
					res.push_back(word);
				}
				word[i] = temp;
			}
		}
	}
	return res;
}

unordered_map<string, vector<string>> getNexts(vector<string>& words)
{
	unordered_set<string> dicts(words.begin(), words.end());
	unordered_map<string, vector<string>> nexts;
	for (auto& word : words)
	{
		nexts[word] = getNexts(word, dicts);
	}
	return nexts;
}

unordered_map<string, int> getDistances(const string& start, unordered_map<string, vector<string>> nexts)
{
	unordered_map<string, int> distances{ {start, 0} };
	queue<string> queue;
	queue.push(start);
	while (!queue.empty())
	{
		auto node = queue.front();
		queue.pop();
		for (string& str : nexts[node])
		{
			if (distances.find(str) == distances.end())
			{
				queue.push(str);
				distances[str] = distances[node] + 1;
			}
		}
	}
	return distances;
}

void getShortestPath(const string& cur, const string& to,
	unordered_map<string, int> distances, unordered_map<string, vector<string>> nexts,
	vector<string>& path, vector<vector<string>>& res)
{
	path.push_back(cur);
	if (cur == to)
		res.push_back(path);
	else
	{
		for (auto& next : nexts[cur])
		{
			if (distances[next] - distances[cur] == 1)
				getShortestPath(next, to, distances, nexts, path, res);
		}
	}
	path.pop_back();
}

vector<vector<string>> findMinPaths(const string& start, const string& to, vector<string>& words)
{
	words.push_back(start);
	auto nexts = getNexts(words);
	auto distances = getDistances(start, nexts);
	vector<vector<string>> minPaths;
	vector<string> path;
	getShortestPath(start, to, distances, nexts, path, minPaths);
	return minPaths;
}

int main()
{
	vector<string> list = { "cab", "acc", "cbc", "ccc", "cac", "cbb", "aab", "abb" };
	auto paths = findMinPaths("abc", "cab", list);
	for (auto& path : paths)
	{
		for (auto& node : path)
		{
			cout << node << " ";
		}
		cout << endl;
	}
	return 0;
}