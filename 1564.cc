#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
    sort(boxes.begin(), boxes.end(), greater<int>());
    int pos = 0;
    int result = 0;
    for (int i = 0; i < boxes.size(); ++i) {
      if (pos == warehouse.size()) {
        break;
      }
      if (boxes[i] <= warehouse[pos]) {
        ++pos;
        ++result;
      }
    }
    return result;
  }
};
