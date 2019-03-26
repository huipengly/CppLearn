#include <unordered_set>

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		if (pHead == nullptr)
			return nullptr;

		ListNode *slow = pHead, *fast = pHead;
		while (fast != nullptr && fast->next != nullptr)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
				break;
		}

		if (fast == nullptr || fast->next == nullptr)		// 非环
			return nullptr;

		int n = 1;
		fast = fast->next;
		while (fast != slow)
		{
			fast = fast->next;
			++n;
		}

		fast = pHead;
		slow = pHead;
		for (int i = 0; i != n; ++i)
			fast = fast->next;

		while (fast != slow)
		{
			fast = fast->next;
			slow = slow->next;
		}

		return slow;

		// 方法1：set
		//if (pHead == nullptr)
		//	return nullptr;
		//std::unordered_set<ListNode *> set;
		//while (pHead != nullptr && set.find(pHead) == set.end())
		//{
		//	set.insert(pHead);
		//	pHead = pHead->next;
		//}
		//return pHead;
	}
};

int main()
{
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(6);
	head->next->next->next->next->next->next = head->next->next;
	Solution s;
	auto *ret = s.EntryNodeOfLoop(head);
	return 0;
}