#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int largestAltitude(vector<int>& gain) {
    int curr = 0;
    int highest = 0;
    for (const auto g : gain) {
      curr += g;
      highest = max(highest, curr);
    }
    return highest;
  }
};
