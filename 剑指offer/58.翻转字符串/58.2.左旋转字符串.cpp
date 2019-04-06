#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	string LeftRotateString(string str, int n) {
		reverse(str.begin(), str.end());
		reverse(str.begin(), str.end() - n);
		reverse(str.end() - n, str.end());
		return str;
	}
};