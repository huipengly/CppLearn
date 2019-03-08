// 时间o(nlogn)，空间o(logn)
bool duplicate(int numbers[], int length, int* duplication) {
	if (length == 0)
		return false;
	std::sort(numbers, numbers + length);
	for (int i = 0; i != length - 1; ++i)
	{
		if (numbers[i] == numbers[i + 1])
		{
			*duplication = numbers[i];
			return true;
		}
	}
	return false;
}

// 时间o(n)，空间o(n)
bool duplicate(int numbers[], int length, int* duplication) {
	int *hash = new int[length]();
	for (int i = 0; i != length; ++i)
	{
		++hash[numbers[i]];
		if (hash[numbers[i]] > 1)
		{
			*duplication = numbers[i];
			return true;
		}
	}
	return false;
}

// 时间o(n)，空间o(1)
bool duplicate(int numbers[], int length, int* duplication) {
    for (int i = 0; i != length; ++i)
    {
        while (i != numbers[i])
        {
            auto next_i = numbers[i];
            if (next_i == numbers[next_i])
            {
                *duplication = next_i;
                return true;
            }
            std::swap(numbers[i], numbers[next_i]);
            i = next_i;
        }
    }
    return false;
}
