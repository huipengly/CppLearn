#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ���������ñ�־λ�ж�last���������-1.��ʵ����ֱ�Ӹ�lastһ���ܴ��ֵ�����ˣ������leetcode���
class Solution {
public:
	vector<int> shortestToChar(string S, char C) {
		vector<int> shortestDistance(S.size(), INT_MAX);
		int last = -1;
		for (int i = S.find(C); i != S.size(); ++i)
		{
			if (S[i] == C)
			{
				shortestDistance[i] = 0;
				last = i;
			}
			else if (last != -1)
			{
				shortestDistance[i] = i - last;
			}
		}
		last = -1;
		for (int i = S.size() - 1; i >= 0; --i)
		{
			if (S[i] == C)
			{
				last = i;
			}
			else if (last != -1)
			{
				shortestDistance[i] = std::min(shortestDistance[i], last - i);
			}
		}
		return shortestDistance;
	}
};

// ������뷨��ÿ����һ��C���ͷֱ����������ߣ����ɾ��룬��������ԭ���Ļ��̣����滻�����������
// ��ʵ����ֱ�Ӵ���������һ�����ɾ��룬�ٴ���������һ�飬�̵Ļ����滻ԭ���ľ���
class Solution1 {
public:
	vector<int> shortestToChar(string S, char C) {
		int last = 0;
		vector<int> shortestDistance(S.size(), INT_MAX);
		for (int i = S.find(C); i != S.size(); ++i)		// �ӵ�һ��C��ʼ
		{
			if (S[i] == C)
			{
				shortestDistance[i] = 0;
				for (int j = i - 1; j >= last; --j)
				{
					if (shortestDistance[j] > i - j)
						shortestDistance[j] = i - j;
					else
						break;
				}
				last = i;
			}
			else
			{
				shortestDistance[i] = i - last;
			}
		}
		return shortestDistance;
	}
};

int main()
{
	Solution s;
	auto ret = s.shortestToChar("loveleetcode", 'e');
	for (auto i : ret)
		cout << i << " ";
	return 0;
}