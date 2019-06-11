#include <vector>
using namespace std;

void sort1(vector<int>& arr)
{
	int next = 0, temp = 0;
	for (int i = 0; i != arr.size(); ++i)
	{
		temp = arr[i];
		while (arr[i] != i + 1)
		{
			next = arr[arr[i] - 1];
			arr[arr[i] - 1] = temp;
			temp = next;
		}
	}
}

void sort2(vector<int>& arr)
{
	for (int i = 0; i != arr.size(); ++i)
	{
		while (arr[i] != i + 1)
		{
			std::swap(arr[i], arr[arr[i] - 1]);
		}
	}
}