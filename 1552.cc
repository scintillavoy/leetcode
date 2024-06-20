#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxDistance(vector<int>& position, int m) {
    sort(position.begin(), position.end());
    int start = 1, end = position.back() - position.front();
    while (start <= end) {
      int mid = start + (end - start) / 2;
      int last = position.front();
      int count = 1;
      for (int i = 1; i < position.size(); ++i) {
        if (position[i] - last >= mid) {
          last = position[i];
          ++count;
          if (count >= m) {
            break;
          }
        }
      }
      if (count < m) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    }
    return start - 1;
  }
};
