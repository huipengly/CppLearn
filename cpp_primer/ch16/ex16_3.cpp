#include "compare.h"
#include "../ch14/Sales_data.h"

int main(int argc, char const *argv[])
{
    Sales_data s1, s2;
    // compare.h:7:12: error: no match for ‘operator<’ (operand types are ‘const Sales_data’ and ‘const Sales_data’)
    //  if (v1 < v2) return -1;
    compare(s1, s2);
    return 0;
}
