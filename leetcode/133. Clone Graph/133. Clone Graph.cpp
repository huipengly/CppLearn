#include <vector>
using std::vector;
#include <unordered_map>
using std::unordered_map;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node == nullptr)
			return nullptr;
		UndirectedGraphNode *root;
		marked.clear();
		root = new UndirectedGraphNode(node->label);
		dfs(root, node);
		return root;
	}
private:
	unordered_map<int, UndirectedGraphNode*> marked;		// 默认使用无需map
	void dfs(UndirectedGraphNode *clone_node, UndirectedGraphNode *node)
	{
		marked[node->label] = clone_node;
		clone_node->neighbors.reserve(node->neighbors.size());	// 使用vector前，若知道大小，先分配内存空间
		for (int i = 0; i != node->neighbors.size(); ++i)
		{
			auto& neighbor = node->neighbors[i];
			if (marked.count(neighbor->label) == 0)	// 如果邻居之前还未读取过，则新建
			{
				marked[neighbor->label] = new UndirectedGraphNode(neighbor->label);
				dfs(marked[neighbor->label], neighbor);
			}
			clone_node->neighbors.push_back(marked[neighbor->label]);	// 添加邻居
		}
	}
};

int main()
{
	UndirectedGraphNode n0(0), n1(1), n2(2);
	n0.neighbors.push_back(&n1);
	n0.neighbors.push_back(&n2);
	n1.neighbors.push_back(&n2);
	n2.neighbors.push_back(&n1);
	Solution s;
	auto n = s.cloneGraph(&n0);
	return 0;
}