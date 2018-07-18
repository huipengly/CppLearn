#include <list>
using std::list;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <iostream>
using std::cout; using std::endl;

int main()
{
    list<char *> list_of_char;
    vector<string> vector_of_string;

    char s1[] = "hello", s2[] = "world", s3[] = "!";
    list_of_char.push_back(s2);
    list_of_char.push_front(s1);
    list_of_char.push_back(s3);

    vector_of_string.assign(list_of_char.begin(), list_of_char.end());

    for (auto v : vector_of_string)
    {
        cout << v << endl;
    }
    return 0;
}