#include "../ch15/Query.h"

int main(int argc, char const *argv[])
{
    // Query q1{"a"}, q2("b");
    // AndQuery *aqp;
    Query_base *pb1 = new AndQuery(Query("value1"), Query("value2"));
    // QueryBase *qb = new AndQuery(q1, q2);
    return 0;
}
