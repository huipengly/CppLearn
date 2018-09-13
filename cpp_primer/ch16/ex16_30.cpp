#include "my_unique_ptr.h"
#include "Blob_my_shared_ptr.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    Blob<int> bi{1, 2, 3, 4};
    for (auto i = 0; i != bi.size(); ++i)
    {
        cout << bi[i] << endl;
    }

    my_unique_ptr<double> dp = new double(10.1);
    cout << *dp << endl;

    return 0;
}
