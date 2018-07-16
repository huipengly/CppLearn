#include <vector>
using std::vector;

class Example {
public:
	static constexpr double rate = 6.5;
	static const int vecSize = 20;
    // vector<double> vec(vecSize);
    double vec[vecSize];
};

constexpr double Example::rate;
// vector<double> Example::vec;

int main()
{
    return 0;
}