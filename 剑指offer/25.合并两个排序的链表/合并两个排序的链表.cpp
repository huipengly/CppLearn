
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(nullptr) {
	}
};

class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == nullptr)
			return pHead2;
		if (pHead2 == nullptr)
			return pHead1;

		ListNode *head = nullptr;

		if (pHead1->val <= pHead2->val)
		{
			head = pHead1;
			head->next = Merge(pHead1->next, pHead2);
		}
		else
		{
			head = pHead2;
			head->next = Merge(pHead1, pHead2->next);
		}

		return head;
	}
};

class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == nullptr)
			return pHead2;
		if (pHead2 == nullptr)
			return pHead1;

		ListNode *head = nullptr, *tail = nullptr;

		while (pHead1 != nullptr && pHead2 != nullptr)
		{
			ListNode *add_to_tail = nullptr;
			if (pHead1->val <= pHead2->val)
			{
				add_to_tail = pHead1;
				pHead1 = pHead1->next;
			}
			else
			{
				add_to_tail = pHead2;
				pHead2 = pHead2->next;
			}

			if (head == nullptr)
			{
				head = add_to_tail;
				tail = add_to_tail;
			}
			else
			{
				tail->next = add_to_tail;
				tail = tail->next;
			}
			tail->next = nullptr;
		}

		if (pHead1 != nullptr)
			tail->next = pHead1;
		else if (pHead2 != nullptr)
			tail->next = pHead2;

		return head;
	}
};

int main()
{

	return 0;
}