#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
using namespace std;
struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

bool isPostArray(const vector<int>& arr, int start, int end)
{
	if (start == end)
		return true;

	int less = -1, more = end;
	for (int i = start; i != end; ++i)
	{
		if (arr[i] < arr[end])
			less = i;
		if (arr[i] > arr[end])	// 只记录第一个比end大的
			more = more == end ? i : more;
	}

	if (less == -1 || more == end)
		return isPostArray(arr, start, end - 1);

	if (less != more - 1)
		return false;

	return isPostArray(arr, start, less) && isPostArray(arr, more, end - 1);
}

bool isPostArray(const vector<int>& arr)
{
	if (arr.empty())
		return true;

	return isPostArray(arr, 0, arr.size() - 1);
}

TreeNode* postArrayToBST(const vector<int>& arr, int start, int end)
{
	if (start > end)
		return nullptr;

	int less = -1, more = end;
	for (int i = start; i != end; ++i)
	{
		if (arr[i] < arr[end])
			less = i;
		else
			more = more == end ? i : more;
	}
	TreeNode* head = new TreeNode(arr[end]);
	head->left = postArrayToBST(arr, start, less);
	head->right = postArrayToBST(arr, more, end - 1);

	return head;
}

TreeNode* postArrayToBST(const vector<int>& arr)
{
	if (arr.empty())
		return nullptr;

	return postArrayToBST(arr, 0, arr.size() - 1);
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
	vector<int> arr{ 2, 1, 3, 6, 5, 7, 4 };
	cout << isPostArray(arr) << endl;
	cout << postArrayToBST(arr) << endl;
	return 0;
}