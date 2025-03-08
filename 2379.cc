#include <algorithm>
#include <string>
using namespace std;

class Solution {
 public:
  int minimumRecolors(string blocks, int k) {
    int num_of_whites = 0;
    int min_recolors = k;
    for (int i = 0; i < blocks.size(); ++i) {
      if (blocks[i] == 'W') {
        ++num_of_whites;
      }
      if (i >= k - 1) {
        min_recolors = min(min_recolors, num_of_whites);
        if (blocks[i - k + 1] == 'W') {
          --num_of_whites;
        }
      }
    }
    return min_recolors;
  }
};
