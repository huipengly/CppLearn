#include <vector>
using std::vector;
#include <iostream>
using std::cout; using std::endl;

int main()
{
    vector<int> ivec;
    // cout << ivec.at(0) << endl;      // terminate called after throwing an instance of 'std::out_of_range'
    // cout << ivec[0] << endl;         // segmentation fault
    // cout << ivec.front() << endl;    // segmentation fault
    // cout << ivec.back() << endl;     // segmentation fault
    return 0;
}