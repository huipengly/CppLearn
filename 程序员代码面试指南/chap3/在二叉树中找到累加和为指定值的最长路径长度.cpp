#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;
struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int preOrder(TreeNode* head, int k, int sum, int level, int maxLen, unordered_map<int, int>& map)
{
	if (head == nullptr)
		return maxLen;

	sum += head->val;
	if (map.find(sum - k) != map.end())
	{
		maxLen = std::max(level - map[sum - k], maxLen);
	}

	if (map.find(sum) == map.end())
		map[sum] = level;

	maxLen = preOrder(head->left, k, sum, level + 1, maxLen, map);
	maxLen = preOrder(head->right, k, sum, level + 1, maxLen, map);

	if (map[sum] == level)
		map.erase(sum);
	return maxLen;
}

int getMaxLengthInTree(TreeNode* head, int k)
{
	unordered_map<int, int> map;
	map[0] = 0;
	return preOrder(head, k, 0, 1, 0, map);
}

int main()
{
	TreeNode* head = new TreeNode(-3);
	head->left = new TreeNode(3);
	head->left->left = new TreeNode(1);
	head->left->right = new TreeNode(0);
	head->left->right->left = new TreeNode(1);
	head->left->right->right = new TreeNode(6);

	head->right = new TreeNode(-9);
	head->right->left = new TreeNode(2);
	head->right->right = new TreeNode(1);
	cout << getMaxLengthInTree(head, 6) << endl;
	cout << getMaxLengthInTree(head, -9) << endl;

	return 0;
}