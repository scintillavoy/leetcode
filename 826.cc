#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                          vector<int>& worker) {
    vector<pair<int, int>> jobs;
    for (int i = 0; i < difficulty.size(); ++i) {
      jobs.push_back({profit[i], difficulty[i]});
    }
    sort(jobs.begin(), jobs.end(), greater<pair<int, int>>());
    sort(worker.begin(), worker.end(), greater<int>());
    int i = 0, j = 0;
    int result = 0;
    while (i < worker.size() && j < jobs.size()) {
      while (j < jobs.size() && jobs[j].second > worker[i]) {
        ++j;
      }
      if (j == jobs.size()) {
        break;
      }
      result += jobs[j].first;
      ++i;
    }
    return result;
  }
};
