#include <iostream>
#include <vector>
#include <list>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		if (root == nullptr)
			return {};
		vector<vector<int>> paths;
		vector<int> passed;
		FindPath(root, expectNumber, 0, paths, passed);
		return paths;
	}
private:
	void FindPath(TreeNode *root, int expectNumber, int sum, vector<vector<int>> &paths, vector<int> &passed)
	{
		if (root == nullptr)
			return;
		passed.push_back(root->val);
		sum += root->val;
		if (root->left == nullptr && root->right == nullptr && sum == expectNumber)
		{
			paths.push_back(passed);
		}

		FindPath(root->left, expectNumber, sum, paths, passed);
		FindPath(root->right, expectNumber, sum, paths, passed);

		passed.pop_back();
	}
};

//class Solution {
//public:
//	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
//		if (root == nullptr)
//			return {};
//		auto path_list = FindPathCore(root, expectNumber, 0);
//		vector<vector<int>> path;
//		for (auto it = path_list.begin(); it != path_list.end(); ++it)
//			path.push_back(vector<int>(it->begin(), it->end()));
//		return path;
//	}
//private:
//	vector<list<int>> FindPathCore(TreeNode *root, int expectNumber, int sum)
//	{
//		vector<list<int>> path{};
//		sum += root->val;
//		if (root->left == nullptr && root->right == nullptr)
//		{
//			if (sum == expectNumber)
//				return { {root->val} };
//			else
//				return {};
//		}
//
//		if (root->left != nullptr)
//		{
//			auto left_path = FindPathCore(root->left, expectNumber, sum);
//			for (auto it = left_path.begin(); it != left_path.end(); ++it)
//			{
//				it->push_front(root->val);
//				path.push_back(*it);
//			}
//		}
//		
//		if (root->right != nullptr)
//		{
//			auto right_path = FindPathCore(root->right, expectNumber, sum);
//			for (auto it = right_path.begin(); it != right_path.end(); ++it)
//			{
//				it->push_front(root->val);
//				path.push_back(*it);
//			}
//		}
//
//		return path;
//	}
//};

int main()
{
	Solution s;
	TreeNode *head = new TreeNode(10);
	head->left = new TreeNode(5);
	head->left->left = new TreeNode(4);
	head->left->right = new TreeNode(7);
	head->right = new TreeNode(12);
	auto ret = s.FindPath(head, 22);
	return 0;
}