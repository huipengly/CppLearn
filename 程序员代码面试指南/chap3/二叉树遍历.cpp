#include <iostream>
#include <stack>
using namespace std;
struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void preOrderRecursive(TreeNode* pRoot)
{
	if (pRoot == nullptr)
		return;

	cout << pRoot->val << endl;
	preOrderRecursive(pRoot->left);
	preOrderRecursive(pRoot->right);
}

void preOrder(TreeNode* pRoot)
{
	if (pRoot == nullptr)
		return;

	stack<TreeNode*> stack;
	stack.push(pRoot);
	while (!stack.empty())
	{
		auto* node = stack.top();
		stack.pop();
		cout << node->val << endl;
		if (node->right != nullptr)
			stack.push(node->right);
		if (node->left != nullptr)
			stack.push(node->left);
	}
}

void inOrderRecursive(TreeNode* pRoot)
{
	if (pRoot == nullptr)
		return;

	inOrderRecursive(pRoot->left);
	cout << pRoot->val << endl;
	inOrderRecursive(pRoot->right);
}

void inOrder(TreeNode* pRoot)
{
	if (pRoot == nullptr)
		return;

	stack<TreeNode*> stack;
	while (pRoot != nullptr)
	{
		stack.push(pRoot);
		pRoot = pRoot->left;
	}

	while (!stack.empty())
	{
		auto* node = stack.top();
		stack.pop();
		cout << node->val << endl;
		node = node->right;
		while (node != nullptr)
		{
			stack.push(node);
			node = node->left;
		}
	}
}

void postOrderRecursive(TreeNode* pRoot)
{
	if (pRoot == nullptr)
		return;

	postOrderRecursive(pRoot->left);
	postOrderRecursive(pRoot->right);
	cout << pRoot->val << endl;
}

void postOrder1(TreeNode* pRoot)
{
	if (pRoot == nullptr)
		return;
	stack<TreeNode*> stack, outStack;
	stack.push(pRoot);
	while (!stack.empty())
	{
		auto* node = stack.top();
		stack.pop();
		outStack.push(node);
		if (node->left != nullptr)
			stack.push(node->left);
		if (node->right != nullptr)
			stack.push(node->right);
	}
	while (!outStack.empty())
	{
		cout << outStack.top()->val << endl;
		outStack.pop();
	}
}

void postOrder2(TreeNode* h)
{
	if (h == nullptr)
		return;
	stack<TreeNode*> stack;
	stack.push(h);
	TreeNode* c = nullptr;
	while (!stack.empty())
	{
		c = stack.top();
		if (c->left != nullptr && c->left != h && c->right != h)
			stack.push(c->left);
		else if (c->right != nullptr && c->right != h)
			stack.push(c->right);
		else
		{
			cout << c->val << endl;
			stack.pop();
			h = c;
		}
	}
}

int main()
{
	TreeNode* pRoot = new TreeNode(10);
	pRoot->left = new TreeNode(6);
	pRoot->left->left = new TreeNode(4);
	pRoot->left->right = new TreeNode(8);
	pRoot->right = new TreeNode(14);
	pRoot->right->left = new TreeNode(12);
	pRoot->right->right = new TreeNode(16);

	cout << "preR :" << endl;
	preOrderRecursive(pRoot);
	cout << "pre :" << endl;
	preOrder(pRoot);
	cout << "inR :" << endl;
	inOrderRecursive(pRoot);
	cout << "in :" << endl;
	inOrder(pRoot);
	cout << "postR :" << endl;
	postOrderRecursive(pRoot);
	cout << "post1 :" << endl;
	postOrder1(pRoot);
	cout << "post2 :" << endl;
	postOrder2(pRoot);
	return 0;
}