#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main()
{
    vector<int> ivec;
    cout << "sizeof(ivec) empty : " << sizeof(ivec) << endl;
    ivec.push_back(10);
    cout << "sizeof<ivec> not empty : " << sizeof(ivec) << endl;
    vector<double> dvec;
    cout << "sizeof(dvec) empty : " << sizeof(dvec) << endl;
    ivec.push_back(10);
    cout << "sizeof<dvec> not empty : " << sizeof(dvec) << endl;
    return 0;
}

// 知乎解释，相当于sizeof(vector)
// iterator start;
// iterator finish;
// iterator end_of_storage;

// 3*8 =  24.