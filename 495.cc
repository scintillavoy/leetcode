#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    int total_duration = 0;
    int last_poisoned_time = -1;
    for (const auto ts : timeSeries) {
      total_duration += duration - max(last_poisoned_time - ts + 1, 0);
      last_poisoned_time = ts + duration - 1;
    }
    return total_duration;
  }
};
