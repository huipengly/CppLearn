#include <vector>
using std::vector;
#include <algorithm>
using std::sort;

// ����space O(1)�ģ�https://leetcode.com/problems/wiggle-sort-ii/discuss/77677/O(n)%2BO(1)-after-median-Virtual-Indexing

// time: O(nlogn) space: O(n)
class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<int> copy(nums);

		/// ��ֵ����żԪ��
		int i = nums.size() - 1, m = i / 2 + 1, j = 0;
		for (; i >= 0; i--)
			nums[i] = copy[i & 1 ? m++ : j++];

		/// �ҵ�д��
		//auto half = (nums.size()+1) / 2 - 1;
		//for (int i = 0; i < nums.size(); i += 2)
		//{
		//	nums[i] = wiggle[half--];
		//}
		//auto size = nums.size() - 1;
		//for (int i = 1; i < nums.size(); i += 2)
		//{
		//	nums[i] = wiggle[size--];
		//}
	}
};

int main()
{
	vector<int> nums{ 4, 5, 5, 6};
	Solution s;
	s.wiggleSort(nums);
	return 0;
}