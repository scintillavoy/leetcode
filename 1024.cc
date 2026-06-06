#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int videoStitching(vector<vector<int>>& clips, int time) {
    // ends[i]: end times of clips starting at i.
    vector<vector<int>> ends(101);
    for (const auto& clip : clips) {
      ends[clip[0]].push_back(clip[1]);
    }
    int min_number_of_clips = 0;
    int last_end = 0;
    int i = 0;
    while (last_end < time) {
      int max_end = -1;
      while (i <= last_end && i < ends.size()) {
        for (const auto& end : ends[i]) {
          max_end = max(max_end, end);
        }
        ++i;
      }
      if (max_end == -1) {
        return -1;
      }
      ++min_number_of_clips;
      last_end = max_end;
    }
    return min_number_of_clips;
  }
};
