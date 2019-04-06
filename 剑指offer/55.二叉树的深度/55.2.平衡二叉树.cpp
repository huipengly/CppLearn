#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(nullptr), right(nullptr) {
	}
};

// 计数的方法
class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot)
	{
		if (pRoot == nullptr)
			return true;
		int depth = 0;
		return IsBalanced_Solution(pRoot, depth);
	}
private:
	bool IsBalanced_Solution(TreeNode* pRoot, int &depth) {
		if (pRoot == nullptr)
			return true;

		int left = 0, right = 0;
		if (IsBalanced_Solution(pRoot->left, left) && 
			IsBalanced_Solution(pRoot->right, right) && 
			abs(left - right) <= 1)
		{
			depth = 1 + max(left, right);
			return true;
		}

		return false;
	}
};

// 前序，每个节点会被遍历多遍。
//class Solution {
//public:
//	bool IsBalanced_Solution(TreeNode* pRoot) {
//		if (pRoot == nullptr)
//			return true;
//
//		auto left = TreeDepth(pRoot->left);
//		auto right = TreeDepth(pRoot->right);
//
//		if (abs(left - right) > 1)
//			return false;
//		else
//			return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
//	}
//private:
//	int TreeDepth(TreeNode* pRoot)
//	{
//		if (pRoot == nullptr)
//			return 0;
//
//		return 1 + max(TreeDepth(pRoot->left), TreeDepth(pRoot->right));
//	}
//};

int main()
{

}