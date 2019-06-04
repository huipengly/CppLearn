#include <vector>
#include <iostream>
#include <string>
#include <memory>
using namespace std;
class Trie {
public:
	/** Initialize your data structure here. */
	Trie() : root(make_shared<TrieNode>()) {}

	/** Inserts a word into the trie. */
	void insert(string word) {
		if (word.empty())
			return;
		auto node = root;
		++node->path;
		for (int i = 0; i != word.size(); ++i)
		{
			int index = word[i] - 'a';
			if (node->map[index] == nullptr)
			{
				node->map[index] = make_shared<TrieNode>();
			}
			node = node->map[index];
			++node->path;
		}
		++node->end;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		auto node = root;
		for (int i = 0; i != word.size(); ++i)
		{
			int index = word[i] - 'a';
			if (node->map[index] == nullptr)
			{
				return false;
			}
			node = node->map[index];
		}
		return node->end != 0;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		auto node = root;
		for (int i = 0; i != prefix.size(); ++i)
		{
			int index = prefix[i] - 'a';
			if (node->map[index] == nullptr)
				return 0;
			node = node->map[index];
		}
		return node->path != 0;
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
	Trie* trie = new Trie();

	trie->insert("apple");
	cout << trie->search("apple") << endl;   // returns true
	cout << trie->search("app") << endl;     // returns false
	cout << trie->startsWith("app") << endl; // returns true
	trie->insert("app");
	cout << trie->search("app") << endl;     // returns true
	return 0;
}