#include <stack>
#include <iostream>
using std::stack;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

/*
链接：https://www.nowcoder.com/questionTerminal/75e878df47f24fdc9dc3e400ec6058ca
来源：牛客网

递归的方法其实是非常巧的，它利用递归走到链表的末端，然后再更新每一个node的next 值 ，
实现链表的反转。而newhead 的值没有发生改变，为该链表的最后一个结点，所以，反转后，我们可以得到新链表的head。
*/

/*
下面注释我写的递归传递了tail这个值，但是反转的链表的tail可以直接通过pHead.next访问，不需要返回了。
所以我写的很长，这个很短。
* */
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == nullptr || pHead->next == nullptr)
			return pHead;

		auto *new_head = ReverseList(pHead->next);

		pHead->next->next = pHead;
		pHead->next = nullptr;

		return new_head;
	}
};

//class Solution {
//private:
//	struct ListInfo
//	{
//		ListNode *head = nullptr;
//		ListNode *tail = nullptr;
//	};
//	ListInfo ReverseListCore(ListInfo listInfo)
//	{
//		auto *pHead = listInfo.head;
//		if (pHead == nullptr || pHead->next == nullptr)
//			return { pHead, pHead };
//
//		auto retInfo = ReverseListCore({ listInfo.head->next, listInfo.tail });
//		retInfo.tail->next = listInfo.head;
//		listInfo.head->next = nullptr;
//		return { retInfo.head, retInfo.tail->next };
//	}
//public:
//	ListNode* ReverseList(ListNode* pHead) {
//		if (pHead == nullptr || pHead->next == nullptr)
//			return pHead;
//
//		ListNode *tail = pHead;
//		while (tail->next == nullptr)
//			tail = tail->next;
//
//		auto retInfo = ReverseListCore({ pHead, tail });
//		return retInfo.head;
//
//		// 方法3：O(n)不使用额外空间
//		//if (pHead == nullptr || pHead->next == nullptr)
//		//	return pHead;
//
//		//ListNode *new_head = pHead->next, *ptr = pHead;
//		//ptr->next = nullptr;
//
//		//while (new_head->next != nullptr)
//		//{
//		//	auto *temp = new_head->next;
//		//	new_head->next = ptr;
//		//	ptr = new_head;
//		//	new_head = temp;
//		//}
//
//		//new_head->next = ptr;
//
//		//return new_head;
//		
//		// 方法2：暴力解O(n^2)
//		//if (pHead == nullptr || pHead->next == nullptr)
//		//	return pHead;
//
//		//ListNode *nHead = nullptr, *tail = nullptr;
//
//		//while (pHead->next != nullptr)
//		//{
//		//	auto *ptr = pHead;
//		//	while (ptr->next != tail)
//		//	{
//		//		ptr = ptr->next;
//		//	}
//		//	if (nHead == nullptr)
//		//	{
//		//		tail = ptr;
//		//		nHead = ptr;
//		//	}
//		//	else
//		//	{
//		//		tail->next = ptr;
//		//		ptr->next = nullptr;
//		//		tail = ptr;
//		//	}
//		//}
//
//		//return nHead;
//
//		// 方法1：使用栈，O(n)，额外空间O(n)
//		//if (pHead == nullptr)
//		//	return nullptr;
//		//stack<ListNode *> stack;
//		//while (pHead != nullptr)
//		//{
//		//	stack.push(pHead);
//		//	pHead = pHead->next;
//		//}
//		//auto *ret = stack.top();
//		//auto *ptr = ret;
//		//stack.pop();
//		//while (!stack.empty())
//		//{
//		//	ptr->next = stack.top();
//		//	stack.pop();
//		//	ptr = ptr->next;
//		//}
//		//ptr->next = nullptr;
//		//return ret;
//	}
//};

int main()
{
	Solution s;
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head = s.ReverseList(nullptr);
	while (head != nullptr)
	{
		std::cout << head->val << std::endl;
		head = head->next;
	}
	return 0;
}