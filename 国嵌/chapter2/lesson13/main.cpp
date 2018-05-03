#include <stdio.h>
#include "Array.h"
//my
int main()
{
    Array a1(10);
    Array a2(10);

    //   a1.Array(14);

    for (int i = 0; i < a1.length(); i++)
    {
        a1[i] = 10 - i;
    }

    for (int i = 0; i < a2.length(); i++)
    {
        a1[i] = i;
    }

    if(a1 != a2)
    {
        printf("a1 != a2\n");
    }
    // for (int i = 0; i < a1.length(); i++)
    // {
    //     printf("array[%d] is %d\n", i, a1[i]);
    // }

    a2 = a1;

    if(a1 == a2)
    {
        printf("a1 == a2\n");
    }

    // printf("a3.length = %d\n", a3.length());
    
    // for (int i = 0; i < a3.length(); i++)
    // {
    //     printf("array[%d] is %d\n", i, a3[i]);
    // }

    /*   a1.destroy();
    a2.destroy();*/

    printf("press any key to continue...\n");
    getchar();
    return 0;
}