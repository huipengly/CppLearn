#include <string>
#include <iostream>
using namespace std;
void replace(string& str, int N)
{
	int blankCounter = 0;
	for (int i = 0; i != N; ++i)
	{
		if (str[i] == ' ')
			++blankCounter;
	}
	for (int i = N + 2 * blankCounter - 1, j = N - 1; j >= 0; --j)
	{
		if (str[j] != ' ')
			str[i--] = str[j];
		else
		{
			str[i--] = '0';
			str[i--] = '2';
			str[i--] = '%';
		}
	}
}

void modify(string& str)
{
	int j = str.size() - 1;
	for (int i = str.size() - 1; i >= 0; --i)
	{
		if (str[i] != '*')
			str[j--] = str[i];
	}
	while (j >= 0)
		str[j--] = '*';
}

int main()
{
	string str{ "a b  c" };
	str.resize(100);
	replace(str, 6);
	cout << str << endl;
	return 0;
}