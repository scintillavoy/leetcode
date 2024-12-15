#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  double maxAverageRatio(vector<vector<int>> &classes, int extraStudents) {
    auto comp = [](const pair<int, int> &a, const pair<int, int> &b) {
      return (double)(a.first + 1) / (a.second + 1) -
                 (double)a.first / a.second <
             (double)(b.first + 1) / (b.second + 1) -
                 (double)b.first / b.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq;
    for (int i = 0; i < classes.size(); ++i) {
      pq.push({classes[i][0], classes[i][1]});
    }
    for (int i = 0; i < extraStudents; ++i) {
      auto t = pq.top();
      pq.pop();
      pq.push({t.first + 1, t.second + 1});
    }
    double max_average_ratio = 0.0;
    while (!pq.empty()) {
      auto t = pq.top();
      pq.pop();
      max_average_ratio += (double)t.first / t.second;
    }
    max_average_ratio /= classes.size();
    return max_average_ratio;
  }
};
