#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int getHeight(TreeNode* head, int l)
{
	if (head == nullptr)
		return l;

	return std::max(getHeight(head->left, l + 1), getHeight(head->right, l + 1));
}

void setEdgeMap(TreeNode* h, int l, vector<vector<TreeNode*>>& edgeMap)
{
	if (h == nullptr)
		return;

	edgeMap[l][0] = (edgeMap[l][0] == nullptr) ? h : edgeMap[l][0];
	edgeMap[l][1] = h;
	setEdgeMap(h->left, l + 1, edgeMap);
	setEdgeMap(h->right, l + 1, edgeMap);
}

void printLeafNotInMap(TreeNode* h, int l, const vector<vector<TreeNode*>>& edgeMap)
{
	if (h == nullptr)
		return;

	if (h->left == nullptr && h->right == nullptr && h != edgeMap[l][0] && h != edgeMap[l][1])
		cout << h->val << endl;
	printLeafNotInMap(h->left, l + 1, edgeMap);
	printLeafNotInMap(h->right, l + 1, edgeMap);
}

void printEdge1(TreeNode* head)
{
	if (head == nullptr)
		return;

	int height = getHeight(head, 0);
	vector<vector<TreeNode*>> edgeMap(height, vector<TreeNode*>(2, nullptr));
	setEdgeMap(head, 0, edgeMap);

	for (int i = 0; i != height; ++i)
		cout << edgeMap[i][0]->val << endl;
	printLeafNotInMap(head, 0, edgeMap);

	for (int i = height - 1; i >= 0; --i)
	{
		if (edgeMap[i][0] != edgeMap[i][1])
			cout << edgeMap[i][1]->val << endl;
	}
}

void printInOrder(const TreeNode* head, int height, string to, int len, ostream& os)
{
	if (head == nullptr)
		return;
	printInOrder(head->right, height + 1, "v", len, os);
	string val = to + to_string(head->val) + to;
	int lenM = val.length();
	int lenL = (len - lenM) / 2;
	int lenR = len - lenM - lenL;
	val = string(lenL, ' ') + val + string(lenL, ' ');
	os << string(height * len, ' ') + val << endl;
	printInOrder(head->left, height + 1, "^", len, os);
}

void printTree(const TreeNode * head, ostream & os)
{
	os << "Binary Tree:" << endl;
	printInOrder(head, 0, "H", 17, os);
	os << endl;
}

ostream& operator<<(ostream & os, const TreeNode * head)
{
	printTree(head, os);
	return os;
}

int main()
{
	TreeNode* head = new TreeNode(1);
	head->left = new TreeNode(2);
	head->left->right = new TreeNode(4);
	head->left->right->left = new TreeNode(7);
	head->left->right->right = new TreeNode(8);
	head->left->right->right->right = new TreeNode(11);
	head->left->right->right->right->left = new TreeNode(13);
	head->left->right->right->right->right = new TreeNode(14);

	head->right = new TreeNode(3);
	head->right->left = new TreeNode(5);
	head->right->right = new TreeNode(6);
	head->right->left->left = new TreeNode(9);
	head->right->left->right = new TreeNode(10);
	head->right->left->left->left = new TreeNode(12);
	head->right->left->left->left->left = new TreeNode(15);
	head->right->left->left->left->right = new TreeNode(16);

	cout << head << endl;

	printEdge1(head);
	return 0;
}