#include <vector>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* insertNumInCircleSortedLinkedList(ListNode* head, int num)
{
	ListNode* node = new ListNode(num);
	if (head == nullptr)
	{
		node->next = node;
		return node;
	}

	ListNode* pre = head, * cur = head->next;
	// 如果可以插入环里，则插入。如果找了一圈还没找到符合条件的，那么此时pre在tail，cur在head，插入到这里，再判断是否需要修改头
	while (cur != head)		
	{
		if (pre->val < num && cur->val > num)
			break;
		pre = cur;
		cur = cur->next;
	}
	pre->next = node;
	node->next = cur;
	return num < head->val ? node : head;

	// 我自己的复杂写法
	//if (num < head->val)
	//{
	//	while (cur->next != head)
	//		cur = cur->next;
	//	cur->next = node;
	//	node->next = head;
	//	head = node;
	//}
	//else
	//{
	//	while (cur->next != head && cur->val < num)
	//	{
	//		pre = cur;
	//		cur = cur->next;
	//	}
	//	if (cur->next == head)
	//	{
	//		cur->next = node;
	//		node->next = head;
	//	}
	//	else
	//	{
	//		pre->next = node;
	//		node->next = cur;
	//	}
	//}

	return head;
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
	auto* head = vector_to_linked_list({ 1, 3, 4 });
	head->next->next->next = head;
	auto* ret = insertNumInCircleSortedLinkedList(head, 5);
	return 0;
}