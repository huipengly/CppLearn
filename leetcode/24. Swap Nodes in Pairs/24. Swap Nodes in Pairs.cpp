
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == nullptr)
			return head;
		ListNode* nhead = nullptr, *ptr = nullptr;
		ListNode* tail = nullptr, *next = nullptr;
		while (head != nullptr)
		{
			tail = head->next;
			next = tail == nullptr ? nullptr : tail->next;
			if (ptr == nullptr)
				nhead = reverse(head, tail);
			else
				ptr->next = reverse(head, tail);
			ptr = head;
			head = next;
		}
		return nhead;
	}
private:
	ListNode* reverse(ListNode* head, ListNode* tail)
	{
		if (tail == nullptr)
			return head;
		ListNode* pre = nullptr, * ptr = head, * next = head;
		while (pre != tail)
		{
			next = ptr->next;
			ptr->next = pre;
			pre = ptr;
			ptr = next;
		}
		return pre;
	}
};

int main()
{
	Solution s;
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	auto *ret = s.swapPairs(head);
	return 0;
}