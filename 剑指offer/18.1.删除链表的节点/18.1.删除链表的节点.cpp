#include <iostream>
using namespace std;
struct ListNode
{
	int value;
	ListNode *next;
	ListNode(int v) : value(v), next(nullptr) {}
};

void DeleteNode(ListNode **plistHead, ListNode *pToBeDeleted)
{
	if (*plistHead == nullptr && pToBeDeleted == nullptr)
		return;

	if ((pToBeDeleted->next != nullptr))
	{
		pToBeDeleted->value = pToBeDeleted->next->value;
		ListNode *pNext = pToBeDeleted->next;
		pToBeDeleted->next = pToBeDeleted->next->next;
		delete pNext;
	}
	else if (*plistHead == pToBeDeleted)
	{
		delete *plistHead;
		pToBeDeleted = nullptr;
		*plistHead = nullptr;
	}
	else
	{
		ListNode *ptr = *plistHead;
		while (ptr->next != pToBeDeleted)
		{
			ptr = ptr->next;
		}
		ptr->next = nullptr;
		delete ptr->next;
	}
}

int main()
{
	ListNode *head = new ListNode(0);
	head->next = new ListNode(1);
	head->next->next = new ListNode(2);
	//head->next->next->next = new ListNode(3);
	//DeleteNode(&head, head->next->next->next);
	DeleteNode(&head, head);
	ListNode *ptr = head;
	while (ptr)
	{
		cout << ptr->value << endl;
		ptr = ptr->next;
	}
	return 0;
}