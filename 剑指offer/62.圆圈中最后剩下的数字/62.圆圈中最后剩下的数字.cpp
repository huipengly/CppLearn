#include <memory>
using namespace std;

class Solution {
public:
	int LastRemaining_Solution(int n, int m)
	{
		if (n < 1 || m < 1)
			return -1;

		int ret = 0;
		for (int i = 2; i <= n; ++i)
		{
			ret = (ret + m) % i;
		}
		return ret;
	}
};

// 时间O(mn)，内存O(n)
//class Solution {
//public:
//	int LastRemaining_Solution(int n, int m)
//	{
//		auto root = new ListNode(0);
//		auto ptr = root;
//		for (int i = 1; i != n; ++i)
//		{
//			ptr->next = new ListNode(i);
//			ptr = ptr->next;
//		}
//
//		ptr->next = root;
//		ptr = root;
//
//		while (ptr->next != ptr)
//		{
//			for (int i = 0; i != m - 2; ++i)
//				ptr = ptr->next;
//			ptr->next = ptr->next->next;
//			ptr = ptr->next;
//		}
//
//		return ptr->val;
//	}
//private:
//	struct ListNode
//	{
//		int val;
//		ListNode* next;
//		ListNode(int v) : val(v), next(nullptr) {}
//	};
//};

int main()
{
	Solution s;
	auto ret = s.LastRemaining_Solution(5, 3);
	return 0;
}