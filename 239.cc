#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int start = 0, end = k;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < end; ++i) {
      pq.push({nums[i], i});
    }
    vector<int> answer;
    answer.push_back(pq.top().first);
    while (end < nums.size()) {
      ++start;
      while (!pq.empty() && pq.top().second < start) {
        pq.pop();
      }
      pq.push({nums[end], end});
      ++end;
      answer.push_back(pq.top().first);
    }
    return answer;
  }
};
