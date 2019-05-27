#include <iostream>
using namespace std;
int add_with_bitwise_operation(int lhs, int rhs)
{
	int add_without_carry = lhs ^ rhs;
	int carry = (lhs & rhs) << 1;
	lhs = add_without_carry;
	rhs = carry;
	while (rhs != 0)
	{
		add_without_carry = lhs ^ rhs;
		carry = (lhs & rhs) << 1;
		lhs = add_without_carry;
		rhs = carry;
	}
	return lhs;
}

// -n为n取反加一
int negNum(int n)
{
	return add_with_bitwise_operation(~n, 1);
}

// a-b = a + (-b)
int minus_with_bitwise_operation(int lhs, int rhs)
{
	return add_with_bitwise_operation(lhs, negNum(rhs));
}

int multi_with_bitwise_operation(int lhs, int rhs)
{
	int res = 0;
	while (rhs != 0)
	{
		res += (rhs & 1) == 1 ? lhs : 0;
		lhs <<= 1;
		rhs >>= 1;
	}
	return res;
}

int isNeg(int n)
{
	return (n & (1 << 31));
}

int divide_with_bitwise_operation_core(int lhs, int rhs)
{
	int l = isNeg(lhs) ? negNum(lhs) : lhs;
	int r = isNeg(rhs) ? negNum(rhs) : rhs;
	int res = 0;
	for (int i = 31; i >= 0; i = minus_with_bitwise_operation(i, 1))
	{
		if ((l >> i) >= r)
		{
			res |= 1 << i;
			l = minus_with_bitwise_operation(l, r << i);
		}
	}
	return isNeg(lhs) ^ isNeg(rhs) ? negNum(res) : res;
}

int divide_with_bitwise_operation(int lhs, int rhs)
{
	if (rhs == 0)
		throw invalid_argument("divisor is 0.");
	if (lhs == INT_MIN && rhs == INT_MIN)
		return 1;
	else if (rhs == INT_MIN)
		return 0;
	else if (lhs == INT_MIN)
	{
		int res = divide_with_bitwise_operation_core(add_with_bitwise_operation(lhs, 1), rhs);
		int rest = divide_with_bitwise_operation_core(
			minus_with_bitwise_operation(res, multi_with_bitwise_operation(res, rhs)), rhs);
		return add_with_bitwise_operation(res, rest);
	}
	else
		return divide_with_bitwise_operation_core(lhs, rhs);
}

int main()
{
	cout << add_with_bitwise_operation(15, 67) << endl;
	cout << minus_with_bitwise_operation(15, 67) << endl;
	cout << multi_with_bitwise_operation(32, 96) << endl;
	cout << divide_with_bitwise_operation(64, 8) << endl;
	return 0;
}