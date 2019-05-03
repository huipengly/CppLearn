#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
	
};
class Solution {
public:
	ListNode* removeRep1(ListNode* head) {
		ListNode* cur = head, * pre = head;
		unordered_set<int> set;
		while (cur != nullptr)
		{
			if (set.find(cur->val) == set.end())
			{
				set.insert(cur->val);
				pre = cur;
			}
			else
			{
				pre->next = cur->next;
			}
			cur = cur->next;
		}
		return head;
	}

	ListNode* removeRep2(ListNode* head) {
		ListNode* cur = head, * pre = nullptr, * next = nullptr;
		while (cur != nullptr)
		{
			pre = cur;
			next = cur->next;
			while (next != nullptr)
			{
				if (next->val == cur->val)
					pre->next = next->next;
				else
					pre = pre->next;
				next = next->next;
			}
			cur = cur->next;
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

ostream& operator<<(ostream& os, const ListNode* head)
{
	auto* curr = head;
	while (curr != nullptr)
	{
		os << curr->val << " ";
		curr = curr->next;
	}
	return os;
}

int main()
{
	Solution s;
	auto* head = vector_to_linked_list({ 1, 2, 3, 3, 4, 4, 2, 1, 1 });
	cout << s.removeRep2(head) << endl;
	return 0;
}