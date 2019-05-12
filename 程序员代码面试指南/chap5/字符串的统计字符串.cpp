#include <vector>
#include <string>
#include <iostream>
using namespace std;

string getCountString(const string& str)
{
	if (str.empty())
		return "";
	int start = 0;
	string countStr{};
	for (int i = 1; i != str.size(); ++i)
	{
		if (str[i] != str[start])
		{
			if (start != 0)
				countStr += string{ "_" };

			countStr += str[start] + string{ "_" } +to_string(i - start);
			start = i;
		}
	}
	countStr += string{ "_" } + str[start] + string{ "_" } + to_string(str.size() - start);
	return countStr;
}

// 本来想先切分，然后二分查找，因为c++不能直接切分，所以这个方法其实并不好，不如在切分阶段就判断index.
char myGetCharAt(const string& str, int index)
{
	if (str.empty() || index < 0)
		return '\0';
	char ch = str[0];
	int i = 0, j = 0, size = 0;
	while (i < str.size())
	{
		ch = str[i];	// 因为肯定是一位字符，所以直接取字母
		i += 2;
		j = i;
		for (; j <= str.size(); ++j)
		{
			if (j == str.size() || str[j] == '_')
			{
				i = stoi(str.substr(i, j - i));
				size += i;
				break;
			}
		}
		if (size > index)
			return ch;
		i = j + 1;
	}
	return '\0';
}

char getChatAt(const string& str, int index)
{
	if (str.empty() || index < 0)
		return '\0';
	bool stage = true;
	int sum = 0, num = 0;
	char ch;
	for (int i = 0; i != str.size(); ++i)
	{
		if (str[i] == '_')
			stage = !stage;
		else if (stage)
		{
			sum += num;
			if (index < sum)
				return ch;
			num = 0;
			ch = str[i];
		}
		else
		{
			num += 10 * num + str[i];
		}
	}
	return index < (sum + num) ? ch : '\0';
}

int main()
{
	string str{ "aaabbcabfffe" };
	cout << str << endl;
	string countStr = getCountString(str);
	cout << countStr << endl;
	cout << "0 : " << myGetCharAt(countStr, 0) << endl;
	cout << "-1 : " << myGetCharAt(countStr, -1) << endl;
	cout << "5 : " << myGetCharAt(countStr, 5) << endl;
	cout << myGetCharAt("a_1_b_100", 101) << endl;
	return 0;
}