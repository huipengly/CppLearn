int Fibonacci(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int Fibonacci(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	int l = 1, ll = 0;
	for (int i = 2; i <= n; ++i)
	{
		int temp = l;
		l += ll;
		ll = temp;
	}
	return l;
}