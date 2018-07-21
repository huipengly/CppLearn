#include <vector>
using std::vector;
#include <string>
using std::string;
#include <iostream>
using std::cout; using std::endl;

int sum_int_vector(const vector<string> &svec)
{
    int sum = 0;
    for (auto &is : svec)           // 用引用好一点，不用拷贝string，而且带上了const属性
    {
        sum += stoi(is);
    }

    return sum;
}

double sum_doube_vector(const vector<string> &svec)
{
    double sum = 0;
    for (auto &is : svec)
    {
        sum += stoi(is);
    }

    return sum;
}

int main()
{
    vector<string> svec = {"12", "34", "55"};

    cout << "use sum_int_vector : " << sum_int_vector(svec) << endl;

    cout << "use sum_double_vector : " << sum_doube_vector(svec) << endl;

    return 0;
}