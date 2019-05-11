#include <vector>
using namespace std;
struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

int numbersTrees(int n)
{
	if (n < 0)
		return 0;
	else if (n < 2)
		return 1;
	vector<int> numbers(n + 1, 0);
	numbers[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			numbers[i] += numbers[j - 1] * numbers[i - j];
		}
	}
	return numbers[n];
}

vector<TreeNode*> generateTrees(int l, int r)
{
	if (l > r)
		return {nullptr};
	vector<TreeNode*> ret;
	for (int i = l; i <= r; ++i)
	{
		auto listLeft = generateTrees(l, i - 1);
		auto listRight = generateTrees(i + 1, r);
		for (auto& l : listLeft)
		{
			for (auto& r : listRight)
			{
				auto* head = new TreeNode(i);
				head->left = l;
				head->right = r;
				ret.push_back(head);
			}
		}
	}
	return ret;
}

vector<TreeNode*> generateTrees(int n)
{
	return generateTrees(1, n);
}