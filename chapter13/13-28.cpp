#include <iostream>
#include <string>

using namespace std;

class TreeNode{
public:
    TreeNode():value(string()), count(1), left(nullptr), right(nullptr){}
    TreeNode(const TreeNode&);
    ~TreeNode();
    void CopyTree();
    int ReleaseTree();
private:
    string value;
    int count;
    TreeNode *left;
    TreeNode *right;
};

TreeNode::TreeNode(const TreeNode& n):value(n.value), count(1), left(n.left), right(n.right)
{
    if(left){
        left->CopyTree();
    }
    if(right){
        right->CopyTree();
    }
}

void TreeNode::CopyTree()
{
    if(left){
        left->CopyTree();
    }
    if(right){
        left->CopyTree();
    }
    count++;
}

int TreeNode::ReleaseTree()
{
    if(left){
        if(!left->ReleaseTree()){
            delete left;
        }
    }
    if(right){
        if(!right->ReleaseTree()){
            delete right;
        }
    }
    count--;
    return count;
}

TreeNode::~TreeNode()
{
    if(count){
        ReleaseTree();
    }
}

class BinStrTree{
public:
    BinStrTree():root(nullptr){}
    BinStrTree(const BinStrTree&);
    ~BinStrTree();
private:

    TreeNode *root;
};

BinStrTree::BinStrTree(const BinStrTree &n):root(n.root)
{
    root->CopyTree();
}

BinStrTree::~BinStrTree()
{
    if(!root->ReleaseTree()){
        delete root;
    }
}

