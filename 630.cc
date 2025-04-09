#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  int scheduleCourse(vector<vector<int>> &courses) {
    sort(
        courses.begin(), courses.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[1] < b[1]; });
    priority_queue<int> durations;
    int total_duration = 0;
    for (const auto &course : courses) {
      int duration = course[0];
      int last_day = course[1];
      if (total_duration + duration <= last_day) {
        total_duration += duration;
        durations.push(duration);
        continue;
      }
      if (!durations.empty() && durations.top() > duration) {
        total_duration += duration - durations.top();
        durations.pop();
        durations.push(duration);
      }
    }
    return durations.size();
  }
};
