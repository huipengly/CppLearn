struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		auto* ptr = head;
		while (ptr != nullptr && ptr->next != nullptr)
		{
			if (ptr->val == ptr->next->val)
				ptr->next = ptr->next->next;
			else
				ptr = ptr->next;
		}
		return head;
	}
};