#include <vector>
#include <iostream>
using namespace std;

int getMinUnsortedLenght(const vector<int>& arr)
{
	if (arr.empty())
		return 0;
	int noMaxIndex = -1;
	int max = arr[0];
	for (int i = 1; i != arr.size(); ++i)
	{
		if (arr[i] < max)
			noMaxIndex = i;
		else
			max = arr[i];
	}
	if (noMaxIndex == -1)
		return 0;
	int noMinIndex = -1;
	int min = arr.back();
	for (int i = arr.size() - 2; i >= 0; --i)
	{
		if (arr[i] > min)
			noMinIndex = i;
		else
			min = arr[i];
	}
	return noMaxIndex - noMinIndex + 1;
}

int main()
{
	cout << getMinUnsortedLenght({ 1, 5, 2, 4, 2, 6, 7 }) << endl;
	cout << getMinUnsortedLenght({ 1, 3, 4, 2, 3, 5 }) << endl;
	return 0;
}