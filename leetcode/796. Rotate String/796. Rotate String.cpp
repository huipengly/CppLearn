#include <string>
using namespace std;

// find�����kmp����O(N)�ģ����ڶ��ַ�����find���kmp����
class Solution {
public:
	bool rotateString(string A, string B) {
		if (A.size() != B.size())
			return false;
		string B2 = B + B;
		return B2.find(A) != string::npos;
	}
};