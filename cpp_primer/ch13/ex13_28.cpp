/**
 * @brief 练习13.28 未完成，没看懂两个类要干什么
 * 
 * @file ex13_28.cpp
 * @author huipengly
 * @date 2018-09-03
 */
#include <string>

class TreeNode
{
public:
    TreeNode( std::string s = std::string(), TreeNode *l = nullptr, TreeNode *r = nullptr) : value(s), count(1), left(l), right(r) { ++left->count; ++right->count; }
    ~TreeNode()
    {
        if (--left->count == 0)
        {
            delete left;
        }
        if (--right->count == 0)
        {
            delete right;
        }
    }
    // 不需要拷贝构造和拷贝赋值，节点不能赋值
    TreeNode(const TreeNode&) = delete;
    TreeNode& operator=(const TreeNode&) = delete;

private:
    std::string value;
    int count;
    TreeNode *left;
    TreeNode *right;
};

class BinStrTree
{
public:
    BinStrTree() : root(new TreeNode()) {}
    ~BinStrTree() { delete root; }
    // BinStrTree(const BinStrTree& b) : 
private:
    TreeNode *root;
};