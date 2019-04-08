class Solution {
public:
	int Add(int num1, int num2)
	{
		int step1 = num1 ^ num2;
		int step2 = num1 & num2;
		while (step2 != 0)
		{
			num1 = step1;
			num2 = step2 << 1;
			step1 = num1 ^ num2;
			step2 = num1 & num2;
		}
		return step1;
	}
};