struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// Time complexity: O(n)
class Solution {
 public:
  TreeNode *sortedListToBST(ListNode *head) {
    this->head = head;
    int len = 0;
    while (head != nullptr) {
      ++len;
      head = head->next;
    }
    return sortedListToBST(len);
  }
 private:
  ListNode *head;
  TreeNode *sortedListToBST(int len) {
    if (len == 0) return nullptr;
    TreeNode *node = new TreeNode();
    node->left = sortedListToBST(len / 2);
    node->val = this->head->val;
    this->head = this->head->next;
    node->right = sortedListToBST(len - len / 2 - 1);
    return node;
  }
};

int main() { return 0; }
