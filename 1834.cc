#include <algorithm>
#include <functional>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> getOrder(vector<vector<int>>& tasks) {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                   greater<tuple<int, int, int>>>
        waiting_tasks;
    for (int i = 0; i < tasks.size(); ++i) {
      waiting_tasks.push({tasks[i][0], tasks[i][1], i});
    }
    int curr_time = 0;
    int next_task = 0;
    vector<int> order;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        enqueued_tasks;
    while (order.size() < tasks.size()) {
      if (enqueued_tasks.empty() && !waiting_tasks.empty() &&
          curr_time < get<0>(waiting_tasks.top())) {
        curr_time = get<0>(waiting_tasks.top());
      }
      while (!waiting_tasks.empty() &&
             get<0>(waiting_tasks.top()) <= curr_time) {
        auto [_, processing_time, index] = waiting_tasks.top();
        waiting_tasks.pop();
        enqueued_tasks.push({processing_time, index});
      }
      auto [processing_time, index] = enqueued_tasks.top();
      enqueued_tasks.pop();
      order.push_back(index);
      curr_time = min(curr_time + processing_time, 1'000'000'000);
    }
    return order;
  }
};
