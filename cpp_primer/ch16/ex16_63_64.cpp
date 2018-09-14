#include <iostream>
#include <vector>
using namespace std;

template <typename T>
std::size_t count_in_vector(const std::vector<T> &tvec, const T &value)
{
    std::size_t counter = 0;
    for (auto t : tvec)
    {
        if (t == value)
            ++counter;
    }
    return counter;
}

template<>
std::size_t count_in_vector(const std::vector<const char *> &tvec, const char *const &value)
{
    std::size_t counter = 0;
    for (auto t : tvec)
    {
        if (*t == *value)
            ++counter;
    }
    return counter;
}

int main(int argc, char const *argv[])
{
    vector<int> ivec{0, 1, 2, 3, 4, 2, 2, 3, 4};
    vector<const char*> cvec{"123", "2345", "123", "456", "908"};
    const char *pc = "123";
    cout << count_in_vector(ivec, 2) << endl;
    cout << count_in_vector(cvec, pc) << endl;
    return 0;
}
