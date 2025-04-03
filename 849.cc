#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxDistToClosest(vector<int>& seats) {
    int max_distance = 0;
    int gap = 0;
    int index = 0;
    while (seats[index] == 0) {
      ++gap;
      ++index;
    }
    max_distance = gap;
    gap = 0;
    ++index;
    while (index < seats.size()) {
      if (seats[index] == 0) {
        ++gap;
      } else {
        max_distance = max(max_distance, (gap + 1) / 2);
        gap = 0;
      }
      ++index;
    }
    max_distance = max(max_distance, gap);
    return max_distance;
  }
};
