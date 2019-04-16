#include <vector>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	struct ListNode *pre;
	ListNode(int x) :
		val(x), next(nullptr) {
	}
};

void add_node(ListNode *&head, ListNode *&tail, ListNode *add)
{
	if (head == nullptr)
	{
		head = add;
		tail = add;
	}
	else
	{
		tail->next = add;
		tail = tail->next != nullptr ? tail->next : tail;
	}
}

ListNode *LinkedList3WayPartition(ListNode *head, int val)
{
	if (head == nullptr || head->next == nullptr)
		return head;

	ListNode *lt_head = nullptr, *lt_tail = nullptr;
	ListNode *eq_head = nullptr, *eq_tail = nullptr;
	ListNode *gt_head = nullptr, *gt_tail = nullptr;
	ListNode *ptr = head;
	ListNode *next = nullptr;
	while (ptr != nullptr)
	{
		next = ptr->next;
		ptr->next = nullptr;
		if (ptr->val < val)
		{
			add_node(lt_head, lt_tail, ptr);
		}
		else if (ptr->val > val)
		{
			add_node(gt_head, gt_tail, ptr);
		}
		else
		{
			add_node(eq_head, eq_tail, ptr);
		}
		ptr = next;
	}

	add_node(lt_head, lt_tail, eq_head);
	add_node(lt_head, eq_tail == nullptr ? lt_tail : eq_tail, gt_head);

	return lt_head;
}

ListNode* vector_to_linked_list(const vector<int> &arr)
{
	ListNode *head = new ListNode(arr[0]);
	auto *ptr = head;
	for (int i = 1; i != arr.size(); ++i)
	{
		ptr->next = new ListNode(arr[i]);
		ptr = ptr->next;
	}
	return head;
}

int main()
{
	vector<int> arr{ 9, 0, 4, 5, 1 };

	ListNode *head = vector_to_linked_list(arr);
	ListNode *add = new ListNode(2);
	auto ret = LinkedList3WayPartition(head, 3);
	return 0;
}
