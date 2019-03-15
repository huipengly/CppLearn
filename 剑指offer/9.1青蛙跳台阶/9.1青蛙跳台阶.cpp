class Solution {
public:
    int dpfun(int number){
        if (number < 0)
            return 0;
        if (dp[number] == -1)
            dp[number] = dpfun(number - 2) + dpfun(number - 1);
        return dp[number];
    }
    int jumpFloor(int number) {
        dp = vector<int>(number + 1, -1);
        dp[0] = 1;
        return dpfun(number);
    }
private:
    vector<int> dp;
};

int Fibonacci(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	int l = 1, ll = 1;  // 这里和斐波那契不同
	for (int i = 2; i <= n; ++i)
	{
		int temp = l;
		l += ll;
		ll = temp;
	}
	return l;
}