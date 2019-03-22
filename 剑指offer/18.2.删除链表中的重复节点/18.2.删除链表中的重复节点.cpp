#include <iostream>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(nullptr) {
	}
};

class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == nullptr || pHead->next == nullptr)
			return pHead;
		ListNode *ptr = pHead, *pre = nullptr;

		while (ptr != nullptr && ptr->next != nullptr)
		{
			if (ptr->val != ptr->next->val)
			{
				pre = ptr;
				ptr = ptr->next;
			}
			else if (ptr->val == ptr->next->val)
			{
				int duplicationValue = ptr->val;
				while (ptr != nullptr && ptr->val == duplicationValue)
				{
					auto *pToBeDeleted = ptr;
					ptr = ptr->next;
					delete pToBeDeleted;
				}
				if (pre == nullptr)
				{
					pHead = ptr;
				}
				else
				{
					pre->next = ptr;
				}
			}
		}

		return pHead;
	}
};

int main()
{
	Solution s;
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(3);
	head->next->next->next->next = new ListNode(4);
	head->next->next->next->next->next = new ListNode(4);
	head->next->next->next->next->next->next = new ListNode(5);
	//DeleteNode(&head, head->next->next->next);
	auto *ret = s.deleteDuplication(head);
	//ListNode *ptr = head;
	while (ret)
	{
		cout << ret->val << endl;
		ret = ret->next;
	}
	return 0;
}