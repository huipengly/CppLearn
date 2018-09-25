#include "../ch14/Sales_data.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    Sales_data item1, item2, sum;
    while (cin >> item1 >> item2)
    {
        // cout << item1 << endl;
        // cout << item2 << endl;
        try{
            sum = item1 + item2;
        } catch (const isbn_mismatch &e){
            cout << e.what() << ": left isbn(" << e.left << ") right isbn(" << e.right << ")" << endl;
        }
        cout << sum << endl;

        sum = item1 + item2;
        cout << sum << endl;
    }
    return 0;
}
