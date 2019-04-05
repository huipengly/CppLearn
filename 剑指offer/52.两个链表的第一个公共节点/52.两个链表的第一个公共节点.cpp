#include <cassert>
#include <unordered_set>
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
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		int l1 = ListLength(pHead1);
		int l2 = ListLength(pHead2);
		int lenth_diff = abs(l1 - l2);

		if (l1 > l2)
			std::swap(pHead1, pHead2);

		for (int i = 0; i != lenth_diff; ++i)
			pHead2 = pHead2->next;

		while (pHead1 != nullptr)
		{
			if (pHead1 == pHead2)
				return pHead1;
			pHead1 = pHead1->next;
			pHead2 = pHead2->next;
		}

		return nullptr;
	}
private:
	int ListLength(ListNode *head)
	{
		int counter = 0;
		while (head != nullptr)
		{
			++counter;
			head = head->next;
		}
		return counter;
	}
};

//class Solution {
//public:
//	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
//		if (pHead1 == nullptr || pHead2 == nullptr)
//			return nullptr;
//
//		unordered_set<ListNode *> nodes;
//		auto *ptr = pHead1;
//		while (ptr != nullptr)
//		{
//			nodes.insert(ptr);
//			ptr = ptr->next;
//		}
//
//		ptr = pHead2;
//		while (ptr != nullptr)
//		{
//			if (nodes.find(ptr) != nodes.end())
//				return ptr;
//			ptr = ptr->next;
//		}
//		return nullptr;
//	}
//};

int main()
{
	ListNode *head1 = new ListNode(1);
	ListNode *head2 = new ListNode(4);
	head1->next = new ListNode(2);
	head1->next->next = new ListNode(3);
	head2->next = new ListNode(5);
	head2->next->next = new ListNode(6);
	head2->next->next->next = new ListNode(7);
	head1->next->next->next = head2->next->next;
	Solution s;
	assert(s.FindFirstCommonNode(head1, head2) == head2->next->next);
	return 0;
}