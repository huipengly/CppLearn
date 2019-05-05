#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <iomanip>
using namespace std;
struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

string preOrderSerialization(TreeNode* head)
{
	if (head == nullptr)
		return "#!";
	string str{};
	str += to_string(head->val) + '!';
	str += preOrderSerialization(head->left);
	str += preOrderSerialization(head->right);
	return str;
}

TreeNode* preOrderDeserialization(queue<string>& queue)
{
	if (queue.empty())
		return nullptr;
	string value = queue.front();
	queue.pop();
	if (value == "#")
		return nullptr;

	TreeNode* head = new TreeNode(stoi(value));
	head->left = preOrderDeserialization(queue);
	head->right = preOrderDeserialization(queue);
	return head;
}

TreeNode* preOrderDeserialization(const string& str)
{
	queue<string> queue;
	auto it = str.begin();
	while (it != str.end())
	{
		auto end = find(it, str.end(), '!');
		queue.push(str.substr(it - str.begin(), end - it));
		it = end + 1;
	}

	return preOrderDeserialization(queue);
}

string serialByLevel1(TreeNode* head)
{
	if (head == nullptr)
		return {};

	string str{};
	queue<TreeNode*> queue;
	queue.push(head);
	while (!queue.empty())
	{
		auto* node = queue.front();
		queue.pop();
		if (node != nullptr)
		{
			str += to_string(node->val) + '!';
			queue.push(node->left);
			queue.push(node->right);
		}
		else
		{
			str += "#!";
		}
	}
	return str;
}

// 书上的写法，更利于理解的广度优先
string serialByLevel2(TreeNode* head)
{
	if (head == nullptr)
		return "#!";

	string str = to_string(head->val) + '!';
	queue<TreeNode*> queue;
	queue.push(head);
	while (!queue.empty())
	{
		auto* node = queue.front();
		queue.pop();
		//if (node->val == 10)
		//	int aa = 0;
		if (node->left != nullptr)
		{
			str += to_string(node->left->val) + '!';
			queue.push(node->left);
		}
		else
			str += "#!";

		if (node->right != nullptr)
		{
			str += to_string(node->right->val) + '!';
			queue.push(node->right);
		}
		else
			str += "#!";
	}
	return str;
}

TreeNode* generateNodeByString(const string& str)
{
	if (str == "#")
		return nullptr;
	return new TreeNode(stoi(str));
}

TreeNode* deserialByLevel(const string& str)
{
	vector<string> values;
	auto it = str.begin();
	while (it != str.end())
	{
		auto end = find(it, str.end(), '!');
		values.push_back(str.substr(it - str.begin(), end - it));
		it = end + 1;
	}
	int index = 0;
	TreeNode* head = generateNodeByString(values[index++]);
	queue<TreeNode*> queue;
	if (head != nullptr)
		queue.push(head);
	while (!queue.empty())
	{
		auto* node = queue.front();
		queue.pop();
		node->left = generateNodeByString(values[index++]);
		node->right = generateNodeByString(values[index++]);
		if (node->left != nullptr)
			queue.push(node->left);
		if (node->right != nullptr)
			queue.push(node->right);
	}

	return head;
}

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

int main()
{
	TreeNode* head = new TreeNode(1);
	head->left = new TreeNode(2);
	head->left->right = new TreeNode(4);
	head->left->right->left = new TreeNode(7);
	head->left->right->right = new TreeNode(8);
	head->left->right->right->right = new TreeNode(10002511);
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

	string str1 = preOrderSerialization(head);
	string str2 = serialByLevel1(head);
	string str3 = serialByLevel2(head);
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	auto* ret1 = preOrderDeserialization(str1);
	cout << ret1 << endl;
	auto* ret2 = deserialByLevel(str2);
	cout << ret2 << endl;
	auto* ret3 = deserialByLevel(str3);
	cout << ret3 << endl;
	return 0;
}