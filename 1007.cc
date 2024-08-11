#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

class Solution {
 public:
  int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
    int min_count = min({count_swaps(tops[0], tops, bottoms),
                         count_swaps(bottoms[0], bottoms, tops),
                         count_swaps(tops[0], bottoms, tops) + 1,
                         count_swaps(bottoms[0], tops, bottoms) + 1});
    return min_count >= numeric_limits<int>::max() - 1 ? -1 : min_count;
  }

 private:
  int count_swaps(int value, const vector<int>& tops,
                  const vector<int>& bottoms) {
    int count = 0;
    bool valid = true;
    for (int i = 1; i < tops.size(); ++i) {
      if (tops[i] == value) {
        continue;
      }
      if (bottoms[i] == value) {
        ++count;
        continue;
      }
      valid = false;
      break;
    }
    return valid ? count : numeric_limits<int>::max() - 1;
  }
};
