#include <stdio.h>

class Test
{
private:
    int i;
    int j;
    int k;
    
public:
    void initialize()
    {
        i = 0;
        j = 0;
        k = 0;
    }
    
    void print()
    {
        printf("i = %d, j = %d, k = %d\n", i, j, k);
    }
};

int main()
{
    Test t1;
    Test t2;
    Test t3;
    
    t1.print();
    t2.print();
    t3.print();
    
    printf("Press any key to continue...");
    getchar();
    return 0;
}
