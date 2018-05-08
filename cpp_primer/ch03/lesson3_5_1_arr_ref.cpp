#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int arr[10] = { 0 };
    int (&arr_ref)[10] = arr;
    arr_ref[3] = 9;
    cout << "arr[3] : " << arr_ref[3] << endl;
    return 0 ;
}

