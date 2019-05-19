int process(int i, int n)
{
	if (i == n - 1)
		return 2;
	else if (i == n)
		return 1;
	return process(i + 1, n) + process(i + 2, n);
}

int getNum1(int n)
{
	if (n < 1)
		return 0;
	return process(1, n);
}