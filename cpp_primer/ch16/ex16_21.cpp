#include "DebugDelete.h"

int main(int argc, char const *argv[])
{
    int *p = new int(10);
    DebugDelete()(p);
    return 0;
}
