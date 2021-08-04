#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;

  ListNode() : val(0), next(nullptr) {}
  ListNode(int v) : val(v), next(nullptr) {}

  int getVal() const {
    return val;
  }

  void setNext(ListNode *n) {
    next = n;
  }

  void print() const {
    cout << val << " ";
    ListNode *n = this->next;
    while (n != nullptr) {
      cout << n->getVal() << " ";
      n = n->next;
    }
    cout << endl;
    return;
  }
};

class Solution {
public:
  vector<int> reversePrint(ListNode* head) {
    vector<int> ret;
    stack<int> st;
    ListNode *n = head;
    while (n != nullptr) {
      st.push(n->val);
      n = n->next;
    }
    while (!st.empty()) {
      ret.push_back(st.top());
      st.pop();
    }
    return ret;
  }
};

int main() {
  ListNode *node1 = new ListNode(1);
  ListNode *node2 = new ListNode(2);
  ListNode *node3 = new ListNode(3);
  ListNode *node4 = new ListNode(4);
  ListNode *node5 = new ListNode(5);
  node1->setNext(node2);
  node2->setNext(node3);
  node3->setNext(node4);
  node4->setNext(node5);

  node1->print();

  Solution so;
  vector<int> ret;
  ret = so.reversePrint(node1);

  for (auto a : ret) {
    cout << a << " ";
  }
  cout << endl;

  //=======
  ListNode *node0 = new ListNode();
  node0->print();

  Solution so2;
  vector<int> ret2;
  ret2 = so2.reversePrint(node0);

  for (auto a : ret2) {
    cout << a << " ";
  }
  cout << endl;

  return 0;
}
