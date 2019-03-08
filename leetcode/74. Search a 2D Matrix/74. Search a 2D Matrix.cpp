// 这个二维数组展开之后是有序的，直接二分查找就行了。
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        int lo = 0;
        int hi = matrix.size() * matrix[0].size() - 1;
        int mid = lo + (hi - lo) / 2;
        int n = matrix[0].size();
        while (lo <= hi)
        {
            auto value = matrix[mid / n][mid % n];
            if (value < target)
                lo = mid + 1;
            else if (value > target)
                hi = mid - 1;
            else
                return true;
            mid = lo + (hi - lo) / 2;
        }
        return false;
    }
};