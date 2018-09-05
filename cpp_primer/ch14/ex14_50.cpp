struct LongDouble {
    LongDouble(double = 0.0);
    operator double();
    operator float();
};
LongDouble ldObj;
int ex1 = ldObj;    // error ambiguous: double or float?
float ex2 = ldObj;  // legal

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
