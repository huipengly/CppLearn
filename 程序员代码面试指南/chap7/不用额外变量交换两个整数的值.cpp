#include <climits>
#include <iostream>
using namespace std;
void swap_without_temp(int& lhs, int& rhs)
{
	lhs = lhs ^ rhs;
	rhs = rhs ^ lhs;
	lhs = lhs ^ rhs;
}

int main()
{
	int lhs = INT_MAX, rhs = INT_MIN;
	swap_without_temp(lhs, rhs);
	cout << lhs << endl << rhs << endl;
	return 0;
}