/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *ptr = dummy;
        int buffer = 0;
        while (l1 != nullptr || l2 != nullptr)
        {
            int val = buffer;
                //l1->val + l2->val + buffer;
            val += l1 != nullptr ? l1->val : 0;
            val += l2 != nullptr ? l2->val : 0;
            if (val > 9)
            {
                buffer = 1;
                val -= 10;
            }
            else
                buffer = 0;
            ptr->next = new ListNode(val);
            ptr = ptr->next;
            l1 = l1 != nullptr ? l1->next : nullptr;
            l2 = l2 != nullptr ? l2->next : nullptr;
        }
        
        if (buffer != 0)
            ptr->next = new ListNode(1);
        
        return dummy->next;
    }
};