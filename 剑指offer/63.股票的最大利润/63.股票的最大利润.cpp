#include <vector>
#include <cstdint>
using namespace std;

int max_profit(const vector<int> &price)
{
	if (price.empty())
		return 0;
	int min_price = price[0];
	int max_profit = 0;
	for (int i = 1; i != price.size(); ++i)
	{
		if (price[i] < min_price)
			min_price = price[i];
		int profit = price[i] - min_price;
		if (profit > max_profit)
			max_profit = profit;
	}
	return max_profit;
}

int main()
{
	auto ret = max_profit({ 9, 11, 8, 5, 7, 12, 16, 14 });
	return 0;
}