class X;
class Y;

class X
{
    Y *py;
};

class Y
{
    X x;
};

int main()
{
    X x1;
    Y y1;
    return 0;
}