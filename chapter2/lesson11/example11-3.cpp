#include <stdio.h>

class Test
{
    int i;
    int j;
    int k;
    
    static int c;
public:
    Test(int i, int j, int k)
    {
        this->i = i;
        this->j = j;
        this->k = k;
    }
    
    void print()
    {
        printf("Object Address: %08X\n", this);
   //     printf("&c = %08X, c = %d\n", &c, c);
        printf("&i = %08X, i = %d\n", &i, i);
        printf("&j = %08X, j = %d\n", &j, j);
        printf("&k = %08X, k = %d\n", &k, k);
    }
};

//int Test::c;

int main()
{
    Test t1(0, 1, 2);
    Test t2(3, 4, 5);
    
    printf("t1 Address: %p\n", &t1);
    t1.print();
    printf("t2 Address: %08X\n", &t2);
    t2.print();
    
    printf("Press any key to continue...");
    getchar();
    return 0;
}
