#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findBuildings(vector<int>& heights) {
    vector<int> result;
    result.push_back(heights.size() - 1);
    int max_height = heights.back();
    for (int i = heights.size() - 2; i >= 0; --i) {
      if (heights[i] > max_height) {
        result.push_back(i);
        max_height = heights[i];
      }
    }
    reverse(result.begin(), result.end());
    return result;
  }
};
