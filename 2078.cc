#include <vector>
using namespace std;

class Solution {
 public:
  int maxDistance(vector<int>& colors) {
    for (int i = 0; i <= colors.size() / 2; ++i) {
      if (colors[i] != colors[0] ||
          colors[colors.size() - 1 - i] != colors[0]) {
        return colors.size() - 1 - i;
      }
    }
    return -1;
  }
};
