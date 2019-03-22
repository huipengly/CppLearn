#include <bitset>
#include <iostream>
#include <string>
using namespace std;

void print_to_max_n_digital_small(int n)
{
	for (int i = 1; i < pow(10, n); ++i)
		cout << i << endl;
}

// 大数加法
void print_to_max_n_digital_big(int n)
{
	string str(n, '0');
	//string end_str(n, '9');
	str.back() += 1;
	int offset = 0;
	while (offset != n)
	{
		cout << str.substr(n - 1 - offset) << endl;
		int i = 0;
		for (; i != n; ++i)
		{
			if (str[n - 1 - i] != '9')
			{
				str[n - 1 - i] += 1;
				break;
			}
			else
			{
				str[n - 1 - i] = '0';
			}
		}
		if (i > offset)
			offset = i;
	}

}

void print_to_max_n_digital(int n)
{
	if (n < 0)
		return;
	else if (n < 19)
		print_to_max_n_digital_small(n);
	else
		print_to_max_n_digital_big(n);
}

struct bitS
{
	;
};

int main()
{
	//print_to_max_n_digital(-1);
	//print_to_max_n_digital_big(2);
	cout << sizeof(bitS) << endl;
	return 0;
}