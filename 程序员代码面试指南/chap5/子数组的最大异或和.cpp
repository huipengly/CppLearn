#include <memory>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int maxXorSubarray1(const vector<int>& arr)
{
	if (arr.empty())
		return 0;
	vector<int> eor(arr.size(), 0);
	int max = INT_MIN;
	eor[0] = arr[0];
	for (int i = 1; i != arr.size(); ++i)
		eor[i] = eor[i - 1] ^ arr[i];
	for (int j = 0; j != arr.size(); ++j)
	{
		for (int i = 0; i <= j; ++i)
		{
			max = std::max(max, i == 0 ? eor[i] : eor[j] ^ eor[i - 1]); 
		}
	}
	return max;
}

class Trie {
public:
	Trie() : root(make_shared<TrieNode>()) {}
	void add1(int number)
	{
		int aux = 1 << 31;
		auto node = root;
		for (int i = 0; i != 32; ++i)
		{
			int index = ((number & aux) != 0) ? 1 : 0;
			aux >>= 1;
			if (node->next[index] == nullptr)
			{
				node->next[index] = make_shared<TrieNode>();
			}
			node = node->next[index];
		}
	}

	void add(int number)
	{
		auto node = root;
		for (int move = 31; move >= 0; ++move)
		{
			int path = (number >> move) & 1;
			if (node->next[path] == nullptr)
			{
				node->next[path] = make_shared<TrieNode>();
			}
			node = node->next[path];
		}
	}

	int maxXor1(int eorj)
	{
		auto node = root;
		int aux = 1 << 31;
		int index = ((eorj & aux) != 0) ? 1 : 0;	// 第一位符号位要找异或为0的
		aux >>= 1;
		bool pos = true;
		int max = 0;
		if (node->next[index] == nullptr)
		{
			index = index == 0 ? 1 : 0;
			pos = false;
		}
		node = node->next[index];
		for (int i = 1; i != 32; ++i)
		{
			int index = ((eorj & aux) != 0 && pos == true) ? 0 : 1;	// 如果符号位为正，则找异或为1的。否则找异或为0的
			if (node->next[index] == nullptr)
			{
				index = index == 0 ? 1 : 0;
			}
			max <<= 1;
			max += index;
			node = node->next[index];
		}
		return eorj ^ max;
	}
	int maxXor(int eorj)
	{
		auto node = root;
		int res = 0;
		for (int move = 31; move >= 0; --move)
		{
			int path = (eorj >> move) & 1;
			int best = move == 31 ? path : (path ^ 1);
			best = node->next[path] != nullptr ? best : (best ^ 1);
			res |= (path ^ best) << move;
			node = node->next[best];
		}
		return res;
	}
private:
	struct TrieNode {
		vector<shared_ptr<TrieNode>> next;
		TrieNode() : next(vector<shared_ptr<TrieNode>>(2, nullptr)) {}
	};
	shared_ptr<TrieNode> root;
};

int maxXorSubarray2(const vector<int>& arr)
{
	Trie trie;
	trie.add(0);
	int eor = 0;
	int max = INT_MIN;
	for (int i : arr)
	{
		eor ^= i;
		max = std::max(max, trie.maxXor(eor));
		trie.add(eor);
	}
	return max;
}

int main()
{
	//Trie trie;
	//trie.add(0);
	//trie.add(INT_MAX);
	//cout << trie.maxXor(-1) << endl;
	cout << (-1 ^ -1) << endl;
	return 0;
}