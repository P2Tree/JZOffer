#include <iostream>
#include <vector>

#include "../DataStruct/BinaryTree.h"

using namespace std;

class Solution {
public:
  BinaryTreeNode *buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.size() == 0 || inorder.size() != preorder.size())
      return new BinaryTreeNode();

    return construct(preorder.begin(), preorder.end()-1, inorder.begin(), inorder.end()-1);
  }

  BinaryTreeNode *construct(vector<int>::iterator preStart, vector<int>::iterator preEnd,
      vector<int>::iterator inStart, vector<int>::iterator inEnd) {
    int rootValue = *preStart;
    BinaryTreeNode *root = new BinaryTreeNode(rootValue);

    if (preStart == preEnd && inStart == inEnd && *preStart == *inStart) {
      return root;
    }

    auto rootInorder = inStart;
    auto nextRootPreorder = preStart;
    while (rootInorder != inEnd && *rootInorder != rootValue) {
      rootInorder++;
      nextRootPreorder++;
    }

    // Get root node in inorder list
    if (rootInorder != inStart) {
      // construct left sub-tree
      root->left = construct(preStart+1, nextRootPreorder, inStart, rootInorder-1);
    }
    if (rootInorder != inEnd) {
      root->right = construct(nextRootPreorder+1, preEnd, rootInorder+1, inEnd);
    }

    return root;

  }
};

static void test(vector<int>& preorder, vector<int>& inorder) {
  Solution so;
  BinaryTreeNode *ret;
  try {
    ret = so.buildTree(preorder, inorder);
  } catch (int e) {
    cout << e << endl;
  }

  BinaryTree *bt = new BinaryTree(ret);

  bt->print();
  return;
}

int main() {
  vector<int> preorder1 = {3,9,20,15,7};
  vector<int> inorder1 = {9,3,15,20,7};

  test(preorder1, inorder1);
  cout << "Expected result:" << endl;
  cout << "node 3, left 9, right 20" << endl;
  cout << "node 9, left null, right null" << endl;
  cout << "node 20, left 15, right 7" << endl;
  cout << "node 15, left null, right null" << endl;
  cout << "node 7, left null, right null" << endl;
  cout << "===" << endl;

  vector<int> preorder2 = {};
  vector<int> inorder2 = {};

  test(preorder2, inorder2);
  cout << "Expected result:" << endl;
  cout << "node 0, left null, right null" << endl;
  cout << "===" << endl;

  vector<int> preorder3 = {1, 2};
  vector<int> inorder3 = {1};

  test(preorder3, inorder3);
  cout << "Expected result:" << endl;
  cout << "node 0, left null, right null" << endl;
  cout << "===" << endl;

  vector<int> preorder4 = {1, 2};
  vector<int> inorder4 = {2, 1};

  test(preorder4, inorder4);
  cout << "Expected result:" << endl;
  cout << "node 1, left 2, right null" << endl;
  cout << "node 2, left null, right null" << endl;
  cout << "===" << endl;
  return 0;
}
