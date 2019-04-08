#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void print_probability(int n)
{
	vector<int> count(6 * n + 1, 0);
	vector<int> count_aux(6 * n + 1, 0);
	for (int i = 1; i <= 6; ++i)
		count[i] = 1;

	for (int i = 2; i <= n; ++i)
	{
		for (int j = 0; j < i; ++j)
			count_aux[j] = 0;
		for (int j = i; j <= 6 * i; ++j)
		{
			count_aux[j] = 0;
			for (int k = 1; k <= j && k <= 6; ++k)
				count_aux[j] += count[j - k];
		}
		swap(count, count_aux);
	}

	double total = pow(6, n);
	for (int i = n; i != count.size(); ++i)
	{
		cout << i << ": " << scientific << (count[i] / total) << endl;
	}
}

int g_maxValue = 6;
void PrintProbability_Solution2(int number)
{
	if (number < 1)
		return;

	int* pProbabilities[2];
	pProbabilities[0] = new int[g_maxValue * number + 1];
	pProbabilities[1] = new int[g_maxValue * number + 1];
	for (int i = 0; i < g_maxValue * number + 1; ++i)
	{
		pProbabilities[0][i] = 0;
		pProbabilities[1][i] = 0;
	}

	int flag = 0;
	for (int i = 1; i <= g_maxValue; ++i)
		pProbabilities[flag][i] = 1;

	for (int k = 2; k <= number; ++k)
	{
		for (int i = 0; i < k; ++i)
			pProbabilities[1 - flag][i] = 0;

		for (int i = k; i <= g_maxValue * k; ++i)
		{
			pProbabilities[1 - flag][i] = 0;
			for (int j = 1; j <= i && j <= g_maxValue; ++j)
				pProbabilities[1 - flag][i] += pProbabilities[flag][i - j];
		}

		flag = 1 - flag;
	}

	double total = pow((double)g_maxValue, number);
	for (int i = number; i <= g_maxValue * number; ++i)
	{
		double ratio = (double)pProbabilities[flag][i] / total;
		printf("%d: %e\n", i, ratio);
	}

	delete[] pProbabilities[0];
	delete[] pProbabilities[1];
}

int main()
{
	print_probability(4);
	PrintProbability_Solution2(4);
	return 0;
}