#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

class Node {
 public:
  int val;
  vector<Node*> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
 public:
  vector<int> postorder(Node* root) {
    if (root == nullptr) {
      return {};
    }
    vector<int> result;
    stack<Node*> stk;
    stk.push(root);
    while (!stk.empty()) {
      Node* curr = stk.top();
      stk.pop();
      result.push_back(curr->val);
      for (auto it = curr->children.cbegin(); it != curr->children.cend();
           ++it) {
        stk.push(*it);
      }
    }
    reverse(result.begin(), result.end());
    return result;
  }
};
