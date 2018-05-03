#include <stdio.h>
#include "Array.h"
//my
int main()
{
    Array a1(10);

    //   a1.Array(14);

    for (int i = 0; i < a1.length(); i++)
    {
        a1.setArray(i, 10 - i);
    }

    for (int i = 0; i < a1.length(); i++)
    {
        printf("array[%d] is %d\n", i, a1.showArray(i));
    }

    Array a2 = a1;

    for (int i = 0; i < a2.length(); i++)
    {
        printf("array[%d] is %d\n", i, a2.showArray(i));
    }

    /*   a1.destroy();
    a2.destroy();*/

    printf("press any key to continue...\n");
    getchar();
    return 0;
}