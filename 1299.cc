#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> replaceElements(vector<int>& arr) {
    int last_max = -1;
    for (int i = arr.size() - 1; i >= 0; --i) {
      int current = arr[i];
      arr[i] = last_max;
      last_max = max(last_max, current);
    }
    return arr;
  }
};
