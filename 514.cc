#include <algorithm>
#include <cmath>
#include <limits>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int findRotateSteps(string ring, string key) {
    int n = ring.size();
    int m = key.size();
    vector<int> count(n, numeric_limits<int>::max());
    count[0] = 0;
    for (int i = 0; i < m; ++i) {
      vector<int> next_count(n, numeric_limits<int>::max());
      for (int j = 0; j < n; ++j) {
        if (count[j] == numeric_limits<int>::max()) {
          continue;
        }
        for (int k = -n / 2; k <= n / 2; ++k) {
          int rotated_index = j + k;
          if (rotated_index < 0) {
            rotated_index += n;
          } else if (rotated_index >= n) {
            rotated_index -= n;
          }
          if (ring[rotated_index] == key[i]) {
            next_count[rotated_index] =
                min(next_count[rotated_index], count[j] + abs(k) + 1);
          }
        }
      }
      count = next_count;
    }
    return *min_element(count.cbegin(), count.cend());
  }
};
