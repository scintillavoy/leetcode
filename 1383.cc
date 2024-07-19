#include <algorithm>
#include <functional>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

#define MOD 1'000'000'007

class Solution {
 public:
  int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency,
                     int k) {
    vector<int> indices(n);
    for (int i = 0; i < n; ++i) {
      indices[i] = i;
    }
    sort(indices.begin(), indices.end(), [&](const int a, const int b) {
      return efficiency[a] > efficiency[b];
    });
    long long sum = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    long long max_performance = numeric_limits<long long>::min();
    for (int i = 0; i < n; ++i) {
      if (pq.size() == k) {
        sum -= pq.top();
        pq.pop();
      }
      sum += speed[indices[i]];
      pq.push(speed[indices[i]]);
      max_performance = max(max_performance, sum * efficiency[indices[i]]);
    }
    return max_performance % MOD;
  }
};
