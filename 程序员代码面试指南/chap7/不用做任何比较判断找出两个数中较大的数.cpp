// 翻转结果，n为1返回0，0返回1
int flip(int n)
{
	return n ^ 1;
}

int sign(int n)
{
	return (n >> 31 & 1);
}

int max_without_compare(int a, int b)
{
	int c = a - b;
	int sa = sign(a);
	int sb = sign(b);
	int sc = sign(c);
	int difSab = sa ^ sb;			// 异号为1
	int sameSab = flip(difSab);		// 同号为1
	int returnA = difSab * sa + sameSab * sc;	// 如果异号，且sa为正，或者同号，sc为正。返回a
	int returnB = flip(returnA);
	return a * returnA + b * returnB;
}