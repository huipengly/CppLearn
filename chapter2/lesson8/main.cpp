#include <stdio.h>
#include <Operator.h>

int main()
{
    int a(4),b(2);
    double r;
    Operator op;

    op.setOperator('/');
    op.setParameter(a,b);
    printf("````````````\n");
    if(op.result(r))
    {
        printf("result is %g\n", r);
    }
    else
    {
        printf("false\n");
    }

    return 0;
}