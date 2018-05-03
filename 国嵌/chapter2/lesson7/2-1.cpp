#include <stdio.h>

struct ProgramLanguages
{
    bool run;
};

struct ObjectOriented:ProgramLanguages
{
    int state;
};

struct ProcedureOriented:ProgramLanguages
{
    int state;
};

struct C:ProcedureOriented
{
    void intruduce()
    {
        printf("I'm C\n");
    }
};

struct CPP:ObjectOriented
{
    void intruduce()
    {
        printf("I'm CPP\n");
    }
};

int main()
{
    C c;
    CPP cpp;
    c.run = true;
    cpp.state = 0;
    cpp.run = true;
    cpp.state = 1;
    printf("C is %d.\n", c.state);
    printf("CPP is %d.\n", cpp.state);
    c.intruduce();
    cpp.intruduce();
    return 0;
}