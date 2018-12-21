#include <iostream>
using std::cout; using std::cin; using std::endl;
#include <vector>
using std::vector;
#include <set>
using std::set;

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        // zero or one element in list
        if (head == NULL || head->next ==NULL){
            return head;
        }

        ListNode *pSorted = NULL;
        while ( head != NULL  ){
            /* remember the head */
            ListNode *pHead = head;
            /* trailing pointer for efficient splice */
            ListNode **ppTrail = &pSorted;

            /* pop head off list */
            head = head->next;

            /* splice head into sorted list at proper place */
            while( *ppTrail!=NULL && pHead->val > (*ppTrail)->val )  {
                ppTrail = &(*ppTrail)->next;
            }
            pHead->next = *ppTrail;
            *ppTrail = pHead;
        }

        return pSorted;
    }
};

int main()
{
	Solution s;
	vector<int> v1{ 1, 2, 2, 1 }, v2{ 2, 2 };
	for (auto i : s.intersection(v1, v2))
	{
		cout << i << endl;
	}
	return 0;
}