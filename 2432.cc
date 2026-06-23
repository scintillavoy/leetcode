#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int hardestWorker(int n, vector<vector<int>>& logs) {
    int max_duration = logs[0][1];
    int hardest_worker_id = logs[0][0];
    for (int i = 1; i < logs.size(); ++i) {
      int duration = logs[i][1] - logs[i - 1][1];
      if (max_duration < duration) {
        max_duration = duration;
        hardest_worker_id = logs[i][0];
      } else if (max_duration == duration) {
        hardest_worker_id = min(hardest_worker_id, logs[i][0]);
      }
    }
    return hardest_worker_id;
  }
};
