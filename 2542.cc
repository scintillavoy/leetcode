#include <algorithm>
#include <functional>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
    int n = nums1.size();
    vector<int> indices(n);
    for (int i = 0; i < n; ++i) {
      indices[i] = i;
    }
    sort(indices.begin(), indices.end(),
         [&](const int a, const int b) { return nums2[a] > nums2[b]; });
    priority_queue<int, vector<int>, greater<int>> pq;
    long long max_score = numeric_limits<long long>::min();
    int i = 0;
    long long sum = 0;
    while (i < n) {
      while (pq.size() < k) {
        pq.push(nums1[indices[i]]);
        sum += nums1[indices[i]];
        ++i;
      }
      max_score = max(max_score, sum * nums2[indices[i - 1]]);
      sum -= pq.top();
      pq.pop();
    }
    return max_score;
  }
};
