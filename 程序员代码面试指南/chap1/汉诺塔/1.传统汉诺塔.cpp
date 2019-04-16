#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Hanoi {
public:
	vector<string> getSolution(int n) {
		Tower_of_Hanoi(n, "left", "mid", "right");
		return solutions;
	}
private:
	vector<string> solutions;
	void move(string from, string to)
	{
		solutions.push_back("move from " + from + " to " + to);
	}

	void Tower_of_Hanoi(int n, string from, string mid, string to)
	{
		if (n == 1)
			move(from, to);
		else
		{
			Tower_of_Hanoi(n - 1, from, to, mid);
			move(from, to);
			Tower_of_Hanoi(n - 1, mid, from, to);
		}
	}
};

int main()
{
	Hanoi h;
	auto ret = h.getSolution(3);
	return 0;
}