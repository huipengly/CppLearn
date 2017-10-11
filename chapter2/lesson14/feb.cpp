#include "feb.h"

int feb1(int i)
{
    int a = 0;
    int b = 1;
    int ret = 0;

    for(int count = 0; count < i; count++)
    {
        ret = b;

        b += a;
        a = ret;
    }

    return ret;
}

int feb2()
{
    static int a = 0;
    static int b = 1;
    int ret;

    ret  = b;

    b += a;
    a = ret;

    return ret;
}

feb::feb()
{
    a = 0;
    b = 1;
}

int feb::febc()
{
    int ret;
    
    ret  = b;

    b += a;
    a = ret;

    return ret;
}