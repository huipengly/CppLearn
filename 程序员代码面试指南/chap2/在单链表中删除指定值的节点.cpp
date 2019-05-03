#include <ostream>
#include <vector>
#include <iostream>
using namespace std;
// 输入描述:
// 1 输入链表结点个数
// 2 输入头结点的值
// 3 按照格式插入各个结点
// 4 输入要删除的结点的值

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeValue(ListNode* head, int val)
{
	while (head != nullptr && head->val == val)
	{
		head = head->next;
	}

	auto* pre = head, * cur = head;
	while (cur != nullptr)
	{
		if (cur->val == val)
			pre->next = cur->next;
		else
			pre = cur;
		cur = cur->next;
	}
	return head;
}

ostream& operator<<(ostream& os, const ListNode* head)
{
	auto* curr = head;
	while (curr != nullptr)
	{
		os << curr->val << " ";
		curr = curr->next;
	}
	return os;
}

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

int main()
{
	int N, val;
	cin >> N >> val;
	ListNode* head = new ListNode(val);
	for (int i = 0; i != N - 1; ++i)
	{
		int posVal;
		cin >> val >> posVal;
		auto* cur = head;
		while (cur != nullptr && cur->val != posVal)
			cur = cur->next;
		if (cur == nullptr)
			return -1;
		ListNode* next = cur->next;
		cur->next = new ListNode(val);
		cur->next->next = next;
	}
	int removeVal;
	cin >> removeVal;
	cout << removeValue(head, removeVal) << endl;
	return 0;
}