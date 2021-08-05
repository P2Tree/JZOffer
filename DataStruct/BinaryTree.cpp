#include <iostream>
#include <vector>
#include <stack>
#include <queue>

#include "BinaryTree.h"

using namespace std;

void BinaryTreeNode::print() const {
  cout << "Val: " << val;
  if (left != nullptr)
    cout << ", Left val: " << left->val;
  else
    cout << ", Left is null";
  if (right != nullptr)
    cout << ", Right val: " << right->val;
  else
    cout << ", Right is null";

  cout << endl;
}

// 存 中 左（走）取 右
void BinaryTree::preOrderTraverse() {
  stack<BinaryTreeNode *> st;
  BinaryTreeNode *node = this->root;
  while (node != nullptr || !st.empty()) {
    if (node) {
      st.push(node);  // 存
      cout << node->val;  // 中
      node = node->left;  // 左（循环continue，找完所有中左）
    } else {
      node = st.top();// 取
      st.pop();
      node = node->right; // 右
    }
  }
  cout << endl;
}

// 存 左（走）取 中 右
void BinaryTree::inOrderTraverse() {
  stack<BinaryTreeNode *> st;
  BinaryTreeNode *node = this->root;
  while (node != nullptr || !st.empty()) {
    if (node) {
      st.push(node);  // 存
      node = node->left;  // 左（循环continue，找完所有左）
    } else {
      node = st.top();// 取
      st.pop();
      cout << node->val;  // 中
      node = node->right; // 右
    }
  }
  cout << endl;
}

// 存 左（走）取（判断走）右 中（保存，删）
void BinaryTree::postOrderTraverse() {
  stack<BinaryTreeNode *> st;
  BinaryTreeNode *node = this->root;
  BinaryTreeNode *tmp = nullptr;

  while (node != nullptr || !st.empty()) {
    if (node != nullptr) {
      st.push(node);  // 存
      node = node->left;  // 左（循环continue，找完所有左）
    } else {
      node = st.top();// 取
      if (node->right && node->right != tmp) { // 检查是否上次看过
        node = node->right; // 右（循环continue）
      } else {
        st.pop(); // pop 在这里
        cout << node->val; // 中
        tmp = node;   // 保存看过的值
        node = nullptr; // 删掉看过的值，下次循环从栈中取
      }
    }
  }
  cout << endl;
}

void BinaryTree::layerOrderTraverse() {
  queue<BinaryTreeNode *> qu;
  BinaryTreeNode *node = this->root;
  qu.push(node);
  while (!qu.empty()) {
    node = qu.front();
    qu.pop();
    cout << node->val;
    if (node->left)
      qu.push(node->left);
    if (node->right)
      qu.push(node->right);
  }
  cout << endl;
}

void BinaryTree::insertNode(int pos, BinaryTreeNode *n, bool isLeft) {
  stack<BinaryTreeNode *> st;
  BinaryTreeNode *node = this->root;
  while (node || !st.empty()) {
    if (node) {
      st.push(node);
      if (node->val == pos) {
        if (isLeft && node->left == nullptr) {
          node->left = n;
          return;
        } else if (!isLeft && node->right == nullptr) {
          node->right = n;
          return;
        }

        throw 1;
      }
      node = node->left;
    } else {
      node = st.top();
      st.pop();
      node = node->right;
    }
  }
}

void BinaryTree::print() const {
  queue<BinaryTreeNode *> st;
  BinaryTreeNode *node;
  st.push(this->root);
  while (!st.empty()) {
    node = st.front();
    st.pop();
    node->print();
    if (node->left)
      st.push(node->left);
    if (node->right)
      st.push(node->right);
  }
}

static int test() {
  BinaryTree *bt = new BinaryTree(1);
  BinaryTreeNode node2 = BinaryTreeNode(2);
  BinaryTreeNode node3 = BinaryTreeNode(3);
  BinaryTreeNode node4 = BinaryTreeNode(4);
  BinaryTreeNode node5 = BinaryTreeNode(5);

  try {
    bt->insertNode(1, &node2, true);
    bt->insertNode(1, &node3, false);
    bt->insertNode(2, &node4, true);
    bt->insertNode(3, &node5, false);
  } catch (int e) {
    if (e == 1) {
      cout << "Error: inserted position already have a node" << endl;
      return 1;
    }
  }

  bt->print();

  cout << "Pre Order: ";
  bt->preOrderTraverse();
  cout << "In Order: ";
  bt->inOrderTraverse();
  cout << "Post Order: ";
  bt->postOrderTraverse();
  cout << "Layer Order: ";
  bt->layerOrderTraverse();

  return 0;
}

