#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	void relocateList(struct ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return;

		ListNode* mid = head, * right = head->next;
		while (right->next != nullptr && right->next->next != nullptr)
		{
			mid = mid->next;
			right = right->next->next;
		}
		right = mid->next;
		mid->next = nullptr;
		mergeLR(head, right);
	}
private:
	void mergeLR(ListNode* left, ListNode* right)
	{
		ListNode* node = nullptr;
		while (left->next != nullptr)
		{
			auto* next = right->next;
			right->next = left->next;
			left->next = right;
			left = right->next;
			right = next;
		}
		left->next = right;
	}
};

class Solution_my {
public:
	/**
	 *	按照左右半区的方式重新组合单链表
	 *	输入：一个单链表的头节点head
	 *	将链表调整成题目要求的样子
	 *
	 *	后台的单链表节点类如下：
	 *
	 struct ListNode {
		int val;
		struct ListNode *next;
		ListNode(int x) :
				val(x), next(NULL) {
		}
	};
	 */
	void relocateList(struct ListNode* head) {
		if (head == nullptr)
			return;
		ListNode* slow = head, * fast = head;
		while (fast != nullptr && fast->next != nullptr)
		{
			slow = slow->next;
			fast = fast->next->next;
		}

		if (fast == slow)
			return;

		ListNode* left = head->next, * right = slow, * cur = head;;
		bool add_left = false;
		while (left != slow && left != nullptr && right != nullptr)
		{
			if (add_left)
			{
				cur->next = left;
				left = left->next;
				add_left = false;
			}
			else
			{
				cur->next = right;
				right = right->next;
				add_left = true;
			}
			cur = cur->next;
		}

		if (left != slow)
			cur->next = left;
		if (right != nullptr)
			cur->next = right;
	}
};

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
	auto* head = vector_to_linked_list({ 10,9,7,8,13 });
	s.relocateList(head);
	cout << head << endl;
	return 0;
}