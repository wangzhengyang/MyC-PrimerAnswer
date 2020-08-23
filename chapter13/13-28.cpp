#include <iostream>
#include <string>

using namespace std;

class TreeNode{
public:
    TreeNode():value(string()), count(0), left(new TreeNode()), right(new TreeNode()){}
    TreeNode(const TreeNode&);
    TreeNode &operator=(const TreeNode&);
private:
    string value;
    int count;
    TreeNode *left;
    TreeNode *right;
};

TreeNode::TreeNode(const TreeNode& n)
{
    value = n.value;
    count = n.count;
    left = n.left;
    right = n.right;
}

TreeNode &TreeNode::operator=(const TreeNode &n)
{
    value = n.value;
    count = n.count;
    left = n.left;
    right = n.right;
    return (*this);
}

class BinStrTree{
public:
    BinStrTree():root(new TreeNode()){}
    BinStrTree(const BinStrTree&);
    BinStrTree &operator=(const BinStrTree&);
private:
    TreeNode *root;
};

BinStrTree::BinStrTree(const BinStrTree &n)
{
    root = n.root;
}

BinStrTree &BinStrTree::operator=(const BinStrTree &n)
{
    root = n.root;
    return (*this);
}


