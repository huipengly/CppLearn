#include <stdio.h>
#include "Operator.h"

int main()
{
    int a(4),b(2);
    double r;
    Operator op;

    op.setOperator('/');
    op.setParameter(a,b);

    if(op.result(r))
    {
        printf("result is %g\n", r);
    }

    return 0;
}
