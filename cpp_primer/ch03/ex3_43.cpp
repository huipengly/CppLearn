#include <iostream>
#include <iterator>

using std::cout;
using std::endl;
using std::begin;
using std::end;

int main()
{
    int ia[3][4] = { 0 };
    // ver.1:范围for
    cout << "ver.1" << endl;
    for (int (&row)[4] : ia)
    {
        for (int col : row)
        {
            cout << col << ' ';
        }
        cout << endl;
    }
    //ver.2:普通for，用下标
    cout << "ver.2" << endl;
    for (size_t row = 0; row < 3; ++row)
    {
        for (size_t col = 0; col < 4; ++col)
        {
            cout << ia[row][col] << ' ';
        }
        cout << endl;
    }
    //ver.3:普通for，用指针
    cout << "ver.3" << endl;
    for (int (*row)[4] = begin(ia); row != end(ia); ++row)//row是指向4个元素的整形数组的指针，*row就是int[4]
    {
        for (int *col = begin(*row); col != end(*row); ++col)
        {
            cout << *col << ' ';
        }
        cout << endl;
    }
    return 0;
}