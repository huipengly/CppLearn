#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Equal
{
public:
    Equal(int i) : i_(i) {}
    bool operator()(int a)
    {
        return a == i_;
    }
private:
    int i_;
};

int main()
{
    vector<int> vint({1, 2, 3, 4, 5, 4, 3, 3, 5, 8});
    for (auto i : vint)
    {
        cout << i << " ";
    }
    cout << endl;
    replace_if(vint.begin(), vint.end(), Equal(3), 0);
    for (auto i : vint)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}