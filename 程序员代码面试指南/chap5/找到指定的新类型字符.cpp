#include <string>
#include <iostream>
using namespace std;

string PointNewChar(const string& str, int k)
{
	int upperCounter = 0;
	for (int i = k - 1; i >= 0; --i)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			++upperCounter;
		}
		else
			break;
	}
	if (upperCounter % 2 == 1)
	{
		return str.substr(k - 1, 2);
	}
	else if (str[k] >= 'A' && str[k] <= 'Z')
	{
		return str.substr(k, 2);
	}
	else
		return str.substr(k, 1);
}

int main()
{
	cout << PointNewChar("aaABCDEcBCg", 7) << endl;
	cout << PointNewChar("aaABCDEcBCg", 4) << endl;
	cout << PointNewChar("aaABCDEcBCg", 10) << endl;
	return 0;
}