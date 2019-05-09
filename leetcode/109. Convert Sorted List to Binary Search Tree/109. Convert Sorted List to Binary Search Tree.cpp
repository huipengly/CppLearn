#include <vector>
#include <ostream>
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 模拟先序遍历的过程，就是恢复的时候不按照中左右恢复，而是按照左中右恢复，这样就没有寻找mid的过程了。
class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		if (head == nullptr)
			return nullptr;
		this->head = head;
		int size = findSize(head);
		return sortedListToBST(0, size - 1);
	}
private:
	ListNode* head;
	int findSize(ListNode* head)
	{
		auto* cur = head;
		int size = 0;
		while (cur != nullptr)
		{ 
			++size;
			cur = cur->next;
		}
		return size;
	}
	TreeNode* sortedListToBST(int l, int r)
	{
		if (l > r)
			return 0;

		int mid = l + (r - l) / 2;
		auto* left = sortedListToBST(l, mid - 1);
		auto* treeHead = new TreeNode(head->val);
		treeHead->left = left;
		head = head->next;
		treeHead->right = sortedListToBST(mid + 1, r);
		return treeHead;
	}
};

// 转换为数组的递归方法。time:O(N) space:O(N)

// 递归方法。time:O(NlogN) space:O(NlogN)
class Solution1 {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		if (head == nullptr)
			return nullptr;

		ListNode* slow = head, * fast = head, * pre = nullptr;
		while (fast != nullptr && fast->next != nullptr)
		{
			pre = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		if (pre != nullptr)
			pre->next = nullptr;
		TreeNode* treeHead = new TreeNode(slow->val);
		if (head == slow)
			return treeHead;

		treeHead->left = sortedListToBST(head);
		treeHead->right = sortedListToBST(slow->next);
		return treeHead;
	}
};

ListNode* vector_to_linked_list(const vector<int>& arr)
{
	ListNode* head = new ListNode(arr[0]);
	auto* ptr = head;
	for (int i = 1; i != arr.size(); ++i)
	{
		ptr->next = new ListNode(arr[i]);
		ptr = ptr->next;
	}
	return head;
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
	Solution s;
	cout << s.sortedListToBST(vector_to_linked_list({ -10,-3,0,5,9 })) << endl;
	return 0;
}