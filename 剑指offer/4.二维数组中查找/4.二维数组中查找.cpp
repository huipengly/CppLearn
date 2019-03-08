// 因为行和列都是有序的，目标找到一个条件，一次能派出一排。从右上角或者左下角开始寻找。这里为左上角
bool Find(int target, vector<vector<int> >& array) {
    if (array.empty() || array[0].empty())
        return false;
    int row = 0;
    int col = array[0].size() - 1;
    while (row < array.size() && col >= 0)
    {
        if (target > array[row][col])
            while (row < array.size() && target > array[row][col]) ++row;
        else if (target < array[row][col])
            while (col >= 0 && target < array[row][col]) --col;
        else 
            return true;
    }
    return false;
}