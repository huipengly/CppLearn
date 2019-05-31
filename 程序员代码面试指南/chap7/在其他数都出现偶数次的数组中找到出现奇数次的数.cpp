#include <vector>
#include <iostream>
using namespace std;
int printOddTimeNum1(const vector<int>& arr)
{
	int eO = 0;
	for (int i : arr)
		eO ^= i;
	return eO;
}

void printOddTimeNum2(const vector<int>& arr)
{
	int eO = 0, eOhasOne = 0;
	for (int i : arr)
		eO ^= i;
	int rightOne = eO & (~eO + 1);
	for (int i : arr)
	{
		if ((i & rightOne) != 0)
			eOhasOne ^= i;
	}
	eO ^= eOhasOne;
	cout << eO << " " << eOhasOne << endl;
}

int main()
{
	vector<int> arr1{ 1, 2, 3, 4, 5, 4, 3, 2, 1 };
	vector<int> arr2{ 1, 2, 3, 5, 4, 3, 2, 1 };
	cout << printOddTimeNum1(arr1) << endl;
	printOddTimeNum2(arr2);
	return 0;
}