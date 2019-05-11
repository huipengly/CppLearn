#include <unordered_map>
#include <vector>
using namespace std;

// 书上的实现
int setPos(const vector<int>& preorder, int l1, int r1,
	const vector<int>& inorder, int l2, int r2,
	vector<int>& postorder, int s, unordered_map<int, int> map)
{
	if (l1 > r1)
		return s;

	postorder[s--] = preorder[l1];
	int i = map[preorder[l1]];
	s = setPos(preorder, r1 - (r2 - i) + 1, r1, inorder, i + 1, r2, postorder, s, map);
	return setPos(preorder, l1 + 1, r1 - (r2 - i), inorder, l2, i - 1, postorder, s, map);
}

vector<int> getPostOrder(const vector<int>& preorder, const vector<int>& inorder)
{
	if (preorder.size() != inorder.size() || preorder.empty())
		return {};
	int size = preorder.size();
	vector<int> postorder(size);
	unordered_map<int, int> map;
	for (int i = 0; i != size; ++i)
		map[inorder[i]] = i;
	setPos(preorder, 0, size - 1, inorder, 0, size - 1, postorder, size - 1, map);
	return postorder;
}

// 我自己的实现，需要传的值多一些，而且每次index都要重新找。书上的方法用一个map实现了，空间换时间。
void process(vector<int>& postorder, int l0, int r0,
	const vector<int>& preorder, int l1, int r1,
	const vector<int>& inorder, int l2, int r2)
{
	if (l1 > r1 || l2 > r2)
		return;

	postorder[r0] = preorder[l1];
	int left_size = 0;
	for (int i = l2; i <= r2; ++i)
	{
		if (inorder[i] == preorder[l1])
			break;
		++left_size;
	}
	process(postorder, l0, l0 + left_size - 1, 
		preorder, l1 + 1, l1 + 1 + left_size - 1, 
		inorder, l2, l2 + left_size - 1);
	process(postorder, l0 + left_size, r0 - 1,
		preorder, l1 + 1 + left_size, r1,
		inorder, l2 + left_size + 1, r2);
}

vector<int> generatePostOrderArrWithPreAndIn(const vector<int>& preorder, const vector<int>& inorder)
{
	if (preorder.size() != inorder.size() || preorder.empty())
		return {};
	int size = preorder.size();
	vector<int> postorder(size);
	process(postorder, 0, size - 1,
		preorder, 0, size - 1,
		inorder, 0, size - 1);
	return postorder;
}

int main()
{
	auto ret = generatePostOrderArrWithPreAndIn({1, 2, 4, 5, 3, 6, 7}, {4, 2, 5, 1, 6, 3, 7});
	auto ret2 = getPostOrder({ 1, 2, 4, 5, 3, 6, 7 }, { 4, 2, 5, 1, 6, 3, 7 });
	return 0;
}