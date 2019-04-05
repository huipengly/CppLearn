#include <cassert>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;
class Solution
{
public:
	Solution() : aux(vector<int>(256, -1)), count(0) {}
	//Insert one char from stringstream
	void Insert(char ch)
	{
		if (aux[ch] == -1)
			aux[ch] = count;
		else
			aux[ch] = -2;
		++count;
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		auto c = First_once();
		return c == -1 ? '#' : c;
	}
private:
	vector<int> aux;
	int count;
	int First_once()
	{
		auto min = INT_MAX;
		auto index = -1;
		for (int i = 0; i != aux.size(); ++i)
		{
			if (aux[i] >= 0 && (min == -1 || aux[i] < min))
			{
				min = aux[i];
				index = i;
			}
		}
		return index;
	}
};

int main()
{
	Solution s;
	string str{ "google" };
	string result{};
	for (auto c : str)
	{
		s.Insert(c);
		result += s.FirstAppearingOnce();
	}
	assert(result == "ggg#ll");
	return 0;
}