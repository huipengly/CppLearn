#include <ostream>
#include <vector>
#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* selectionSortWithLinkedList(ListNode* head)
{
	ListNode* newHead = nullptr, * ncur = nullptr;
	ListNode* cur = nullptr, * pre = nullptr;
	ListNode* min = nullptr, * min_pre = nullptr;
	while (head != nullptr)
	{
		pre = head;
		cur = head->next;
		min = head;
		min_pre = nullptr;
		while (cur != nullptr)
		{
			if (cur->val < min->val)
			{
				min_pre = pre;
				min = cur;
			}
			pre = cur;
			cur = cur->next;
		}

		if (newHead == nullptr)
			newHead = min;
		else
			ncur->next = min;
		ncur = min;

		if (min_pre == nullptr)
			head = min->next;
		else
			min_pre->next = min->next;
	}
	return newHead;
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
	auto* head = vector_to_linked_list({ 1, 3, 5, 2, 4, 6 });
	cout << selectionSortWithLinkedList(head) << endl;

	return 0;
}