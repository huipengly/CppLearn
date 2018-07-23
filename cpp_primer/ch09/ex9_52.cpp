#include <string>
using std::string;
#include <stack>
using std::stack;
#include <iostream>
using std::cout; using std::endl;

double calculator(const string &str)
{
    stack<char> function;
    for (auto &s : str)
    {
        function.push(s);
        if (s == ')')
        {
            string parenthesized_expressions;
            while(function.top() != '(')
            {
                parenthesized_expressions.push_back(function.top());
                function.pop();
            }
            function.push(std::to_string(stod(parenthesized_expressions.substr(1, parenthesized_expressions.size() - 1))).c_str);
        }
    }
}

int main()
{

    return 0;
}