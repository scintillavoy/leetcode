#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  int minOperations(vector<int>& nums, int k) {
    int num_of_operations = 0;
    priority_queue<long long, vector<long long>, greater<long long>> pq(
        nums.begin(), nums.end());
    while (pq.size() >= 2 && pq.top() < k) {
      long long x = pq.top();
      pq.pop();
      long long y = pq.top();
      pq.pop();
      pq.push(min(x, y) * 2 + max(x, y));
      ++num_of_operations;
    }
    return num_of_operations;
  }
};
