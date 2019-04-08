#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> multiply(const vector<int>& A) {
		//if (A.empty())
		//	return A;
		//if (A.size() == 1)
		//	return { 1 };
		vector<int> B(A.size(), 1);
		vector<int> C(A.size(), 1);

		for (int i = 1; i != B.size(); ++i)
			B[i] = B[i - 1] * A[i - 1];
		for (int i = C.size() - 2; i >= 0; --i)
			C[i] = C[i + 1] * A[i + 1];

		vector<int> ret(A.size(), 0);
		for (int i = 0; i != ret.size(); ++i)
			ret[i] = B[i] * C[i];
		return ret;
	}
};

int main()
{

	return 0; 
}