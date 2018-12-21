#include <iostream>
using std::cout; using std::endl;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		ListNode* handling_node = head;
		ListNode* insert_node = head;
		ListNode* root;
		while (handling_node == nullptr)
		{
			if (handling_node->val > insert_node->next->val)
			{
				insert_node = insert_node->next;
			}
			else
			{
				ListNode* next_insert_node = insert_node->next;
				ListNode* next_handling_node = handling_node->next;
				insert_node->next = handling_node;
				handling_node->next = next_insert_node;
				handling_node = next_handling_node;
			}
		}
		return root;
	}
};

int main()
{

	return 0;
}