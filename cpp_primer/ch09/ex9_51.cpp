#include <string>
using std::string;
#include <iostream>
using std::cout; using std::endl;
#include <vector>
using std::vector;

// 顺便研究了类内初始值问题
// 当在全局定义类的对象时，类内为赋初值的变量为0或默认初始值
// 当在局部定义类的对象时，类内为随机值

class MyDate
{
    friend void print(MyDate date);
public:
    MyDate(const string &str);

private:
    unsigned int day, month, year;
};

MyDate::MyDate(const string &str) : month(0)
{
    const vector<string> svec_month{"Jan", "Feb", "Mar", "April", "May", "June", "July", "Aug", "Sep", "Oct", "Nov", "Dec"};
    for (auto it = svec_month.begin(); it != svec_month.end(); ++it)
    {
        if (str.find(*it) != string::npos)
        {
            month = it - svec_month.begin() + 1;
            break;
        }
    }

    if (month == 0)
    {
        month = stoi(str.substr(str.find_first_of("0123456789")));
        day = stoi(str.substr(str.find_first_of("0123456789", str.find_first_not_of("0123456789"))));
        year = stoi(str.substr(str.find_last_not_of("0123456789") + 1));
    }
    else
    {
        day = stoi(str.substr(str.find_first_of("0123456789")));
        year = stoi(str.substr(str.find_last_not_of("0123456789") + 1));
    }
}

void print(MyDate date)
{
    cout << "year : " << date.year << endl;
    cout << "month : " << date.month << endl;
    cout << "day : " << date.day << endl;
}

MyDate aa("2/5/2001");
int main()
{
    print(MyDate("January 1, 1900"));
    print(MyDate("4/3/1990"));
    print(MyDate("Oct 1 1900"));
    print(aa);
    return 0;
}