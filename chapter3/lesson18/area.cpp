#include <iostream>

using namespace std;

class Plot
{
public:
    virtual double area() = 0;
};

class Rectangle : public plot
{
private:
    double a;
    double b;
public:
    Rectangle(double i, double j)
    {
        a = i;
        b = j;
    }
    double area()
    {
        return a * b;
    }
};

class Circle : public plot
{
private:
    double r;
public:
    Circle(double i)
    {
        r = i;
    }
    double area()
    {
        return 3.14 * r * r;
    }
};

int main()
{
    Rectangle r(1.6,2);
    Circle c(1.2);
    Plot p;

    cout << "r(1.6,2) area is " << r.area() << endl;
    cout << "c(1.2) area is " << c.area() << endl;

    return 0;
}