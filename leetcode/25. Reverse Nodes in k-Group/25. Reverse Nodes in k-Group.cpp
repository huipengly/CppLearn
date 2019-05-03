#include <stack>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (k < 2)
			return head;
		ListNode* start = nullptr;
		ListNode* pre = nullptr;
		ListNode* cur = head;
		ListNode* next = nullptr;
		int counter = 1;
		while (cur != nullptr)
		{
			next = cur->next;
			if (counter == k)
			{
				start = pre == nullptr ? head : pre->next;
				head = pre == nullptr ? cur : head;
				reverse(pre, start, cur, next);
				pre = start;
				counter = 0;
			}
			++counter;
			cur = next;
		}
		return head;
	}
private:
	void reverse(ListNode* left, ListNode* start, ListNode* end, ListNode* right)
	{
		ListNode* pre = start;
		ListNode* cur = start->next;
		ListNode* next = nullptr;
		while (cur != right)
		{
			next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		if (left != nullptr)
			left->next = end;
		start->next = right;
	}
};

class Solution_stack {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (k < 2)
			return head;
		ListNode* newHead = head, * pre = nullptr, * cur = head, * next = nullptr;
		stack<ListNode*> stack;
		while (cur != nullptr)
		{
			next = cur->next;
			stack.push(cur);
			if (stack.size() == k)
			{
				pre = reverse(stack, pre, next);
				newHead = newHead == head ? cur : newHead;
			}
			cur = next;
		}
		return newHead;
	}
private:
	ListNode* reverse(stack<ListNode*>& stack, ListNode* left, ListNode* right)
	{
		ListNode* cur = stack.top();
		stack.pop();
		if (left != nullptr)
		{
			left->next = cur;
		}
		ListNode* next = nullptr;
		while (!stack.empty())
		{
			next = stack.top();
			stack.pop();
			cur->next = next;
			cur = next;
		}
		cur->next = right;
		return cur;
	}
};

int main()
{
	Solution s;
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	auto* ret = s.reverseKGroup(head, 2);
	return 0;
}