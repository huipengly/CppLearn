#include <unordered_map>
using std::unordered_map;

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
			label(x), next(nullptr), random(nullptr) {
	}
};

// 注意，random可能有null！！！
class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		if (pHead == nullptr)
			return nullptr;
		// 第一遍，新节点拷贝，插入原节点后面，相当于建立一个set
		auto *ptr = pHead;
		while (ptr != nullptr)
		{
			auto *next = ptr->next;
			ptr->next = new RandomListNode(ptr->label);
			ptr->next->next = next;
			ptr = next;
		}

		// 第二遍，新节点的random
		ptr = pHead;
		while (ptr != nullptr)
		{
			ptr->next->random = ptr->random == nullptr ? nullptr : ptr->random->next;
			ptr = ptr->next->next;
		}

		// 第三遍，抽出新节点
		RandomListNode *nHead = pHead->next;
		ptr = pHead;
		while (ptr != nullptr)
		{
			auto *next = ptr->next->next;
			ptr->next->next = next == nullptr ? nullptr : next->next;
			ptr->next = next;
			ptr = next;
		}

		return nHead;
	}
};

//class Solution {
//public:
//	RandomListNode* Clone(RandomListNode* pHead)
//	{
//		if (pHead == nullptr)
//			return nullptr;
//		// 第一遍，拷贝正常顺序的，并建立新旧节点map
//		RandomListNode *nHead = new RandomListNode(pHead->label);
//		auto *nptr = nHead;
//		auto *ptr = pHead;
//		unordered_map<RandomListNode *, RandomListNode *> node_map;
//		while (ptr->next != nullptr)
//		{
//			nptr->next = new RandomListNode(ptr->next->label);
//			nptr = nptr->next;
//			ptr = ptr->next;
//			node_map[ptr] = nptr;
//		}
//
//		// 第二遍，拷贝随机数据
//		nptr = nHead;
//		ptr = pHead;
//		while (ptr->next != nullptr)
//		{
//			nptr->random = node_map[ptr->random];
//			nptr = nptr->next;
//			ptr = ptr->next;
//		}
//
//		return nHead;
//	}
//};

int main()
{
	RandomListNode *head = new RandomListNode(1);
	head->next = new RandomListNode(2);
	//head->next->next = new RandomListNode(3);
	//head->next->next->next = new RandomListNode(4);
	head->random = head->next;
	//head->next->random = head;
	Solution s;
	auto *ret = s.Clone(head);
	return 0;
}