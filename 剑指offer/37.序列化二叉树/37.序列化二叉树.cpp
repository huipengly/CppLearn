#include <string>
#include <queue>
#include <sstream>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(nullptr), right(nullptr) {
	}
};

class Solution {
public:
	char* Serialize(TreeNode *root) {
		if (root == nullptr)
			return nullptr;

		auto str = SerializeCore(root);
		char *ret = new char[str.length() + 1];
		int i;
		for (i = 0; i < str.length(); i++) {
			ret[i] = str[i];
		}
		ret[i] = '\0';
		return ret;
	}
	TreeNode* Deserialize(char *str) {
		if (str == nullptr || *str == '\0')
			return nullptr;

		return Deserialize(&str);
	}
private:
	string SerializeCore(TreeNode *root)
	{
		if (root == nullptr)
			return "#,";

		string ret{to_string(root->val) + ","};
		ret += SerializeCore(root->left);
		ret += SerializeCore(root->right);
		return ret;
	}
	TreeNode *Deserialize(char **str)
	{
		if (**str == '#')
		{
			++(*str);
			++(*str);
			return nullptr;
		}

		int val = 0;
		while (**str != '\0' && **str != ',')
		{
			val = 10 * val + **str - '0';
			++(*str);
		}

		TreeNode *root = new TreeNode(val);
		if (**str == '\0')
			return root;
		else
			++(*str);

		root->left = Deserialize(str);
		root->right = Deserialize(str);
		return root;
	}
};

int main()
{
	Solution s;
	//char *str = new char[1000]{ "1,2, #, #,3, #, #" };
	TreeNode *head = new TreeNode(1);
	head->left = new TreeNode(2);
	head->right = new TreeNode(3);
	auto *root = s.Serialize(head);
	auto *h = s.Deserialize(root);
	return 0;
}