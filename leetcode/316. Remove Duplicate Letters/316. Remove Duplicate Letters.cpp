#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ���ϵ�ʵ�ַ���
class Solution {
public:
	string removeDuplicateLetters(string str) {
		vector<int> map(26, 0);
		string ret{};
		ret.reserve(26); //	��Ϊֻ��Сд��ĸ�����Է��ص��ַ������ֻ��26λ����ǰ����ռ�
		for (int i = 0; i != str.size(); ++i)
		{
			++map[str[i] - 'a'];
		}
		int l = 0, r = 0;
		while (r != str.size())
		{
			if (map[str[r] - 'a'] == -1 ||
				--map[str[r] - 'a'] > 0)
			{
				++r;
			}
			else
			{
				int pick = -1;
				for (int i = l; i <= r; ++i)
				{
					if (map[str[i] - 'a'] != -1 &&
						(pick == -1 || str[i] < str[pick]))
					{
						pick = i;
					}
				}
				ret += str[pick];
				map[str[pick] - 'a'] = -1;
				for (int i = pick + 1; i <= r; ++i)		// ����Ҫ��pick+1��ʼ����Ϊǰ��Ĳ�����Ҫ��
				{
					if (map[str[i] - 'a'] != -1)
						++map[str[i] - 'a'];
				}
				l = pick + 1;
				r = l;
			}
		}
		return ret;
	}
};

// ���Լ���ʵ�֣���ʵ������Ҫɾ���ַ�����ֻ��Ҫ��ע��Щ����Ҫ�ˣ�����ͳ��Ҳֻ��Ҫͳ��һ��
class Solution_erase {
public:
	string removeDuplicateLetters(string s) {
		vector<int> map(26, 0);
		string ret{};
		int min_c = 26, min_index = -1;
		while (!s.empty())
		{
			// ͳ����Ƶ
			for (int i = 0; i != s.size(); ++i)
			{
				++map[s[i] - 'a'];
			}
			// �ҵ�ĳ���ַ�Ƶ��Ϊ0��ʱ�򣬲����ҵ������������С���ַ�
			for (int i = 0; i != s.size(); ++i)
			{
				int c = s[i] - 'a';
				if (c < min_c)
				{
					min_c = c;
					min_index = i;
				}
				if (--map[c] == 0)
				{
					ret += 'a' + min_c;
					// �Ƴ�ѡ��֮ǰ��
					s.erase(0, min_index);
					// �Ƴ���С���ַ�
					s.erase(remove(s.begin(), s.end(), min_c + 'a'), s.end());
					min_c = 26;
					map = vector<int>(26, 0);
					break;
				}
			}
		}
		return ret;
	}
};

int main()
{
	Solution s;
	cout << s.removeDuplicateLetters("cbacdcbc") << endl;
	return 0;
}