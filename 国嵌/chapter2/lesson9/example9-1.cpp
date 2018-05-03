#include <stdio.h>

class Test
{
private:
    int i;
public:
    void initialize()
    {
        i = 0;
    }
    
    int getI()
    {
        return i;
    }
};

int main()
{
    Test t1;
    Test t2;
    Test t3;
    
    t1.initialize();
    t2.initialize();
    t3.initialize();
    
    printf("t1.i = %d\n", t1.getI());
    printf("t2.i = %d\n", t2.getI());
    printf("t3.i = %d\n", t3.getI());
    
    printf("Press any key to continue...");
    getchar();
    return 0;
}
