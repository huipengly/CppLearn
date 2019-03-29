#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		auto it_push = pushV.begin(), it_pop = popV.begin();
		stack<int> aux;
		while (it_pop != popV.end())
		{
			if (!aux.empty() && aux.top() == *it_pop)
			{
				++it_pop;
				aux.pop();
			}
			else
			{
				if (it_push == pushV.end())
					break;
				else if (*it_pop != *it_push)
				{
					aux.push(*it_push);
					++it_push;
				}
				else if (*it_pop == *it_push)
				{
					++it_pop;
					++it_push;
				}
			}
		}

		return it_pop == popV.end();
	}
};

int main()
{
	Solution s;
	cout << s.IsPopOrder({ 1, 2, 3, 4, 5 }, { 1, 2, 3, 4, 5 }) << endl;
	return 0;
}