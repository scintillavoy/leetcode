#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxDistance(vector<vector<int>>& arrays) {
    int max_distance = 0;
    int min_val = arrays.front().front();
    int max_val = arrays.front().back();
    for (int i = 1; i < arrays.size(); ++i) {
      max_distance = max({max_distance, abs(arrays[i].back() - min_val),
                          abs(max_val - arrays[i].front())});
      min_val = min(min_val, arrays[i].front());
      max_val = max(max_val, arrays[i].back());
    }
    return max_distance;
  }
};
