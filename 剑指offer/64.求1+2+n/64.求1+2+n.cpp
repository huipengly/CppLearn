class Temp{
public:
	Temp() { ++count; sum += count; }
	static void reset() { sum = 0; count = 0; }
	static int Sum() { return sum; }
	static int count;
	static int sum;
};

int Temp::count = 0;
int Temp::sum = 0;

class Solution {
public:
	int Sum_Solution(int n) {
		Temp::reset();
		Temp *ptr = new Temp[n];

		delete[] ptr;
		ptr = nullptr;
		return Temp::Sum();
	}
};

int main()
{
	Solution s;
	auto ret = s.Sum_Solution(5);
	return 0;
}