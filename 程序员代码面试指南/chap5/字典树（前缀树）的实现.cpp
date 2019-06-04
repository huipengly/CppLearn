#include <memory>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Trie {
public:
	Trie() : root(make_shared<TrieNode>()) {}
	void insert(const string& str)
	{
		if (str.empty())
			return;
		auto node = root;
		++node->path;
		for (int i = 0; i != str.size(); ++i)
		{
			int index = str[i] - 'a';
			if (node->map[index] == nullptr)
			{
				node->map[index] = make_shared<TrieNode>();
			}
			node = node->map[index];
			++node->path;
		}
		++node->end;
	}
	bool search(const string& str)
	{
		auto node = root;
		for (int i = 0; i != str.size(); ++i)
		{
			int index = str[i] - 'a';
			if (node->map[index] == nullptr)
			{
				return false;
			}
			node = node->map[index];
		}
		return node->end != 0;
	}
	void del(const string& str)
	{
		if (search(str))
		{
			auto node = root;
			--node->path;
			for (int i = 0; i != str.size(); ++i)
			{
				int index = str[i] - 'a';
				if (--node->map[index]->path == 0)
				{
					node->map[index] = nullptr;
					break;
				}
				node = node->map[index];
			}
			--node->end;
		}
	}
	int prefixNumbers(const string& str)
	{
		auto node = root;
		for (int i = 0; i != str.size(); ++i)
		{
			int index = str[i] - 'a';
			if (node->map[index] == nullptr)
				return 0;
			node = node->map[index];
		}
		return node->path;
	}

private:
	struct TrieNode {
		int path;
		int end;
		vector<shared_ptr<TrieNode>> map;
		TrieNode() : path(0), end(0), map(vector<shared_ptr<TrieNode>>(26, nullptr)) {}
	};
	shared_ptr<TrieNode> root;
};

int main()
{
	Trie trie;
	trie.insert("abc");
	trie.insert("abcd");
	trie.insert("abd");
	trie.insert("b");
	trie.insert("bcd");
	trie.insert("efg");
	trie.insert("hik");
	cout << trie.search("b") << endl;
	trie.del("b");
	cout << trie.search("b") << endl;
	cout << trie.search("ab") << endl;
	cout << trie.prefixNumbers("ab") << endl;
	return 0;
}