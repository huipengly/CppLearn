#include <iostream>

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == nullptr)
			return nullptr;

		ListNode *slow = pListHead, *fast = pListHead;
		int count = k;
		while (count-- && fast != nullptr)
		{
			fast = fast->next;
		}

		if (count != -1)
			return nullptr;

		while (fast != nullptr)
		{
			slow = slow->next;
			fast = fast->next;
		}

		return slow;
	}
};

int main()
{
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	Solution s;
	auto *ret = s.FindKthToTail(head, 0);
	std::cout << ret->val << std::endl;
	return 0;
}