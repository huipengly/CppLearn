#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
using namespace std::placeholders;

int main(int argc, char const *argv[])
{
    vector<string> str_vec{"", "1", "", "", "23", "4342"};

    function<bool (const string&)> fcn(&string::empty);
    cout << count_if(str_vec.begin(), str_vec.end(), fcn) << endl;

    cout << count_if(str_vec.begin(), str_vec.end(), mem_fn(&string::empty)) << endl;    // Hints: 记得取地址

    cout << count_if(str_vec.begin(), str_vec.end(), bind(&string::empty, _1)) << endl;
    return 0;
}
