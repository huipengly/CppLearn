#include <string>

struct Sales_data
{
    std::string bookNo;
    unsigned units_sold;
    double revenue;

    // unsigned units_sold = 0;
    // double revenue = 0.0;
    // 非聚合类，报错
    // ex7_52.cpp: In function ‘int main()’:
    // ex7_52.cpp:28:49: error: could not convert ‘{"978-0590353403", 25, 1.599e+1}’ from ‘<brace-enclosed initializer list>’ to ‘Sales_data’
    //      Sales_data aa = {"978-0590353403", 25, 15.99};

};

int main()
{
    Sales_data aa = {"978-0590353403", 25, 15.99};
    return 0;
}