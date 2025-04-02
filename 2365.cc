#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  long long taskSchedulerII(vector<int>& tasks, int space) {
    unordered_map<int, long long> last_completion_days;
    long long current_day = 0;
    for (const auto task : tasks) {
      ++current_day;
      if (last_completion_days.contains(task)) {
        current_day = max(current_day, last_completion_days[task] + space + 1);
      }
      last_completion_days[task] = current_day;
    }
    return current_day;
  }
};
