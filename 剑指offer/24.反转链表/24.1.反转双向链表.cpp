struct ListNode {
	int val;
	struct ListNode *next;
    struct ListNode *pre;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

ListNode *reverse(ListNode *pHead)
{
    if (pHead == nullptr)
        return nullptr;
    ListNode *pre = nullptr;
    ListNode *next = nullptr;
    while (pHead != nullptr)
    {
        next = pHead->next;
        pHead->pre = next;
        pHead->next = pre;
        pre = pHead;
        pHead = next;
    }
    return pre;
}