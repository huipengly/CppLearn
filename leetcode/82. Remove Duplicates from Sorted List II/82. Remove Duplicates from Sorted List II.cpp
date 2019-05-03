#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* cur = head, * pre = nullptr;
		while (cur != nullptr && cur->next != nullptr)
		{
			if (cur->val == cur->next->val)
			{
				int val = cur->val;
				while (cur != nullptr && cur->val == val)
					cur = cur->next;
				if (pre == nullptr)
					head = cur;
				else
					pre->next = cur;
			}
			else
			{
				pre = cur;
				cur = cur->next;
			}
		}
		return head;
	}
};

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
	Solution s;
	auto* head = vector_to_linked_list({ 1, 2, 3, 3, 4, 4, 5 });
	auto* ret = s.deleteDuplicates(head);
	return 0;
}