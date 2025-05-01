#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills,
                    int strength) {
    sort(tasks.begin(), tasks.end());
    sort(workers.begin(), workers.end());
    int low = 0;
    int high = min(tasks.size(), workers.size());
    while (low <= high) {
      int mid = low + (high - low) / 2;
      bool possible = true;
      int remaining_pills = pills;
      deque<int> worker_queue;
      int worker_index = workers.size() - 1;
      for (int i = mid - 1; i >= 0; --i) {
        while (worker_index >= (int)workers.size() - mid &&
               workers[worker_index] + strength >= tasks[i]) {
          worker_queue.push_front(workers[worker_index]);
          --worker_index;
        }
        if (worker_queue.empty()) {
          possible = false;
          break;
        }
        if (worker_queue.back() >= tasks[i]) {
          worker_queue.pop_back();
          continue;
        }
        if (remaining_pills <= 0) {
          possible = false;
          break;
        }
        --remaining_pills;
        worker_queue.pop_front();
      }
      if (!possible) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return low - 1;
  }
};
