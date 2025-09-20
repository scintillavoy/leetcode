#include <vector>
using namespace std;

class Solution {
 public:
  int buttonWithLongestTime(vector<vector<int>>& events) {
    int index_with_longest_time = 0;
    int longest_time = 0;
    int last_time = 0;
    for (const auto& event : events) {
      int current_time = event[1] - last_time;
      if (current_time > longest_time) {
        index_with_longest_time = event[0];
        longest_time = current_time;
      } else if (current_time == longest_time &&
                 index_with_longest_time > event[0]) {
        index_with_longest_time = event[0];
      }
      last_time = event[1];
    }
    return index_with_longest_time;
  }
};
