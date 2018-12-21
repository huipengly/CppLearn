struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr)
			return l2;
		if (l2 == nullptr)
			return l1;
		ListNode dummy(-1);			// �������new�Ļ����ǵ����Ҫdelete��������������Ͳ���Ҫ�����ڴ�й©
		ListNode *cur = &dummy;
		while (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				cur->next = l1;
				l1 = l1->next;
			}
			else
			{
				cur->next = l2;
				l2 = l2->next;
			}
			cur = cur->next;
		}
		cur->next = l1 ? l1 : l2;	// ����һ���鲢�꣬����һ��ʣ��Ķ��鲢
		return dummy.next;
	}
};

int main()
{
	Solution s;
	ListNode *l1, *l2;
	l1 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(4);

	l2 = new ListNode(1);
	l2->next = new ListNode(3);
	l2->next->next = new ListNode(4);

	s.mergeTwoLists(l1, l2);
	return 0;
}