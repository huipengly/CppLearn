#include <string>
using namespace std;

// find如果用kmp就是O(N)的，对于短字符串，find会比kmp还快
class Solution {
public:
	bool rotateString(string A, string B) {
		if (A.size() != B.size())
			return false;
		string B2 = B + B;
		return B2.find(A) != string::npos;
	}
};