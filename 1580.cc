#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
    sort(boxes.begin(), boxes.end(), greater<int>());
    int result = 0;
    int left = 0, right = warehouse.size() - 1;
    for (int i = 0; i < boxes.size(); ++i) {
      if (left > right) {
        break;
      }
      if (boxes[i] <= warehouse[left]) {
        ++left;
        ++result;
      } else if (boxes[i] <= warehouse[right]) {
        --right;
        ++result;
      }
    }
    return result;
  }
};
