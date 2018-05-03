#include <stdio.h>

class Test
{
private:
    static int cI;
    int j;
public:
    int GetI()
    {
        return j;
    }
    
    static void SetI(int i)
    {
        cI = i;
    }
    
    void print()
    {
        printf("cI = %d\n", cI);
    }
};

//int Test::cI = 0;

int main()
{
//    Test::SetI(5);
    
 //   printf("Test::cI = %d\n", Test::GetI());
    
    Test t1;
    Test t2;
    
 /*   t1.print();
    t2.print();
    
    t1.SetI(10);
    
    t2.print();*/
    
    printf("Test::cI = %d\n", t1.GetI());
    
    printf("Press any key to continue...");
    getchar();
    return 0;
}
