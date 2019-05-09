#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	TreeNode* sortedArrayToBST(const vector<int>& nums) {
		return sortedArrayToBST(nums, 0, nums.size() - 1);
	}
private:
	TreeNode* sortedArrayToBST(const vector<int>& nums, int lo, int hi)
	{
		if (lo > hi)
			return nullptr;
		int mid = lo + (hi - lo) / 2;
		auto* head = new TreeNode(nums[mid]);
		head->left = sortedArrayToBST(nums, lo, mid - 1);
		head->right = sortedArrayToBST(nums, mid + 1, hi);
		return head;
	}
};