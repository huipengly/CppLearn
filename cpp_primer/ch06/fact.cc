#include "Chapter6.h"

//有bug，太大了会溢出
int fact(int n)
{
    if (n > 1)
    {
        return n * fact(n - 1);
    }
    else
    {
        return n;
    }
}
