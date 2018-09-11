/**
 * @brief 荷兰国旗问题
 * 
 * @file SortColor.cpp
 * @author huipengly
 * @date 2018-09-11
 * @note 算法见https://www.cnblogs.com/gnuhpc/archive/2012/12/21/2828166.html
 */
#include <algorithm>
using std::swap;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        auto beg = nums.begin();
        auto end = nums.end() - 1;
        auto it = beg;
        while (it <= end)
        {
            if (*it == 0)
            {
                swap(*it, *beg);
                ++beg;
                ++it;
            }
            else if (*it == 2)
            {
                swap (*it, *end);
                --end;
            }
            else
                ++it;
        }
    }
};