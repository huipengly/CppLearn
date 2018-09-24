#include <random>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    default_random_engine e;
    unsigned int min, max;
    cout << "please input min and max: ";
    cin >> min >> max;
    cout << "set a random seed: ";
    unsigned user_seed;
    cin >> user_seed;
    e.seed(user_seed);
    uniform_int_distribution<unsigned int> u(min, max);     // Hints: 要提供模板实参
    cout << u(e) << endl;
    cout << u(e) << endl;
    cout << u(e) << endl;
    cout << u(e) << endl;
    cout << u(e) << endl;
    return 0;
}
