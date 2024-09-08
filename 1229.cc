#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> minAvailableDuration(vector<vector<int>>& slots1,
                                   vector<vector<int>>& slots2, int duration) {
    sort(slots1.begin(), slots1.end());
    sort(slots2.begin(), slots2.end());
    int i = 0, j = 0;
    while (i < slots1.size() && j < slots2.size()) {
      const vector<int>& slot1 = slots1[i];
      const vector<int>& slot2 = slots2[j];
      int start_time = max(slot1[0], slot2[0]);
      int end_time = min(slot1[1], slot2[1]);
      if (end_time - start_time >= duration) {
        return {start_time, start_time + duration};
      }
      if (slot1[1] < slot2[1]) {
        ++i;
      } else {
        ++j;
      }
    }
    return {};
  }
};
