#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int countPoints(string rings) {
    vector<vector<bool>> rods(10, vector<bool>(3));
    for (int i = 0; i < rings.size(); i += 2) {
      int color;
      switch (rings[i]) {
        case 'R':
          color = 0;
          break;
        case 'G':
          color = 1;
          break;
        case 'B':
          color = 2;
          break;
      }
      rods[rings[i + 1] - '0'][color] = true;
    }
    int count = 0;
    for (const auto &rod : rods) {
      if (rod[0] && rod[1] && rod[2]) {
        ++count;
      }
    }
    return count;
  }
};
