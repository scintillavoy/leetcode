#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                    vector<int>& profit) {
    int n = startTime.size();
    vector<Job> jobs(n);
    for (int i = 0; i < n; ++i) {
      jobs[i] = {startTime[i], endTime[i], profit[i]};
    }
    sort(jobs.begin(), jobs.end());
    vector<int> dp(n);
    dp[n - 1] = jobs[n - 1].profit;
    for (int i = n - 2; i >= 0; --i) {
      dp[i] = jobs[i].profit;
      int next_index = lower_bound(jobs.cbegin(), jobs.cend(), jobs[i].end_time,
                                   [](const Job& element, const int value) {
                                     return element.start_time < value;
                                   }) -
                       jobs.cbegin();
      if (next_index != n) {
        dp[i] += dp[next_index];
      }
      dp[i] = max(dp[i], dp[i + 1]);
    }
    return dp.front();
  }

 private:
  struct Job {
    int start_time;
    int end_time;
    int profit;

    bool operator<(const Job& j) const {
      if (start_time != j.start_time) {
        return start_time < j.start_time;
      }
      if (end_time != j.end_time) {
        return end_time < j.end_time;
      }
      return profit < j.profit;
    }
  };
};
