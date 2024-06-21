#include <vector>
using namespace std;

class Solution {
 public:
  int maximizeSweetness(vector<int>& sweetness, int k) {
    int start = 1, end = 1'000'000'000;
    while (start <= end) {
      int mid = start + (end - start) / 2;
      int cuts = 0;
      int sum = 0;
      for (int i = 0; i < sweetness.size(); ++i) {
        sum += sweetness[i];
        if (sum >= mid) {
          sum = 0;
          ++cuts;
        }
      }
      if (sum < mid) {
        --cuts;
      }
      if (cuts < k) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    }
    return start - 1;
  }
};
