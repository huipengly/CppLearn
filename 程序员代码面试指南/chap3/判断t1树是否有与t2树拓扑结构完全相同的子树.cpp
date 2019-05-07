#include <string>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// o(m + n)方法，但是常数时间太长了。其中string.find认为是kmp实现
// 特殊例子：树1[12], 树2[2]
class Solution {
public:
	bool isSubtree(TreeNode* s, TreeNode* t) {
		string sStr = preOrderSerialization(s);
		string tStr = preOrderSerialization(t);
		auto n = sStr.find(tStr);
		if (n != string::npos)
		{
			if (n == 0)
				return true;
			return sStr[n - 1] == '!';
		}
		return false;
	}
private:
	string preOrderSerialization(TreeNode * head)
	{
		if (head == nullptr)
			return "#!";
		string str = to_string(head->val) + '!';
		str += preOrderSerialization(head->left);
		str += preOrderSerialization(head->right);
		return str;
	}
};

class Solution_recursive {
public:
	bool isSubtree(TreeNode* s, TreeNode* t) {
		return (s != nullptr) && (check(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t));
	}
private:
	bool check(TreeNode * s, TreeNode * t) {
		if (t == nullptr && s == nullptr)
			return true;
		if (t == nullptr || s == nullptr)
			return false;

		return (s->val == t->val) && check(s->left, t->left) && check(s->right, t->right);
	}
};

int main()
{
	Solution s;
	//TreeNode* head = new TreeNode(3);
	TreeNode* head = new TreeNode(12);
	//head->left = new TreeNode(4);
	//head->left->left = new TreeNode(1);
	//head->right = new TreeNode(5);
	//head->right->left = new TreeNode(2);
	//TreeNode* t = new TreeNode(3);
	TreeNode* t = new TreeNode(2);
	//t->left = new TreeNode(1);
	//t->right = new TreeNode(2);
	auto ret = s.isSubtree(head, t);
	return 0;
}