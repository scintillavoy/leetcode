#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
    int time_needed = 0;
    sort(processorTime.begin(), processorTime.end());
    sort(tasks.rbegin(), tasks.rend());
    for (int i = 0; i < processorTime.size(); ++i) {
      time_needed = max(time_needed, processorTime[i] + tasks[i * 4]);
    }
    return time_needed;
  }
};
