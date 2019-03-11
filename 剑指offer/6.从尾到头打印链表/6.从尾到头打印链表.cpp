// 笔试快速过方法
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> ret;
        ListNode *ptr = head;
        while (ptr != nullptr)
        {
            ret.push_back(ptr->val);
            ptr = ptr->next;
        }
        return vector<int>(ret.rbegin(), ret.rend());
    }
};

// 修改原始数据方法
