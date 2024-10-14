#include <cmath>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  long long maxKelements(vector<int>& nums, int k) {
    priority_queue<int> pq;
    for (const auto num : nums) {
      pq.push(num);
    }
    long long score = 0;
    while (k--) {
      int max_num = pq.top();
      pq.pop();
      pq.push(ceil(max_num / 3.0));
      score += max_num;
    }
    return score;
  }
};
