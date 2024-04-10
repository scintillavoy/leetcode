#include <vector>
using namespace std;

class Solution {
 public:
  bool verifyPreorder(vector<int>& preorder) {
    int parent = 0;
    int min_value = 0;
    for (int i = 1; i < preorder.size(); ++i) {
      while (parent >= 0 && preorder[i] > preorder[parent]) {
        min_value = preorder[parent];
        --parent;
      }
      if (preorder[i] <= min_value) {
        return false;
      }
      ++parent;
      preorder[parent] = preorder[i];
    }
    return true;
  }
};
