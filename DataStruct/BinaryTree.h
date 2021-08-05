#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct BinaryTreeNode {
  int val;
  BinaryTreeNode *left;
  BinaryTreeNode *right;

  BinaryTreeNode() : val(0), left(nullptr), right(nullptr) {}
  BinaryTreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
  BinaryTreeNode(int v, BinaryTreeNode *l, BinaryTreeNode *r)
    : val(v), left(l), right(r) {}

  void print() const;
};

class BinaryTree {
private:
  BinaryTreeNode *root;
public:
  BinaryTree() : root(new BinaryTreeNode()) {}
  BinaryTree(int v) : root(new BinaryTreeNode(v)){}
  BinaryTree(int v, BinaryTreeNode *l, BinaryTreeNode *r)
    : root(new BinaryTreeNode(v, l, r)) {}

  void preOrderTraverse();
  void inOrderTraverse();
  void postOrderTraverse();
  void layerOrderTraverse();

  void insertNode(int pos, BinaryTreeNode *n, bool isLeft);

  void print() const;
};
