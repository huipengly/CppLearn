#include <unordered_map>
#include <string>
#include <iomanip>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

bool isBSTNode(TreeNode* h, TreeNode* n, int val)
{
	if (h == nullptr)
		return false;
	if (h == n)
		return true;
	return isBSTNode(h->val > val ? h->left : h->right, n, val);
}

int maxTopo(TreeNode* h, TreeNode* n)		// 以h为头节点的二叉树，其子节点n的最大拓扑数目。
{
	if (h != nullptr && n != nullptr && isBSTNode(h, n, n->val))
		return maxTopo(h, n->left) + maxTopo(h, n->right) + 1;
	return 0;
}

int bstTopoSize1(TreeNode* head)
{
	if (head == nullptr)
		return 0;

	int max = maxTopo(head, head);
	max = std::max(max, bstTopoSize1(head->left));
	max = std::max(max, bstTopoSize1(head->right));
	return max;
}

struct Record
{
	int l;
	int r;
	Record() = default;
	Record(int l, int r) : l(l), r(r) {}
};

int modifiMap(TreeNode* n, int v, unordered_map<TreeNode*, Record> &map, bool s)
{
	if (n == nullptr || (map.find(n) == map.end()))
		return 0;
	Record r = map[n];
	if ((s && (n->val > v)) || (!s && (n->val < v)))
	{
		map.erase(n);
		return r.l + r.r + 1;
	}
	else
	{
		int minus = modifiMap(s ? n->right : n->left, v, map, s);
		if (s)
			r.r -= minus;
		else
			r.l -= minus;
		map[n] = r;
		return minus;
	}
}

int postOrder(TreeNode* head, unordered_map<TreeNode*, Record> &map)
{
	if (head == nullptr)
		return 0;
	int ls = postOrder(head->left, map);
	int rs = postOrder(head->right, map);
	modifiMap(head->left, head->val, map, true);
	modifiMap(head->right, head->val, map, false);
	Record lr, rr;
	int lbst = 0, rbst = 0;
	if (map.find(head->left) != map.end())
	{
		lr = map[head->left];
		lbst = lr.l + lr.r + 1;
	}
	if (map.find(head->right) != map.end())
	{
		rr = map[head->right];
		rbst = rr.l + rr.r + 1;
	}
	map[head] = Record(lbst, rbst);
	return std::max(lbst + rbst + 1, std::max(ls, rs));
}

int bstTopoSize2(TreeNode* head)
{
	unordered_map<TreeNode*, Record> map;
	return postOrder(head, map);
}

// 打印二叉树
void printInOrder(const TreeNode* head, int len, char to, int height, ostream& os)
{
	if (head == nullptr)
		return;

	printInOrder(head->right, len + 1, 'v', height, os);
	std::string val = to + to_string(head->val) + to;
	os << setw(height * (len + 1)) << val << endl;
	printInOrder(head->left, len + 1, '^', height, os);
}

void printTree(const TreeNode * head, ostream & os)
{
	os << "Binary Tree:" << endl;
	printInOrder(head, 0, 'H', 17, os);
	os << endl;
}

ostream& operator<<(ostream & os, const TreeNode * head)
{
	printTree(head, os);
	return os;
}
// 打印二叉树

int main()
{
	TreeNode* head = new TreeNode(6);
	head->left = new TreeNode(1);
	head->left->left = new TreeNode(0);
	head->left->right = new TreeNode(3);

	head->right = new TreeNode(12);
	head->right->left = new TreeNode(10);
	head->right->left->left = new TreeNode(4);
	head->right->left->left->left = new TreeNode(2);
	head->right->left->left->right = new TreeNode(5);
	head->right->left->right = new TreeNode(14);
	head->right->left->right->left = new TreeNode(11);
	head->right->left->right->right = new TreeNode(15);
	head->right->right = new TreeNode(13);
	head->right->right->left = new TreeNode(20);
	head->right->right->right = new TreeNode(16);

	cout << head << endl;
	cout << bstTopoSize1(head) << endl;
	cout << bstTopoSize2(head) << endl;

	return 0;
}