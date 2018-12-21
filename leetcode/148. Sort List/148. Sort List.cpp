struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* sortList(ListNode* head) {
		// 计算链表长度
		ListNode *ptr = head;
		int length = 0;
		while (ptr)
		{
			ptr = ptr->next;
			++length;
		}

		// 自底向上归并排序
		ListNode dummy(0);
		dummy.next = head;
		ListNode *left, *right, *tail;
		for (int sz = 1; sz < length; sz += sz)
		{
			ListNode *cur = dummy.next;
			tail = &dummy;
			while (cur)
			{
				left = cur;
				right = split(left, sz);
				cur = split(right, sz);
				tail = merge(left, right, tail);
			}
		}

		return dummy.next;
	}

private:
	/**
	 * Divide the linked list into two lists,
	 * while the first list contains first n ndoes
	 * return the second list's head
	 */
	ListNode* split(ListNode *head, int n) {
		for (int i = 1; head && i < n; i++)
			head = head->next;
		if (!head) return nullptr;
		ListNode *second = head->next;
		head->next = nullptr;
		return second;
	}
	/**
	  * merge the two sorted linked list l1 and l2,
	  * then append the merged sorted linked list to the node head
	  * return the tail of the merged sorted linked list
	 */// tail尾巴
	ListNode* merge(ListNode* l1, ListNode* l2, ListNode* head) {
		ListNode *cur = head;
		while (l1 && l2) {
			if (l1->val > l2->val) {
				cur->next = l2;
				cur = l2;
				l2 = l2->next;
			}
			else {
				cur->next = l1;
				cur = l1;
				l1 = l1->next;
			}
		}
		cur->next = (l1 ? l1 : l2);
		while (cur->next) cur = cur->next;	
		return cur;
	}
};

int main()
{
	Solution s;
	ListNode *l1, *l2, *l3, *l4;
	l1 = new ListNode(4);
	l2 = new ListNode(2);
	l3 = new ListNode(1);
	l4 = new ListNode(3);
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	s.sortList(l1);
	return 0;
}