#include <iostream>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
    struct ListNode *pre;
	ListNode(int x) :
			val(x), next(nullptr) {
	}
};

ListNode *ReversePartList(ListNode *head, int start, int end)
{
	ListNode *s_pre = nullptr, *e_next = nullptr;
	int length = 0;
	auto *ptr = head;
	while (ptr != nullptr)
	{
		++length;
		if (length == start - 1)
			s_pre = ptr;
		if (length == end + 1)
			e_next = ptr;
		ptr = ptr->next;
	}

	if (length < start || length < end || start > end || start <= 0)
		return head;

	auto reverse_start = s_pre == nullptr ? head : s_pre->next;
	ptr = reverse_start;
	ListNode *pre = e_next;
	ListNode *next = nullptr;
	while (ptr != e_next)
	{
		next = ptr->next;
		ptr->next = pre;
		pre = ptr;
		ptr = next;
	}

	if (s_pre == nullptr)
	{
		return pre;
	}
	else
	{
		s_pre->next = pre;
		return head;
	}
}

int main()
{
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);

	auto *ret = ReversePartList(head, 0, 2);
	while (ret != nullptr)
	{
		cout << ret->val << endl;
		ret = ret->next;
	}
	return 0;
}